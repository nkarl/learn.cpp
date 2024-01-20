#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<vector<int>> trips = {
      {2, 1, 5},
      {3, 3, 7},
  };

  std::sort(trips.begin(), trips.end());
  // std::sort(trips.begin(), trips.end(),
  //[](vector<int> a, vector<int> b) {
  // return a[1] < b[1];
  //});

  for (auto t : trips) {
    printf("%d %d %d, ", t[0], t[1], t[2]);
  }
  cout << endl;

  struct Trip {
    int load, start, end;
    // NOTE: Rust allows pointers/references to an int data type.
    // This doesn't seem to be possible in C++. Pointers seem to be deleted.
    // Could be because primitives such as int are faster to copy because it's easier to shuffled them around in the registers.
  };

  // vector<Trip> ts = {{2, 1, 5}, {3, 3, 7}};
  vector<Trip> ts(std::size(trips));
  for (auto i = 0; i < trips.size(); ++i) {
    auto trip = trips[i];
    ts[i] = {trip[0], trip[1], trip[2]};
  }

  std::sort(ts.begin(), ts.end(),
            [](Trip a, Trip b) { return a.start < b.end && a.end < b.end; });
  for (auto &[load, start, end] : ts) {
    printf("%d %d %d, ", load, start, end);
  }
  cout << endl;
}
