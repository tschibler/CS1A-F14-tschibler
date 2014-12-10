#include "dictionary.h"
#include <vector>
#include "stopwatch.h"
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
  srand(time(NULL));
  
  cout << "Using balanced BST (inserting one at a time and balancing)" << endl;

  Dictionary1 d1 = Dictionary1();
  StopWatch timer = StopWatch();
  
  timer.start();
  for(int i = 0; i < 1000; i++) {
    d1.insert(i,"value");
  }
  timer.stop();
  cout << "\tWorst case (sorted list) initialization for 1000 entries took " << timer.readValue() << " seconds" << endl;
  timer.reset();
  
  d1 = Dictionary1();
  timer.start();
  for(int i = 0; i < 1000; i++)
    d1.insert(rand()%1000000,"value");
  timer.stop();
  cout << "\tInitialization with 1000 random entries took " << timer.readValue() << " seconds" << endl << endl;
  timer.reset();

  int seed = rand();
  if(seed == 0)
    seed = 1;
  vector<int> sortedKeys;
  vector<int> keys;
  
  for(int exp = 0; exp < 6; exp++) {
    sortedKeys.clear();
    keys.clear();
    for(unsigned int i = 0; i < pow(10,exp); i++)
      sortedKeys.push_back(i);
    
    int index = 0;
    for(unsigned int i = 0; i < pow(10,exp); i++) {
      index = (index + seed)%sortedKeys.size();
      keys.push_back(sortedKeys[index]);
      sortedKeys.erase(sortedKeys.begin()+index);
    }
    
    cout << "For " << (int)pow(10,exp) << " entries:" << endl;
    cout << "\tUsing balanced BST" << endl;
    
    timer.start();
    d1 = Dictionary1(keys, vector<string>(pow(10,exp),"value"));
    timer.stop();
    cout << "\t\tOptimal initialization (by sorting data and then constructing efficiently) took " << timer.readValue() << " seconds" << endl;
    timer.reset();
        
    timer.start();
    for(int i = 0; i < pow(10,exp); i++)
      d1.lookUp(i);
    timer.stop();
    cout << "\t\tLook up on every key took " << timer.readValue() << " seconds" << endl;
    timer.reset();
    
    cout << "\tUsing standard vector" << endl;
    
    Dictionary2 d2 = Dictionary2();
    timer.start();
    for(int i = 0; i < pow(10,exp); i++)
      d2.insert(keys[i],"value");
    timer.stop();
    cout << "\t\tInitialization took " << timer.readValue() << " seconds" << endl;
    timer.reset();

    timer.start();
    for(int i = 0; i < pow(10,exp); i++)
      d2.lookUp(i);
    timer.stop();
    cout << "\t\tLook up on every item took " << timer.readValue() << " seconds" << endl;
    timer.reset();
  }
}
