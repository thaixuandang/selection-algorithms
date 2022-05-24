#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#include <algorithm>

namespace SelectionSort {
  template<typename T>
  T select(T a[], int n, int k) {
    for (int i = 0; i < k; ++i) {
      int jmin = i;
      for (int j = i + 1; j < n; ++j) {
        if (a[j] < a[jmin]) {
          jmin = j;
        }
      }
      std::swap(a[i], a[jmin]);
    }
    return a[k - 1];
  }
}

#endif
