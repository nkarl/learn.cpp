#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vec = {1, 2, 3};

  // vector<int>::iterator it = vec.begin();
  auto it = vec.begin() + 1;
  for (auto i = it; i != vec.end(); ++i) {
    cout << *i << ' ';
  }
}
