#include <iostream>
#include <sstream>
#include <vector>

using i8 = char;
using namespace std;

auto tokenize(i8 const *path, vector<string> &vec) -> void {
  stringstream ss(path);
  string token;
  while (getline(ss, token, '/')) {
    vec.push_back(token);
  }
}

int main() {
  const i8 *path = "/a/b/c/d";

  vector<string> vec;
  tokenize(path, vec);
  for (auto t : vec) {
    cout << t << ' ';
  }
}
