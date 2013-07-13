# Rename a *.cpp file to *.cc file
# Author: Yigwoo
# Usage python name-cpp-to-cc.py [path-name]

import os
import os.path
from sys import argv

def changext(path):
    if os.path.isdir(path):
        for line in os.listdir(path):
            line = os.path.join(path, line)
            if (os.path.isfile(line)):
                if line.endswith('.cpp'):
                    filename = line.split('.cpp')[0]
                    filename = filename + '.cc'
                    os.rename(line, filename)
                    print "%s renamed to %s" % (str(line), str(filename))
            elif (os.path.isdir(line)):
                changext(line)
            else:
                print "%r not a file or dir!" % str(line)
    else:
        print "%r not a dir!" % str(path)

if __name__ == '__main__':
    if len(argv) != 2:
        print "usage python name-cpp-to-cc.py [path-name]"
    else:
        path = argv[1]
        if os.path.isdir(path):
            changext(path)
        else:
            print "%r not a directory!" % str(path)
