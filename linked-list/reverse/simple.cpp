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

void printListPostOrder(Node *head) {
  if (head->next == nullptr) {
    printf("%2d\n", head->value);
    return;
  }
  printListPostOrder(head->next);
  printf("%2d ", head->value);
}

Node *reverseList(Node *head) {
  Node *prev = nullptr, *curr = head;
  while (curr) {
    Node *next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

Node *reverse(Node *curr) {
  if (curr->next == nullptr) {
    return curr;
  }
  auto new_head = reverse(curr->next);
  curr->next->next = curr;
  curr->next = nullptr;
  return new_head;
}

int main() {
  vector<int> nums = {0, 1, 2, 3, 4};
  Node *head = makeList(nums);

  printList(head);
  // printListPostOrder(head);
  // auto revr = reverseList(head);
  auto revr = reverse(head);
  printList(revr);
  return 0;
}
