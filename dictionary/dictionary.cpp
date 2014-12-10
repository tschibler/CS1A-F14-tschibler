#include "balancedTree.h"
#include "dictionary.h"
#include "dictEntry.h"
#include <string>
#include <vector>
using namespace std;

void Dictionary1::insert(int key, string value) {
  DictEntry * newEntry = new DictEntry();
  newEntry->key = key;
  newEntry->value = value;
  dict->insertData(newEntry);
}

string * Dictionary1::lookUp(int key) {
  return dict->getData(key);
}

Dictionary1::Dictionary1() {
  dict = new ThomasTree();
}

Dictionary1::Dictionary1(vector<int> keys, vector<string> values) {
  vector<DictEntry> entries;
  for(unsigned int i = 0; i < keys.size(); i++) {
    DictEntry newEntry;
    newEntry.key = keys[i];
    newEntry.value = values[i];
    entries.push_back(newEntry);
  }
  dict = new ThomasTree(entries);
}

void Dictionary2::insert(int key, string value) {
  DictEntry * newEntry = new DictEntry();
  newEntry->key = key;
  newEntry->value = value;
  dict->push_back(newEntry);
}

string * Dictionary2::lookUp(int key) {
  for(unsigned int i = 0; i < dict->size(); i++) {
    if(key == dict[0][i]->key)
      return &(dict[0][i]->value);
  }
  return NULL;
}

Dictionary2::Dictionary2() {
  dict = new vector<DictEntry *>;
}
