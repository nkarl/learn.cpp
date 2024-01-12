#include <iostream>
#include <vector>

using std::cout, std::endl, std::vector;

struct Node {
  int value; struct Node *next = nullptr;
  Node(int value) : value(value) {}
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

void postOrder(Node *head) {
  if (head->next == nullptr) {
    cout << head->value << ' ';
    return;
  }
  postOrder(head->next);
  cout << head->value << ' ';
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
  //printList(nprev);
}

Node *reverse(Node *head) {
  if (head->next == nullptr)
    return head;
  auto newHead = reverse(head->next);
  head->next->next = head;
  head->next = nullptr;
  return newHead;
}

int main() {
  vector<int> nums = {0, 1, 2, 3, 4};
  Node *head = makeList(nums);

  printList(head);
  // postOrder(head);
  // reverseList(head);
  auto revr = reverse(head);
  printList(revr);
  return 0;
}
