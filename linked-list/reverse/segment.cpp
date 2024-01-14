#include <iostream>
#include <vector>

using std::vector;

struct Node {
  int value;
  struct Node *next = nullptr;
  Node(int value) : value(value) {}
  Node(int value, Node *next) : value(value), next(next) {}
};

Node *makeList(vector<int> nums) {
  Node *head = new Node(nums[0]);
  Node *n = head;
  for (int i = 1; i < nums.size(); ++i) {
    Node *tmp = new Node(nums[i]);
    n->next = tmp;
    n = n->next;
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
  Node *new_head = head;
  Node *nprev = nullptr, *nnext = nullptr;
  while (new_head) {
    nnext = new_head->next;
    new_head->next = nprev;
    nprev = new_head;
    new_head = nnext;
  }
  return new_head;
}

Node *reverse(Node *head) {
  if (head->next == nullptr) {
    return head;
  }
  auto new_head = reverse(head->next);
  head->next->next = head;
  head->next = nullptr;
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
  Node *new_head = reverse(head->next, left + 1, right, bounds);
  head->next->next = head;
  head->next = nullptr;
  return new_head;
}

Node *reverseBetween(Node *head, int left, int right) {
  Bound bounds;
  bounds.left = new Node(-1, head);
  Node *dummy = bounds.left;
  Node *new_tail = head;

  int i = 1;
  for (; i < left; ++i) {
    new_tail = new_tail->next;
    bounds.left = bounds.left->next;
  }

  bounds.left->next = reverse(new_tail, left, right, &bounds);
  new_tail->next = bounds.right;
  return dummy->next;
}

int main() {
  vector<int> nums = {-3, -2, 3, -5, 3, 4, -4};
  int left = 5, right = 7;
  Node *head = makeList(nums);
  printList(head);
  Node *new_head = reverseBetween(head, left, right);
  printList(new_head);
  return 0;
}
