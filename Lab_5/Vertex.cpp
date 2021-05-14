#include "Vertex.h"

int Vertex::getID()const{ return ID; }
string Vertex::getName()const{ return name; }
void Vertex::setID(int a){ ID = a; }
void Vertex::setName(string n){ name = n; }
vector<double> *Vertex::getWeight(){ return &weight; }
vector<Vertex*> *Vertex::getEdge(){ return &edges; }
void Vertex::setLoc(pair<double, double> l){ loc = l; }
void Vertex::addEdge(Vertex*v){ edges.push_back(v); }
void Vertex::addWeight(double w){ weight.push_back(w); }
pair<double, double> Vertex::getLoc()const{ return loc; }
