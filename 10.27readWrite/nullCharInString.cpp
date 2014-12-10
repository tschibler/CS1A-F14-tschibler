#include <string>
#include <iostream>
using namespace std;

int main(){
  string a = "abcdefghijklmn";
  cout << a << endl;
  a[5] = '\0';
  cout << a << endl;
  for(int i = 0; i < a.size(); i++) {
    cout << a[i] << endl;
  }
} 
