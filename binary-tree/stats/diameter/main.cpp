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

/**
 * NOTE: in order to understand how this works, useful to have these two things:
 *  1. an image of the stacktrace.
 *  2. induction proof.
 *
 * NOTE: INDUCTION PROOF
 *  - hypothesis: every tree node has a diameter and a longer branch between its left and right childs.
 *  - proof:
 *    - leaf nodes are trivial, { d: 0, l: 0 }
 *    - for every tree node,
 *      - Its diameter is the sum of its left child's longest and right child's longest.
 *      - Its longest branch is either left or right.
 *      - If its diameter is more than the diameter of its left or right child, then including itself,
 *        - its longest has to be larger than the depth of its either childs.
 *        - in other words, its diameter and longest are maximal so far.
 *      - Once the stacktrace pops back at the root node, the diameter and longest are maximal.
 */
TreeStats find_tree_diameter(Node *node) {
  if (!node)
    return {0, 0};

  auto left   = find_tree_diameter(node->left);
  auto right  = find_tree_diameter(node->right);

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
