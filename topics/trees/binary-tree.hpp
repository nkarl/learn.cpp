#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <vector>

struct Node {
  int val;
  Node *left, *right;

  Node(int val) : val(val) {}
  Node(int val, Node *left, Node *right) : val(val), left(left), right(right) {}
};

Node *make_root(int val);
Node *make_tree(std::vector<int> values);

#endif
