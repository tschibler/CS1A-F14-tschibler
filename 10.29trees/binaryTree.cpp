#include <iostream>
using namespace std;

struct Tnode {
  int data;
  Tnode* left;
  Tnode* right;
  Tnode(int d, Tnode* l, Tnode* r) {
    data = d;
    left = l;
    right = r;
  }
  Tnode(int d) {
    data = d;
    left = NULL;
    right = NULL;
  }
};

struct Node {
  Tnode * tNodePtr;
  Node * next;
  Node(Tnode * t, Node * n) {
    tNodePtr = t;
    next = n;
  }
};

void printData(const Tnode * const toBePrinted) {
  cout << toBePrinted->data << endl;
}

void printTree(const Tnode * const tree) {
  if (tree==NULL)
    return;
  printData(tree);
  printTree(tree->left);
  printTree(tree->right);
}

void insertData(Tnode * tree, int newData) {
  if(newData < tree->data) {
    if(tree->left==NULL)
      tree->left = new Tnode(newData);
    else
      insertData(tree->left,newData);
  } else {
    if(tree->right==NULL)
      tree->right = new Tnode(newData);
    else
      insertData(tree->right,newData);
  }
}

Tnode * constructTree(int data[],int n) {
  if(n<1) return NULL;
  Tnode * const head = new Tnode(data[0]);
  for (int i = 1; i < n; i++) {
    insertData(head,data[i]);
  }
  return head;
}

int* sort(int data[], int n) {
  if(n<1)
    return NULL;
  Tnode * const head = constructTree(data,n);
  Tnode * ptr = head;
  Node * stack = NULL;
  Node * stack_temp;
  int * out = new int[n];
  int i = 0; 

 tryLeft:  
  if(ptr->left) {
    stack = new Node(ptr,stack);
    ptr = ptr->left;
    goto tryLeft;
  }
 tryRight:
  out[i] = ptr->data;
  i++;
  if(ptr->right) {
    ptr = ptr->right;
    if(ptr->left)
      goto tryLeft;
    goto tryRight;
  }
  
  if(stack!=NULL) {
    ptr = stack->tNodePtr;
    stack_temp = stack;
    stack = stack->next;
    delete stack_temp;
    goto tryRight;
  }
  return out;
}

int main() {
  int data[] = {4,6,3,5,7,2,8,10,3,23,3,45,23,86,1,23,3,7,9,0,2};
  int* a = sort(data,21);
  for(int i = 0; i < 21; i++) {
    cout << a[i] << endl;
  }
}
