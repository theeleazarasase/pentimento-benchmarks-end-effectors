# Dataset

This repo standardizes end-effector benchmark data.

## Files
- `data/objects.csv` — object catalog + properties
- `data/trial_metadata.json` — rig + calibration + environment
- `data/trials.csv` — one row per trial (summary metrics)
- Per-trial raw timeseries CSV (stored locally; not committed by default)

## Intended use
Reusable across many end-effector designs and later integration into the Pentimento platform.
