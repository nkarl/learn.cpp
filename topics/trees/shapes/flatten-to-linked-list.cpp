#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int val;
  Node *left, *right;

  Node(int val) : val(val) {}
  Node(int val, Node *left, Node *right) : val(val), left(left), right(right) {}
};

Node *flatten(Node *node) {
  if (!node)
    return node;

  auto left = flatten(node->left);
  auto right = flatten(node->right);

  if (!left && !right) {
  } else if (!left && right) {
  } else if (!right && left) {
    node->right = left;
    node->left = nullptr;
  } else if (left && right) {
    node->right = left;
    auto ptr = left;
    while (ptr->right) {
      ptr = ptr->right;
    }
    ptr->right = right;
    node->left = nullptr;
  }

  return node;
}

int main() {
  Node root = {1, nullptr, nullptr};
  root.left = new Node {2, nullptr, nullptr};
  root.right = new Node {5, nullptr, nullptr};
  root.left->left = new Node {3, nullptr, nullptr};
  root.left->right = new Node {4, nullptr, nullptr};
  root.right->right = new Node {6, nullptr, nullptr};

  auto n = flatten(&root);
}
