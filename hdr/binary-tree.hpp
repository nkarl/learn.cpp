#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <functional>
#include <iostream>
#include <vector>

struct Node {
  int val = 0;
  Node *left = nullptr, *right = nullptr;

  Node(int val) : val(val) {}
  Node(int val, Node *left, Node *right) : val(val), left(left), right(right) {}
};

Node *build_tree_from_preorder(std::vector<int> &inorder, std::vector<int> &preorder);
Node *build_tree_from_postorder(std::vector<int> &inorder, std::vector<int> &postorder);

enum ORDER { INORDER = 0, PREORDER, POSTORDER };

void print_tree(Node *root, int order);
void print_preorder(Node *root);
void print_inorder(Node *root);
void print_postorder(Node *root);

#endif
