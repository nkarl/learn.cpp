#include <iostream>
#include <limits.h>
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

Node *reverseList(Node *head) {
  Node *prev = nullptr, *new_head = head;
  while (new_head) {
    Node *next     = new_head->next;
    new_head->next = prev;
    prev           = new_head;
    new_head       = next;
  }
  return new_head;
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

struct Bound {
  Node *left, *right;
};

Node *reverse(Node *head, int left, int right, Bound *bounds) {
  if (left == right) {
    bounds->right = head->next;
    return head;
  }
  Node *new_head   = reverse(head->next, left + 1, right, bounds);
  head->next->next = head;
  head->next       = nullptr;
  return new_head;
}

Node *reverseBetween(Node *head, int left, int right) {
  Bound bounds;
  bounds.left = new Node(INT_MAX, head);

  Node *dummy     = bounds.left;
  Node *new_right = head;

  int i = 1;
  for (; i < left; ++i) {
    bounds.left = bounds.left->next;
    new_right   = new_right->next;  // new_right is old_left
  }

  Node *new_left    = reverse(new_right, left, right, &bounds);
  bounds.left->next = new_left;
  new_right->next   = bounds.right;
  return dummy->next;
}

int main() {
  vector<int> nums = {-3, -2, 3, -5, 3, 4, -4};
  int         left = 5, right = 7;
  Node       *head = makeList(nums);
  printList(head);
  Node *new_head = reverseBetween(head, left, right);
  printList(new_head);
  return 0;
}
