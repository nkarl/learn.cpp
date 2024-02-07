#include <algorithm>
#include <iostream>
using namespace std;

string mergeStrings2(string &w1, string &w2) {
  const std::function<string(int, int)> merge = [&](int i, int end) -> string {
    if (i == end)
      return "";
    return string(1, w1[i]) + string(1, w2[i]) + merge(i + 1, end);
  };

  auto shorter = min(w1.length(), w2.length());
  string result = merge(0, shorter);
  return result +=
         (w1.length() > w2.length()) ? w1.substr(shorter) : w2.substr(shorter);
}

string mergeStrings(string w1, string w2) {
  int shorter = min(w1.length(), w2.length());
  string result = "";
  for (auto i = 0; i < shorter; ++i) {
    result = result + w1[i] + w2[i];
  }
  return result +=
         (w1.length() > w2.length()) ? w1.substr(shorter) : w2.substr(shorter);
}

int main() {
  string w1 = "abc";
  string w2 = "pqrx";

  auto r1 = mergeStrings(w1, w2);
  cout << r1 << endl;
  auto r2 = mergeStrings2(w1, w2);
  cout << r2 << endl;
}
