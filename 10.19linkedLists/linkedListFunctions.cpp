#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node *next;
  Node(int d, Node *n) : data(d), next(n) {}
};

void printNode(const Node* const node) {
  cout << node << "\t" << node->data << endl;
}

void printList(const Node *head) {
  const Node *p;
  for(p=head; p!=NULL; p=p->next) {
    printNode(p);
    if(p==p->next) {
      cout << "Infinite loop on " << p->data << " as it points to itself" << endl;
      return;
    }
  }
  cout << endl;
}

Node * deepCopyOfLinkedList(Node *head) {
  if(head==NULL)
    return NULL;
  Node *nHead = new Node(head->data,NULL);
  Node *nCursor = nHead;
  for(Node *cursor=head->next; cursor!=NULL; cursor=cursor->next, nCursor=nCursor->next) {
    nCursor->next = new Node(cursor->data,NULL);
  }
  return nHead;
}

//head is inclusive
//stop is exclusive
Node * sortLinkedList(Node * head, Node * stop) {  
  if(head == stop)
    return head;
  Node *trailingPtr = head;
  Node *ptr = head->next;
  Node *pivot = head;
  int temp;
  while(ptr!=stop) {
    if(ptr->data < pivot->data) {
      trailingPtr->next = ptr->next;
      ptr->next = head->next;
      head->next = ptr;
      temp = ptr->data;
      ptr->data = head->data;
      head->data = temp;
      if(pivot==head)
	pivot = head->next;
      ptr = trailingPtr->next;
    } else {
      trailingPtr = ptr;
      ptr = ptr->next;
    }
  }
  sortLinkedList(head,pivot);
  sortLinkedList(pivot->next,stop);
  return head;
}

Node * sortedCopyOfLinkedList(Node *head) {
  Node* nHead = deepCopyOfLinkedList(head);
  return sortLinkedList(nHead, NULL);
}

Node * noDupCopyOfLinkedList(Node *head) {
  head = deepCopyOfLinkedList(head);
  Node * nHead = sortedCopyOfLinkedList(head);
  vector<double[3]> duplicateList;
  //use sorted list to create duplicate list
  //iterate over starting list
  //check if the next item is in duplicate list (binary search as duplicate list is sorted)
  //  if one has not been checked -> flag as checked
  //  else -> remove it
  //  if no more to remove -> delete from duplicate list
}

Node * concatenatedCopy(Node *head1, Node *head2) {
  Node * nHead1 = deepCopyOfLinkedList(head1);
  Node * nHead2 = deepCopyOfLinkedList(head2);
  if(nHead1==NULL)
    return nHead2;
  Node * cursor = nHead1;
  while(cursor->next!=NULL)
    cursor=cursor->next;
  cursor->next = nHead2;
  return nHead1;
}

Node * mergedCopyOfSortedLinkedLists(Node *head1, Node *head2) {
  Node *h1 = deepCopyOfLinkedList(head1);
  Node *h2 = deepCopyOfLinkedList(head2);
  Node *head;
  if(h1->data<=h2->data) {
    head = h1;
    h1 = h1->next;
  } else {
    head = h2;
    h2 = h2->next;
  }
  Node *tempPtr = head;
  while(h1!=NULL&&h2!=NULL) {
    if(h1->data<=h2->data) {
      tempPtr->next = h1;
      h1 = h1->next;
    } else {
      tempPtr->next = h2;
      h2 = h2->next;
    }
    tempPtr=tempPtr->next;
  }
  if(h1==NULL)
    tempPtr->next = h2;
  else
    tempPtr->next = h1;
  return head;
}

int main() {
  srand(time(NULL));
  Node * head = new Node(rand()%100,NULL);
  Node * head1 = new Node(rand()%100,NULL);
  Node * n = head;
  Node * n1 = head1;
  for(int i = 0; i < 20; i++) {
    n->next = new Node(rand()%100,NULL);
    n = n->next;
    n1->next = new Node(rand()%100,NULL);
    n1 = n1->next;
  }
  printList(sortedCopyOfLinkedList(head));
  cout << "Original list:" << endl << endl;
  printList(head);
  cout << endl << "Copy of original list:" << endl << endl;
  printList(deepCopyOfLinkedList(head));
  cout << endl << "Sorted copy of original list:" << endl << endl;
  printList(sortedCopyOfLinkedList(head));
  /*cout << endl << "No duplicate copy of original list:" << endl << endl;  
    printList(noDupCopyOfLinkedList(head));*/
  cout << endl << "Secondary list" << endl << endl;
  printList(head1);
  cout << endl << "Concatenation of the two lists:" << endl << endl;
  printList(concatenatedCopy(head, head1));
  cout << endl << "Merged sorted lists:" << endl << endl;
  printList(mergedCopyOfSortedLinkedLists(sortedCopyOfLinkedList(head),sortedCopyOfLinkedList(head1)));
  
  return 0;
}



