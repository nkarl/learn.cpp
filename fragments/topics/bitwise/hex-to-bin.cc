#include <iostream>
#include <map>
#include <stdio.h>

using std::cout;
using std::endl;
using std::string;

using u8 = char;
using u32 = unsigned int;

std::map<u8, string> dict = {
    {'0', "0000"}, {'1', "1000"}, {'2', "0100"}, {'3', "1100"}, {'4', "0010"},
    {'5', "1010"}, {'6', "0110"}, {'7', "1110"}, {'8', "0001"}, {'9', "1001"},
    {'A', "0101"}, {'B', "1101"}, {'C', "0011"}, {'D', "1011"}, {'E', "0111"},
    {'F', "1111"}, {'a', "0101"}, {'b', "1101"}, {'c', "0011"}, {'d', "1011"},
    {'e', "0111"}, {'f', "1111"},
};

int main() {
  const u8 *bitstring = "11111111";
  u8 buffer[9] = {0};

  for (u32 i = 0; i < 8; ++i) {
    cout << bitstring[i];
  }
  cout << endl;
  printf("%x", 0xff / 0xf);
}
