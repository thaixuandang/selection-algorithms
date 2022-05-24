/* Benchmark for 4 selection algorithms:
 * * Naive
 * * Selection sort
 * * Quickselect
 * * Median of medians
 */

#include <cstdio>
#include <random>
#include <algorithm>
#include <cassert>
#include "naive.h"
#include "selection_sort.h"
#include "quickselect.h"
#include "median_of_medians.h"


const int num_test = 12;
const int num_algo = 4;
const int max_size = 10000000;

const int sizes[] = {
    50,
    100,
    500,
    1000,
    5000,
    10000,
    50000,
    100000,
    500000,
    1000000,
    5000000,
    10000000};

int (*const algorithms[])(int*, int, int) = {
    Naive::select<int>,
    SelectionSort::select<int>,
    Quickselect::select<int>,
    MedianOfMedians::select<int>};

const char* algo_names[] = {
    "Naive",
    "Selection sort",
    "Quickselect",
    "Median of Medians"};


// random number generator
std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
int a[max_size];

int test(int (*algo)(int*, int, int), int size, int k, const char* algo_name) {
  time_t start = clock();
  int res = algo(a, size, k);
  time_t end = clock();
  int runtime = (end - start) / (CLOCKS_PER_SEC / 1000);

  printf(",%d", runtime);
  fprintf(stderr, "Running %17s in %7d milliseconds.\n", algo_name, runtime);
  
  return res;
}

int main() {
  printf("Size");
  for (int i = 0; i < num_algo; ++i) {
    printf(",%s", algo_names[i]);
  }

  for (int i = 0; i < num_test; ++i) {
    int size = sizes[i];
    
    // generate data and order query
    std::generate(a, a + size, rng);
    int k = rng() % size + 1;

    printf("%d", size);
    fprintf(stderr, "Size: %d, order: %d\n", size, k);

    int answers[num_algo];
    for (int i = 0; i < num_algo; ++i) {
      answers[i] = test(algorithms[i], size, k, algo_names[i]);
    }

    putchar('\n');
    fprintf(stderr, "\n");

    std::sort(answers, answers + num_algo);
    assert(answers[0] == answers[num_algo - 1]);
  }
  return 0;
}
