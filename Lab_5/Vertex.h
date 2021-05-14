#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H

#include <iostream>
#include <vector>
using namespace std;

class Vertex {
private:
    int ID;
    string name;
    pair<double, double> loc;
    vector<double> weight;
    vector<Vertex *> edges;
public:
    static int vertex_count;

    inline Vertex() {
        vertex_count++;
        ID = vertex_count;
    }

    inline Vertex(string n, pair<double, double> l) {
        name = n;
        loc = l;
        vertex_count++;
        ID = vertex_count;
    }

    int getID()const;

    string getName()const;

    void setID(int a);

    void setName(string n);

    vector<double> *getWeight();

    vector<Vertex*> *getEdge();

    pair<double, double> getLoc()const;
    void setLoc(pair<double, double>);
    void addEdge(Vertex*);
    void addWeight(double);
};

#endif
