#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int val;
  Node *left, *right, *next;
};

void print(Node *node) { printf("%d ", node->val); }

void order_pre(Node *node) {
  if (!node)
    return;
  print(node);
  order_pre(node->left);
  order_pre(node->right);
}

void order_in(Node *node) {
  if (!node)
    return;
  order_in(node->left);
  print(node);
  order_in(node->right);
}

void order_post(Node *node) {
  if (!node)
    return;
  order_post(node->left);
  order_post(node->right);
  print(node);
}

Node *connect_level(Node *node) {
  if (!node)
    return node;
  if (node->left) {
    node->left->next = node->right;
    if (node->next) {
      node->right->next = node->next->left;
    }
  }
  return connect_level(node->next);
}

Node *connect(Node *root) {
  if (!root)
    return root;

  connect_level(root);
  auto _ = connect(root->left);
  return root;
}

void print_level(Node *node) {
  if (!node)
    return;
  printf("%d ", node->val);
  print_level(node->next);
}

void print_tree(Node *root) {
  if (!root)
    return;
  print_level(root); cout << endl;
  print_tree(root->left);
}

int main() {
  vector<Node> vec = {{1, nullptr, nullptr}, {2, nullptr, nullptr},
                      {3, nullptr, nullptr}, {4, nullptr, nullptr},
                      {5, nullptr, nullptr}, {6, nullptr, nullptr},
                      {7, nullptr, nullptr}};

  Node root = vec[0];
  root.left = &vec[1], root.right = &vec[2];
  root.left->left = &vec[3], root.left->right = &vec[4];
  root.right->left = &vec[5], root.right->right = &vec[6];

  order_pre(&root);
  cout << endl;
  order_in(&root);
  cout << endl;
  order_post(&root);
  cout << endl;
  cout << endl;

  connect(&root);
  print_tree(&root);
}
