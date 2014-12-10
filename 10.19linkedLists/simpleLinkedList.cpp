#include <iostream>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int d, Node *n) {
    data = d;
    next = n;
  }
};

int main() {
  Node a(7, NULL);
  Node b(14, NULL);
  Node c(25, NULL);
  Node *head;
  head = &a;
  a.next = &b;
  b.next = &c;

  Node *p;
  for(p=head; p!=NULL; p=p->next) {
    cout << (p->data) << endl;
  }
  return 0;
}

