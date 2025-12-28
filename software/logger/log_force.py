import argparse, os, time
from datetime import datetime, timezone
import serial

def iso_now():
    return datetime.now(timezone.utc).isoformat()

def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--port", required=True, help="COM5 or /dev/ttyACM0")
    ap.add_argument("--baud", type=int, default=115200)
    ap.add_argument("--out", required=True, help=r"e.g. data\runs\run_001")
    ap.add_argument("--seconds", type=float, default=10.0)
    args = ap.parse_args()

    os.makedirs(args.out, exist_ok=True)
    out_csv = os.path.join(args.out, "force_timeseries.csv")

    with serial.Serial(args.port, args.baud, timeout=1) as ser, open(out_csv, "w", newline="") as f:
        f.write("timestamp_iso,ts_ms,raw,force_N\n")
        start = time.time()
        while time.time() - start < args.seconds:
            line = ser.readline().decode(errors="ignore").strip()
            if not line or line.startswith("ts_ms"):
                continue
            parts = line.split(",")
            if len(parts) != 3:
                continue
            ts_ms, raw, forceN = parts
            f.write(f"{iso_now()},{ts_ms},{raw},{forceN}\n")

    print(f"Wrote {out_csv}")

if __name__ == "__main__":
    main()
