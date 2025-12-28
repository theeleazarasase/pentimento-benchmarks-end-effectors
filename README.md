# Pentimento Benchmarks: End Effectors

A print-first benchmark + dataset for modular end-effectors focused on **repeatability**, **force/hold metrics**, and later **planning-aware design**.

This repository is part of **Pentimento Benchmarks** — the measurement backbone that will later support the future **Pentimento** robotic platform.

## Module 1 status
- [ ] Rig built (NOYITO 20kg load cell + HX711)
- [ ] Calibration complete (counts ? N)
- [ ] Logging pipeline produces trials.csv + raw timeseries
- [ ] 50+ trials recorded

## Repo layout
- `docs/` protocols + dataset documentation
- `hardware/` rig BOM, wiring, photos
- `firmware/` MCU code (Uno/ESP32)
- `software/` PC tools for logging + analysis
- `data/` dataset templates + examples
- `cad/` printable fixtures/mounts
