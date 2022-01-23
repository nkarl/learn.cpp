#include <iostream>

using namespace std;

template<class T>
class Node {
  private:
  public:
    T        Key;
    Node<T> *Less = nullptr;
    Node<T> *More = nullptr;

    Node<T>(T k) { Key = k; }
    Node<T>(Node<T> &node) { Key = node.Key; }
};

template<class T>
class BST {
  private:
    Node<T> *insert(int k, Node<T> *parent) {
        if (parent == nullptr) return new Node<T>(k);

        if (k < parent->Key)
            parent->Less = insert(k, parent->Less);
        else if (parent->Key < k)
            parent->More = insert(k, parent->More);

        return parent;
    }

    void print(Node<T> *parent) {
      if (parent == nullptr) return;

      cout << parent->Key << " ";
      print(parent->Less);
      print(parent->More);
    }

  public:
    Node<T> *_root = nullptr;

    BST(Node<T> &node) { _root = new Node<T>(node); };

    void insert(int k) {
      insert(k, _root);
    }

    void print() {
      print(_root);
    }
};

int main(int argc, char *argv[], char *env[]) {
    Node<int> a(3);

    cout << a.Key << endl;

    BST<int> tree(a);

    tree.insert(0);
    tree.insert(2);
    tree.insert(7);
    tree.insert(4);

    tree.print();
    
    return 0;
}
