#include "balancedTree.h"
#include "dictEntry.h"
#include <string>
#include <vector>
using namespace std;

class Dictionary1 {
  ThomasTree * dict;
 public:
  void insert(int key, string value);
  string * lookUp(int key);
  Dictionary1();
  Dictionary1(vector<int> keys, vector<string> values);
};

class Dictionary2 {
  vector<DictEntry *> * dict;
 public:
  void insert(int key, string value);
  string * lookUp(int key);
  void remove(int key);
  Dictionary2();
};
