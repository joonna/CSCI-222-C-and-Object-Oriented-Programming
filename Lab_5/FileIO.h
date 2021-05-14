#ifndef GRAPH_FILEIO_H
#define GRAPH_FILEIO_H

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Vertex.h"
using namespace std;

class FileIO {
private:
    ifstream *fp;
public:
    FileIO(string src);
    ifstream *getFP()const;
    ~FileIO();
    virtual vector<Vertex*>readData(){
        vector <Vertex*> temp;
        return temp;
    }
};


#endif