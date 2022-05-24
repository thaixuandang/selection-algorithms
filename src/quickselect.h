#ifndef QUICKSELECT_H
#define QUICKSELECT_H

#include <algorithm>
#include <random>
#include <chrono>

namespace Quickselect {
  // random number generator for choosing pivots
  std::mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());

  template<typename T>
  T select(T a[], int n, int k) {
    if (n <= 1) {
      return a[0];
    }
    
    int pivot = a[rng() % n];
    int i = 0, j = n - 1;
    do {
      while (a[i] < pivot) {
        i++;
      }
      while (a[j] > pivot) {
        j--;
      }
      
      // at this time, a[i] >= pivot >= a[j]
      if (i <= j) {
        std::swap(a[i++], a[j--]);
      }
    } while (i <= j);

    if (k <= j + 1) {
      return select(a, j + 1, k);
    }

    if (k <= i) {
      return pivot;
    }
    
    // k > i
    return select(a + i, n - i, k - i);
  }
}

#endif
