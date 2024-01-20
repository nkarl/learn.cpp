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

  /*
   * NOTE:
   *  - `int const *`   means a       pointer to a piece of data that is immutable (read-only).
   *  - `int * const`   means a const pointer to a piece of data that is   mutable.
   *    - data of this case needs to be allocated on the stack.
   */
  struct Trip {
    int const *load, *start, *end;
  };

  // vector<Trip> ts = {{2, 1, 5}, {3, 3, 7}};
   vector<Trip> ts(std::size(trips)); // works
  //vector<Trip> ts; // works
  for (auto i = 0; i < trips.size(); ++i) {
    /*
     * auto trip = trips[i];
     * ts[i] = {&trip[0], &trip[1], &trip[2]}; // won't work because `trip` goes out of scope at the end of the for loop.
     *                                         // this is because `trip` itself is an interator and a *pointer* to the actual reference.
     */
    /*// heap-allocation
     * auto *trip = new Trip({&trips[i][0], &trips[i][1], &trips[i][2]}); // works
     * ts[i] = *trip;                                                     // works
     */
    ts[i] = {&trips[i][0], &trips[i][1], &trips[i][2]};       // works
    ts.push_back({&trips[i][0], &trips[i][1], &trips[i][2]}); // works
  }

  //std::sort(ts.begin(), ts.end(),
            //[](Trip a, Trip b) { return a.start < b.end && a.end < b.end; });
  for (auto &[load, start, end] : ts) {
    printf("%d %d %d, ", *load, *start, *end);
    //*load += 1; // illegal, won't compile.
  }
  cout << endl;
}
