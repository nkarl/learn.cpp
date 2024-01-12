#include <iostream>

using std::cout;
using std::endl;

using i8 = char;
using u32 = int;

int main() {
  // 32-bit
  // dec: 1836087179
  //reversed bitstring: "1101000111101110000011101011011b0";
  i8 const *buf =
      "001001111100100011001011010101000000010100010101000100101110011000111110"
      "010001011010010001000010000000111000111001001101101011";

  u32 BIT = 74;
  u32 ibyte = 74 / 8;
  u32 jbit = BIT % 8;

  auto TST = buf[ibyte] & (1 << jbit);

  cout << TST << endl;
  cout << buf[BIT] << endl;

  cout << ((u32)1 << 31) << endl;
  cout << ((u32)1 << 32) << endl;

  cout << 0xff << endl;
}
