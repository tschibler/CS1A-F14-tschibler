#ifndef BALANCED_TREE_H
#define BALANCED_TREE_H

#include <iostream>
#include <vector>
#include <cmath>
#include "dictEntry.h"
using namespace std;

class ThomasTree {
  vector<DictEntry *> tree;
  int getChildIndex(int parentIndex, int leftOrRight /* left - 0, right - 1 */);
  int getParentIndex(int childIndex);
  int isRightChild(int childIndex);
  void initNextLayer();
  int findNearestOpening(int index);
  int pushUp(int index, DictEntry * data);
  int pullUp(int index, DictEntry * data);
  void initFromSortedData(vector<DictEntry> * entries, unsigned int whereToAdd = 1, unsigned int begin = 1, unsigned int end = 0);
 public:
  int insertData(DictEntry * newData, int index = 0);
  string * getData(int key);
  void printTree();
  ThomasTree();
  ThomasTree(vector<DictEntry> entries);
};

#endif
