#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int val;
  Node *left, *right, *next;
};

void print(Node *node) { printf("%d ", node->val); }

void cache_tree(Node *node, vector<Node *> &cache) {
  if (!node->left && !node->right) {
    cache.push_back(node);
    return;
  }
  cache.push_back(node);
  cache_tree(node->left, cache);
  cache_tree(node->right, cache);
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

  vector<Node *> cache;
  cache_tree(&root, cache);

  for (auto n : cache) {
    printf("%d ", n->val);
  }
  cout << endl;

  // [ 0 1 2 3 4 5 6 ]
  // [   1     2     ]
  // [   2 4 5 3 6 7 ]

  //cout << "8 >> 1: " << (8 >> 1) << endl;
  //cout << "4 >> 1: " << (4 >> 1) << endl;

  //cout << "1 << 1: " << (1 << 1) << endl;
  //cout << "1 << 2: " << (1 << 2) << endl;

  //for (auto i = 1; i < cache.size(); ++i) {
    //auto j = 1 << i;
    //for (auto k = i; k <= j - i + 1; ++k) {
      ////cout << i << ' ' << k <<  ' ' << j << endl;
      //cout << k << ':' << cache[k]->val << ' ';
      ////cout << cache[k]->val << " ";
    //}
    //i = j;
    //cout << endl;
  //}
}
