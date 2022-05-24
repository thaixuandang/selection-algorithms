#ifndef NAIVE_H
#define NAIVE_H

#include <algorithm>

namespace Naive {
  template<typename T>
  T select(T a[], int n, int k) {
    std::sort(a, a + n);
    return a[k - 1];
  }
}

#endif
