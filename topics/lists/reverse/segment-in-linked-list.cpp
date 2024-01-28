#include <iostream>
#include <vector>

using std::vector;

struct Node {
  int          value;
  struct Node *next = nullptr;
  Node(int value) : value(value) { }
  Node(int value, Node *next) : value(value), next(next) { }
};

Node *makeList(vector<int> nums) {
  Node *head = new Node(nums[0]);
  Node *n    = head;
  for (int i = 1; i < nums.size(); ++i) {
    Node *tmp = new Node(nums[i]);
    n->next   = tmp;
    n         = n->next;
  }
  return head;
}

void printList(Node *head) {
  if (head->next == nullptr) {
    printf("%2d\n", head->value);
    return;
  }
  printf("%2d ", head->value);
  printList(head->next);
}

void reverseList(Node *head) {
  Node *newHead = head;
  Node *nprev = nullptr, *nnext = nullptr;
  while (newHead) {
    nnext         = newHead->next;
    newHead->next = nprev;
    nprev         = newHead;
    newHead       = nnext;
  }
  // printList(nprev);
}

Node *reverse(Node *curr) {
  if (curr->next == nullptr) {
    return curr;
  }
  auto new_head    = reverse(curr->next);
  curr->next->next = curr;
  curr->next       = nullptr;
  return new_head;
}

Node *search(Node *node, int x) {
  if (node->next == nullptr || node->next->value == x) {
    return node;
  }
  return search(node->next, x);
}

Node *reverse(Node *const left_bound, Node *p, Node *const right_bound) {
  if (p == right_bound) {
    return p;
  }
  Node *new_head = reverse(left_bound, p->next, right_bound);
  p->next->next  = p;
  p->next        = left_bound;
  return new_head;
}

int main() {
  vector<int> nums = {0, 1, 2, 3, 4};
  Node       *head = makeList(nums);

  printList(head);
  Node *left_bound  = search(head, 1);
  Node *l           = left_bound->next;
  Node *r           = (search(l, 3))->next;
  Node *right_bound = r->next;
  auto  newHead     = reverse(l, l, r);
  left_bound->next  = newHead;
  l->next           = right_bound;

  // auto revr = reverse(head);
  printList(head);
  return 0;
}
