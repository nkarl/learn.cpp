#include "binary-tree.hpp"

Node *make_root(int val) {
  auto root = new Node(val, nullptr, nullptr);
  return root;
}

Node *make_tree(std::vector<int> values) {
  auto root = make_root(values[0]);
  for (auto i = 1; i < values.size(); i += 2) {
    /*
     * TODO: implement the algorithm to 
     */
  }
  return root;
}

