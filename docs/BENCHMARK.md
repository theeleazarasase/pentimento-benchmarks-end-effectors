# BENCHMARK: Module 1 (Pull-to-slip)

## Goal
Measure **slip onset force** and basic repeatability for end-effector contact designs.

## Primary test: Pull-to-slip
**Setup**
- Object is held by the end-effector OR placed on a sled/fixture that the end-effector restrains.
- Pull line attaches to the object/sled and routes to the load cell hook point.

**Action**
- Apply a steady pull until the first clear slip event occurs.

**Record**
- `peak_force_N` = maximum force before slip onset
- Raw timeseries (`timestamp_iso, ts_ms, raw, force_N`)

## Repeatability protocol
- N = 10 trials per object/config.
- Reset object pose between trials using the same procedure.

## Standardization rules
- Use the same pull direction and attachment point per object.
- Use a swivel in the pull chain to avoid torque.
- Keep pull rate “slow and steady” (or use a weight/pulley later).

## Outputs
- Raw CSV per trial
- `trials.csv` row per trial (summary)
