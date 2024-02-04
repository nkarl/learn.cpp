#include "../../../hdr/binary-tree.hpp"
#include <iostream>

using namespace std;

void print(Node *root) {
  cout << "preorder  " ; print_tree(root, PREORDER)  ; cout << endl ;
  cout << "inorder   " ; print_tree(root, INORDER)   ; cout << endl ;
  cout << "postorder " ; print_tree(root, POSTORDER) ; cout << endl ;
}

int main() {
  const std::function<void (vector<int>&)> p = [&](vector<int> &v) {
    for (auto e : v) cout << e << ' ';
    cout << endl;
  };
  vector<int> preorder = {3, 9, 20, 15, 7}; cout << "pre :"; p(preorder);
  vector<int> inorder = {9, 3, 15, 20, 7};  cout << "in  :"; p(inorder);
  vector<int> postorder = {9, 15, 7, 20, 3}; cout << "post:"; p(postorder);

  Node *root_preorder = build_tree_from_preorder(inorder, preorder);
  Node *root_postorder = build_tree_from_postorder(inorder, postorder);

  auto result = compare(root_preorder, root_postorder);
  cout << "same trees:" << (result ? "true" : "false")  << endl;
  print(root_preorder);
}
