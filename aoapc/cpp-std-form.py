import os
from sys import argv

def createCppFile(filepath):
    stdform = '''#include <iostream>
#include <string>
#include <vector>
#include <time>
using namespace std;

int main() {
  t = clock();
  t = clock() - t;
  cout << "time:clocks  " << (double)t/CLOCKS_PER_SEC << ":" << (int)clock() << endl;
  return 0;
}
'''
    file = open(filepath, 'w')
    file.write(stdform)
    file.close()

if len(argv) != 2:
    print "Usage: python cpp-std-form.py [file-path]"

filepath = argv[1]
if os.path.exists(filepath):
   print "file '%s' exists? overrite it? (y/n)" % str(filepath)
   ans = raw_input("-->")
   if ans == 'y':
       createCppFile(filepath)
   else:
       pass
else:
    createCppFile(filepath)
