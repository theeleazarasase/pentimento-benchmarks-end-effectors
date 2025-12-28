# Calibration (HX711 + Load Cell)

## Goal
Convert HX711 raw counts to Newtons.

## Procedure
1) Warm up for 10–20 seconds.
2) Tare: record `raw_zero` with no load.
3) Apply known mass `m_kg` (hang weight from hook).
4) Compute force: `F_N = m_kg * 9.80665`.
5) Record `raw_mass`.
6) Scale: `scale_counts_per_N = (raw_mass - raw_zero) / F_N`.
7) Validate with a second mass and record error.

## Store
Save calibration in `data/trial_metadata.json`:
- raw_zero
- scale_counts_per_N
- calibrated_at_iso
