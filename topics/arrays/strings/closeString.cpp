#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

bool closeString(string word1, string word2) {
  std::array<int, 26> map1 = {}, map2 = {};
  for (char c : word1)
    ++map1[c - 'a'];
  for (char c : word2)
    ++map2[c - 'a'];

  for (int i = 0; i < 26; ++i) {
    bool c1 = map1[i] > 0;
    bool c2 = map2[i] > 0;
    if ((c1 && !c2) || (!c1 && c2))
      return false;
  }

  std::sort(map1.begin(), map1.end());
  std::sort(map2.begin(), map2.end());

  for (int i = 0; i < 26; ++i) {
    if (map1[i] != map2[i])
      return false;
  }
  return true;
}

int main() {
  string word1 = "a", word2 = "aa";
  bool result = closeString(word1, word2);
  cout << result << endl;
  return 0;
}
