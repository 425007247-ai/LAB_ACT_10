# Hand Trace of Search Algorithms

The required hand trace uses the key at index 11: **120022**.

Sorted vector:

`120000, 120002, 120004, 120006, 120008, 120010, 120012, 120014, 120016, 120018, 120020, 120022`

## 1. Linear Search

Linear Search checks from index 0 until it reaches the target.

| Probe | Index | Key examined | Result |
| ----: | ----: | ----: | :---- |
| 1 | 0 | 120000 | Not equal |
| 2 | 1 | 120002 | Not equal |
| 3 | 2 | 120004 | Not equal |
| 4 | 3 | 120006 | Not equal |
| 5 | 4 | 120008 | Not equal |
| 6 | 5 | 120010 | Not equal |
| 7 | 6 | 120012 | Not equal |
| 8 | 7 | 120014 | Not equal |
| 9 | 8 | 120016 | Not equal |
| 10 | 9 | 120018 | Not equal |
| 11 | 10 | 120020 | Not equal |
| 12 | 11 | 120022 | Found |

**Result:** Index 11, with **12 probes**.

## 2. Binary Search

Midpoint formula: `mid = low + (high - low) / 2`

| Probe | Low | High | Mid | Key at mid | Decision |
| ----: | ----: | ----: | ----: | ----: | :---- |
| 1 | 0 | 11 | 5 | 120010 | Target is larger; set low = 6 |
| 2 | 6 | 11 | 8 | 120016 | Target is larger; set low = 9 |
| 3 | 9 | 11 | 10 | 120020 | Target is larger; set low = 11 |
| 4 | 11 | 11 | 11 | 120022 | Found |

**Result:** Index 11, with **4 probes**.

## Comparison

For this target, Linear Search examines 12 elements while Binary Search examines 4 elements. Binary Search uses fewer probes because it reduces the remaining search range at every step.
