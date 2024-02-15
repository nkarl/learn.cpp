#include <functional>
#include <iostream>

using namespace std;

struct Data {
  int value;
  string op_name;
  function<int(int)> op_on_value;
};

inline int add_2(int value) { return value + 2; }

int main() {
  Data a;
  a.value = 1;
  a.op_on_value = &add_2, a.op_name = "add 2";
}
