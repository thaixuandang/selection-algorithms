#ifndef QS_MEDIAN_PIVOT_H
#define QS_MEDIAN_PIVOT_H

#include <algorithm>
#include "median_of_medians.h"

namespace QuicksortMedianPivot {
  template<typename T>
  void quicksort(T a[], int n) {
    if (n <= 1) {
      return;
    }
    T pivot = MedianOfMedians::select(a, n, n / 2);
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