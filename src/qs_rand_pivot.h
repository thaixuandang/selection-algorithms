#ifndef QS_RAND_PIVOT_H
#define QS_RAND_PIVOT_H

#include <algorithm>
#include <random>
#include <chrono>

namespace QuicksortRandomPivot {
  // random number generator for choosing pivots
  std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

  template<typename T>
  void quicksort(T a[], int n) {
    if (n <= 1) {
      return;
    }
    T pivot = a[rng() % n];
    int i = 0, j = n - 1;
    do {
      while (a[i] < pivot) {
        i++;
      }
      while (a[j] > pivot) {
        j--;
      }
      if (i <= j) {
        std::swap(a[i++], a[j--]);
      }
    } while (i <= j);
    quicksort(a, j + 1);
    quicksort(a + i, n - i);
  }
}

#endif