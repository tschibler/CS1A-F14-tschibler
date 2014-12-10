#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int main() {
  char a[] = {'a','a','a','a',',','h','h','g','f',',','a','s','d','f','\0'};
  char * ptr;
  ptr = strtok(a,",");
  for(int i = 0; i < 2; i++) {
    ptr = strtok(NULL,",");
  }
  cout << strcmp(ptr,"asdf") << endl;
  return 0;
}
