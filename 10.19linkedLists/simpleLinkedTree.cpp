#include <iostream>
using namespace std;

struct TNode {
  int data;
  TNode *left;
  TNode *right;
  TNode(int d, TNode *l, TNode *r) {
    data = d;
    left = l;
    right = r;
  }
};

void traverseTree(TNode *head) {
  if(head==NULL) return;
  cout << head->data << endl;
  traverseTree(head->left);
  traverseTree(head->right);
}

int main() {
  TNode a(42, NULL, NULL);
  TNode b(13, NULL, NULL);
  TNode c(3, NULL, NULL);
  TNode d(78, NULL, NULL);
  TNode *head;
  head = &a;
  a.left = &b;
  a.right = &d;
  b.left = &c;

  traverseTree(head);
  return 0;
}

