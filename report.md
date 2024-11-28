## 1-1

**Fill in the blanks in the following table using the information you gathered about the cache configuration of the lab machine.**

| Cache | Cache Line Size | Total Size | Associativity | Number of Sets | Raw Latency |
| ----- | --------------- | ---------- | ------------- | -------------- | ----------- |
| L1-D  | 64              | 131072     | 8             | 64             | 4 cycles    |
| L2    | 64              | 1048576    | 4             | 1024           | 12 cycles   |
| L3    | 64              | 8388608    | 16            | 8192           | 42 cycles   |

## 1-3

**After completing your code, generate the histogram pdf file and include it in the lab report.**

<!-- ![Histogram](./Part1-Timing/Histogram.pdf) -->

## 1-4

**Based on the generated histogram, report two thresholds, one to distinguish between L2 and L3 latency and the other to distinguish between L3 and DRAM latency.**

L2-L3 threshold: 40

L3-DRAM threshold: 100

## 2-2

**In the victim's pseudocode above, the victim attempts to load the data indexed by `flag` into the `value` variable. How can you change the victim's code to load the desired data without leaking the flag to the attacker?**
Load the entire data with flag 0~1023, and only retain data with the specific flag.
