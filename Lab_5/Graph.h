#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include "Vertex.h"
#include "FileIO.h"
#include "PalomarReader.h"
#include <vector>
#include <stack>
#include <set>
#include <cmath>
#include <math.h>
using namespace std;

class Graph {
private:
    vector<Vertex*> start;
public:
    Graph() = default;
    explicit Graph(FileIO fp);
    explicit Graph(PalomarReader pr);
    void dfTrav();
    int findID(string sr);
    Vertex* findVertex(int ID);
    int findIndex(int ID);
    vector<Vertex*> shortest_path(string src, string sink, double* dist);
    double compute_weight(vector<Vertex*> v);
    vector<Vertex*> getStart()const;

    void print_path(vector<Vertex*>);
};


#endif