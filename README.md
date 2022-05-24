# Selection algorithms
Implement and benchmark selection algorithms.

## Benchmark
Compile and run benchmark:
```bash
g++ src/*.cpp -O2 -o build/benchmark && build/benchmark > results.csv
```
or make the median of medians algorithm faster with:
```bash
g++ src/*.cpp -O2 -o build/benchmark && build/benchmark > results.csv -DFAST
```

## Results
See in `results.csv`.
