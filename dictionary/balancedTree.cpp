#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "balancedTree.h"
using namespace std;

void ThomasTree::printTree() {
  unsigned int k = 2;
  for(unsigned int i = 1; i < tree.size(); i++) { 
    if(tree[i]!=NULL)
      cout << tree[i]->key;
    else
      cout << "-";
    cout << " ";
    if(i == k - 1) {
      cout << endl;
      k = 2*k;
    }
  }
}

int ThomasTree::getChildIndex(int parentIndex, int leftOrRight /* left - 0, right - 1 */) {
  return 2*parentIndex + leftOrRight;
}

int ThomasTree::getParentIndex(int childIndex) {
  return (childIndex)/2;
}

int ThomasTree::isRightChild(int childIndex) {
  if(childIndex==1)
    return -1;
  return (childIndex)%2;
}

void ThomasTree::initNextLayer() {
  int newSize = getChildIndex(tree.size()-1,1);
  for(int i = tree.size(); i <= newSize; i++) {
    tree.push_back(NULL);
  }
}

int ThomasTree::findNearestOpening(int index) {
  for(unsigned int i = 1; i <= pow(2,floor(log2(index))); i++) {
    if(floor(log2(index))==floor(log2(index-i)) && tree[index-i]==NULL)
      return index-i;
    if(floor(log2(index))==floor(log2(index+i)) && tree[index+i]==NULL)
      return index+i;
  }
  cerr << "No opening found for index: " << index << endl;
  return -1;
}

int ThomasTree::pushUp(int index, DictEntry * data) {
  DictEntry * temp = tree[getParentIndex(index)];
  tree[getParentIndex(index)] = data;
  int newIndex;
  if(isRightChild(index))
    newIndex = index-1;
  else
    newIndex = index+1;
  insertData(temp,newIndex);
  return newIndex;
}

int ThomasTree::pullUp(int index, DictEntry * data) {
  int newIndex = getParentIndex(index);
  while(isRightChild(index)==isRightChild(newIndex))
    newIndex = getParentIndex(newIndex);
  newIndex = getParentIndex(newIndex);
  DictEntry * temp = tree[newIndex];
  tree[newIndex] = data;
  newIndex = insertData(temp, getChildIndex(newIndex, isRightChild(index)));
  return newIndex;
}

int ThomasTree::insertData(DictEntry * newData, int index) {
  if(index==0) {
    index = 1;
    tree[0]->key++;
  }
  while(index < tree.size() && tree[index]!=NULL)
    index = (newData->key < tree[index]->key) ? getChildIndex(index, 0) : getChildIndex(index, 1);
  if(index < tree.size())
    tree[index] = newData;
  else if(floor(log2(index))>floor(log2(tree[0]->key))) {
    int desiredIndex = findNearestOpening(getParentIndex(index));
    if(isRightChild(index) == ((desiredIndex-getParentIndex(index))/abs(desiredIndex-getParentIndex(index))+1)/2) {
      index = pullUp(index, newData);
    } else {
      index = pushUp(index, newData);
    }
  } else {
    initNextLayer();
    tree[index] = newData;
  }
  return index;
}

string * ThomasTree::getData(int key) {
  int index = 1;
  while(index<tree.size() && tree[index]!=NULL) {
    if(key==tree[index]->key)
      return &(tree[index]->value);
    else if(key>tree[index]->key)
      index = getChildIndex(index, 1);
    else
      index = getChildIndex(index, 0);
  }
  return NULL;
}

ThomasTree::ThomasTree() {
  tree.push_back(new DictEntry());
  tree[0]->key = 0;
}

bool compare(DictEntry a, DictEntry b) {
  return a.key <= b.key;
}

void ThomasTree::initFromSortedData(vector<DictEntry> * entries, unsigned int whereToAdd, unsigned int begin, unsigned int end) {
  if(end == 0)
    end = entries->size();
  unsigned int middle = (begin + end)/2;
  DictEntry * nextEntry = new DictEntry();
  nextEntry->key = entries[0][middle-1].key;
  nextEntry->value = entries[0][middle-1].value;
  tree[whereToAdd] = nextEntry;
  //cout << "Added " << nextEntry->key << " at index " << whereToAdd << endl;
  if(begin < middle)
    initFromSortedData(entries, getChildIndex(whereToAdd, 0), begin, middle - 1);
  if(end > middle)
    initFromSortedData(entries, getChildIndex(whereToAdd, 1), middle + 1, end);
}

ThomasTree::ThomasTree(vector<DictEntry> entries) {
  tree.push_back(new DictEntry());
  tree[0]->key = entries.size();
  while(tree.size() < entries.size())
    initNextLayer();
  sort(entries.begin(), entries.end(), compare);
  initFromSortedData(&entries);
}
