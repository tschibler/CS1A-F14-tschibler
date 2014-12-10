#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(int argc, char * argv[]) {
  string line;
  char * tokenPtr;
  ifstream infile ("/cs/faculty/pconrad/public_html/data/census/1990NameData/dist.all.last");
  ofstream outfile;

  outfile.open ("censusDataEdited.txt"); // dot notation

  if (!infile.is_open() || !outfile.is_open()) {
    cerr << "Unable to open file" << endl; 
    exit(1);
  }

  while ( getline (infile,line) ) {
    char ireallydontcare[line.size()+1];
    for(int i = 0; i < line.size(); i++)
      ireallydontcare[i] = line[i];
    ireallydontcare[line.size()] = '\0';
    tokenPtr = strtok(ireallydontcare," ");
    while (tokenPtr!=NULL) {
      if(!strcmp(tokenPtr,"0.000")) {
	infile.close();
	outfile.close();
	exit(1);
      }
      tokenPtr = strtok(NULL," ");
    }
    outfile << line << "\n";
  }
  infile.close();
  outfile.close();
  return 0;
}
