#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

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
    cout << head->value << endl;
    return;
  }
  cout << head->value << ' ';
  printList(head->next);
}

void reverseList(Node *head) {
  Node *newHead = head;
  Node *nprev = nullptr, *nnext = nullptr;
  while (newHead) {
    nnext = newHead->next;
    newHead->next = nprev;
    nprev = newHead;
    newHead = nnext;
  }
  // printList(nprev);
}

Node *reverse(Node *head) {
  if (head->next == nullptr)
    return head;
  auto newHead = reverse(head->next);
  head->next->next = head;
  head->next = nullptr;
  return newHead;
}

// Node *rev_segment(Node *const left_bound, Node *p, Node *const right_bound) {
//   if (p == right_bound) {
//     printf("%d ", p->value);
//     return p;
//   }
//   printf("%d ", p->value);
//   return rev_segment(left_bound, p->next, right_bound);
// }

struct Bound {
  Node *left, *right;
};

Node *reverse(Node *head, int left, int right, Bound *bounds) {
  if (left == right) {
    bounds->right = head->next;
    return head;
  }
  Node *newHead = reverse(head->next, left+1, right, bounds);
  head->next->next = head;
  head->next = nullptr;
  return newHead;
}

Node *reverseBetween(Node *head, int left, int right) {
  Bound bounds; bounds.left = new Node(-1, head);
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
  // vector<int> nums = {0, 1, 2, 3, 4};
  vector<int> nums = {-3, -2, 3, -5, 3, 4, -4};
  int left = 5, right = 7;
  Node *head = makeList(nums);

  printList(head);
  Node *newHead = reverseBetween(head, left, right);
  printList(newHead);
  return 0;
}
