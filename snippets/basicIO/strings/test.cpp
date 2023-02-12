#include <iostream>

using std::string;
using std::cout; using std::endl;

int main(int argc, char *argv[]) {
    string str0 = "aabbcc";
    string str1 = "aa";
    string str2 = "ab";

    cout << (str0.find(str1) == 0 ? "True" : "False") << endl;
    cout << (str0.find(str2) == 1 ? "True" : "False") << endl;
    return 0;
}
