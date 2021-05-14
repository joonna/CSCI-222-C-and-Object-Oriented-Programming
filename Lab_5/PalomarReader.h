#ifndef GRAPH_PALOMARREADER_H
#define GRAPH_PALOMARREADER_H


#include "FileIO.h"
#include "Vertex.h"
#include <vector>
using namespace std;
class PalomarReader : public FileIO{
private:
    vector<Vertex*> head;
public:
    explicit PalomarReader(string src);
    int find_index(string)const;
    vector<Vertex*> readData() override;
};


#endif