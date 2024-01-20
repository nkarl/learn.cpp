#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int val;
  Node *left, *right;
};

struct TreeStats {
  int diameter, longest;
};

TreeStats find_tree_diameter(Node *node) {
  if (!node)
    return {0, 0};
  auto left = find_tree_diameter(node->left);
  auto right = find_tree_diameter(node->right);

  auto node_d = left.longest + right.longest;
  return {std::max(node_d, std::max(left.diameter, right.diameter)),
          1 + std::max(left.longest, right.longest)};
}

int binaryTreeDiameter(Node *root) { return find_tree_diameter(root).diameter; }

int main() {
  Node root = {1, nullptr, nullptr};
  vector<Node> vec = {
      {2, nullptr, nullptr}, {3, nullptr, nullptr}, {4, nullptr, nullptr}};
  root.left = &vec[0], root.right = &vec[1];
  root.left->left = &vec[2];

  auto d = binaryTreeDiameter(&root);
  cout << d << endl;
}
