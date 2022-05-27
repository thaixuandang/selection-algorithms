#ifndef MEDIAN_OF_MEDIANS_H
#define MEDIAN_OF_MEDIANS_H

#include <algorithm>

namespace MedianOfMedians {
  template<typename T>
  void sort(T a[], int n) {
#ifdef FAST
    std::sort(a, a + n);
#else
    // insertion sort
    for (int i = 1; i < n; ++i) {
      T x = a[i];
      int j = i - 1;
      while (j >= 0 && a[j] > x) {
        a[j + 1] = a[j];
        j--;
      }
      a[j + 1] = x;
    }
#endif
  }

  template<typename T>
  T select(T a[], int n, int k) {
    if (n <= 50) {
      sort(a, n);
      return a[k - 1];
    }

    int groups = 0;
    for (int i = 0; i + 5 <= n; i += 5) {
      sort(a + i, 5);
      std::swap(a[groups++], a[i + 2]);
    }

    T pivot = select(a, groups, groups / 2);
    int count_less = 0, count_equal = 0;
    for (int i = 0; i < n; ++i)
      if (a[i] < pivot) {
        count_less++;
      } else if (a[i] == pivot) {
        count_equal++;
      }

    if (count_less < k && k <= count_less + count_equal) {
      return pivot;
    }

    int j = 0;
    if (k <= count_less) {
      for (int i = 0; i < n; ++i) {
        if (a[i] < pivot) {
          std::swap(a[j++], a[i]);
        }
      }
      return select(a, j, k);
    }

    // k > count_less + count_equal
    for (int i = 0; i < n; ++i) {
      if (a[i] > pivot) {
        std::swap(a[j++], a[i]);
      }
    }
    return select(a, j, k - count_less - count_equal);
  }
}

#endif
