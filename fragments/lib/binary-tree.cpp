#include "../hdr/binary-tree.hpp"

using namespace std;

Node *build_tree_from_preorder(vector<int> &inorder, vector<int> &preorder) {
  int root = 0;
  std::map<int, int> mp;
  auto i = 0;
  for (auto e : inorder) mp[e] = i++;

  const std::function<Node *(int, int)> build = [&]
  (int left, int right) -> Node * {
    if (left > right) return nullptr;

    Node *node = new Node(preorder[root]);
    auto r = mp[preorder[root]];/* 0;
    for (; inorder[r] != preorder[root]; ++r);*/
    ++root;

    node->left = build(left, r - 1);
    node->right = build(r + 1, right);
    return node;
  };

  return build(0, preorder.size() - 1);
}

Node *build_tree_from_postorder(std::vector<int> &inorder, std::vector<int> &postorder) {
  int root = postorder.size() - 1;
  std::map<int, int> mp;
  auto i = 0;
  for (auto e : inorder) mp[e] = i++;

  const std::function<Node *(int, int)> build = [&]
  (int left, int right) -> Node * {
    if (left > right) return nullptr;

    Node *node = new Node(postorder[root]);
    auto r = mp[postorder[root]];/*0;
    for (; inorder[r] != postorder[root]; ++r);*/
    --root;

    node->right = build(r + 1, right);
    node->left = build(left, r - 1);
    return node;
  };

  return build(0, postorder.size() - 1);
}

bool compare(Node *r1, Node *r2) {
  if (!r1 && !r2)
    return true;
  if ((!r1 && r2) || (r1 && !r2))
    return false;
  if (r1->val != r2->val)
    return false;
  auto res1 = compare(r1->left, r2->left);
  auto res2 = compare(r1->right, r2->right);
  return res1 && res2;
}

void print_tree(Node *root, int order) {
  switch (order) {
  case PREORDER: print_preorder(root); break;
  case INORDER: print_inorder(root); break;
  case POSTORDER: print_postorder(root); break;
  }
}

void print_preorder(Node *root) {
  if (!root)
    return;
  cout << root->val << ' ';
  print_preorder(root->left);
  print_preorder(root->right);
}

void print_inorder(Node *root) {
  if (!root)
    return;
  print_inorder(root->left);
  cout << root->val << ' ';
  print_inorder(root->right);
}

void print_postorder(Node *root) {
  if (!root)
    return;
  print_postorder(root->left);
  print_postorder(root->right);
  cout << root->val << ' ';
}
