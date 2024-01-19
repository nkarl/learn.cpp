#include <iostream>

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int main() {
  auto res = gcd(6, 3);
  std::cout << res;
}
