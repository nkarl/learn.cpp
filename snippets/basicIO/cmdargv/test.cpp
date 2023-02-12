#include <iostream>

using std::cout; using std::endl;

struct ArrayReader {
    char **argv;
    int argc;

    ArrayReader(int argc, char *argv[]) {
        this->argv = argv;
        this->argc = argc;
    }

    void read() {
        for (int i=0; i<argc; ++i) {
            auto element = argv[i];
            cout << "argv[" << i << "]: " << element << endl;
        }
    }
};

int main(int argc, char *argv[]) {
    ArrayReader reader(argc, argv);
    reader.read();
    return 0;
}
