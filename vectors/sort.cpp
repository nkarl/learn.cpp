#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<vector<int>> trips = {
      {2, 1, 5},
      {3, 3, 7},
  };

  std::sort(trips.begin(), trips.end(),
      [](vector<int> a, vector<int> b) {
        return a[1] < b[1];
      });

  for (auto t : trips) {
    printf("%d %d %d, ", t[0], t[1], t[2]);
  }
}
