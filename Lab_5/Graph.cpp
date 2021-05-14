#include "Graph.h"
#include "PalomarReader.h"
Graph::Graph(PalomarReader pr){
    start = pr.readData();
}

Graph::Graph(FileIO pr){
    start = pr.readData();
}

void Graph::dfTrav(){
    stack<Vertex*> backtrack;
    set<Vertex*> visted;
    Vertex* currVertex;
    currVertex = start[0];

    while(start.size() > visted.size()){
        backtrack.push(currVertex);
        visted.insert(currVertex);
        while (!backtrack.empty()){
            cout << currVertex->getName();
            currVertex = backtrack.top();
            Vertex *neighbor = nullptr;
            vector<Vertex*>::iterator it = currVertex->getEdge()->begin();
            while (visted.count(*it) == 1 && it != currVertex->getEdge()->end()){
                it++;
            }
            if(it != currVertex->getEdge()->end())
            {
                neighbor = *it;
                visted.insert(neighbor);
                backtrack.push(neighbor);
            }
            else{
                backtrack.pop();
            }
        }
        if(start.size() > visted.size()){
            for(int i = 0; i <start.size(); i++){
                if(visted.count(start[i]) == 0){
                    currVertex = start[i];
                    break;
                }
            }
        }
    }
}

double Graph::compute_weight(vector<Vertex *> v) {
    Vertex * src;
    double dist = 0;
    auto it = v.begin();
    src = *it;
    for(it++; it != v.end(); it++){
        pair<double, double> x1 = src->getLoc();
        pair<double, double> x2 = (*it)->getLoc();
        dist += sqrt(pow(x1.first - x2.first, 2 ) + pow(x1.first - x2.first, 2 ));
        src = *it;
    }
    return dist;
}

void Graph::print_path(vector<Vertex*> path){
    vector<Vertex*>::iterator it;
    for(it = path.begin(); it!=path.end();it++){
        Vertex *temp = *it;
        cout << temp->getName() << " : " << temp->getID();
        if(it+1 != path.end()){
            cout << " -> ";
        }
    }
    cout << endl;
}

vector<Vertex*> Graph::getStart()const{
    return start;
}

int Graph::findID(string sr){
    int ID = -1;
    for(int i = 0; i < start.size(); i++){
        if(sr == start[i]->getName()){
            ID = start[i]->getID();
            break;
        }
    }
    return ID;
}

Vertex* Graph::findVertex(int ID){
    Vertex* curr = nullptr;
    for(int i = 0; i < start.size();i++){
        if(ID == start[i]->getID()){
            curr = start[i];
            break;
        }
    }
    return curr;
}

int Graph::findIndex(int ID){
    int index = -1;
    for(int i = 0; i < start.size(); i++) {
        if (ID == start[i]->getID()) {
            index = i;
            break;
        }
    }
    return index;
}

#define INF 100000000
#define EPS 1E-3
vector<Vertex*> Graph::shortest_path(string src, string sink, double* dist){
    Vertex* current;
    set<int> visited;
    double* sdist = new double[start.size()];
    vector<Vertex*> shortest;
    int sourceID, sinkID;
    sourceID = findID(src);
    sinkID = findID(sink);
    current = findVertex(sourceID);

    for (int i = 0; i < start.size(); i++) {
        int index = findIndex(start[i]->getID());
        *(sdist + index) = INF;
    }

    *(sdist + findIndex(sourceID)) = 0;
    visited.insert(sourceID);

    while (visited.size() < start.size()) {
        vector<Vertex*> neighbors = *current->getEdge();
        vector<double> cost = *current->getWeight();
        int currentID = findID(current->getName());
        int current_index = findIndex(currentID);
        for (int i = 0; i < neighbors.size(); i++) {
            double distance = cost[i] + *(sdist + current_index);
            int nIndex = findIndex(neighbors[i]->getID());
            if (distance < *(sdist + nIndex)) {
                *(sdist + nIndex) = distance;
            }
        }

        double cheapest =  INF;
        int cheapIndex = -1;
        int cheapID = -1;
        for (int i = 0; i < start.size(); i++) {
            if(visited.count(start[i]->getID()) != 0){
                continue;
            }
            if(cheapest > *(sdist + findIndex(start[i]->getID()))){
                cheapIndex = findIndex(start[i]->getID());
                cheapest = *(sdist + cheapIndex);
                cheapID = start[i]->getID();
            }
        }
        visited.insert(cheapID);
        current = start[cheapIndex];
    }

    Vertex* prev;
    current = findVertex(sinkID);

    while(current != findVertex(sourceID)){
        int i = 0;
        int currID = current->getID();
        shortest.push_back(findVertex(currID));
        cout << setw(3) << findVertex(currID)->getName() << "->" << findVertex(sourceID)->getName() << " " << endl;
        vector<double> costs = *current->getWeight();
        vector<Vertex *> neighbors = *current->getEdge();

        if(prev != current) {
            double cheapest = *(sdist + findIndex(currID));
            cout << "Cheapest: " << cheapest << endl;
            for (i = 0; i < neighbors.size(); i++) {
                double nCost = *(sdist + findIndex(neighbors[i]->getID()));
                cout << "\tNeighbor: " << i << " Vertex: " << neighbors[i]->getID() << " " << setw(12) << " " <<
                     " Costs " << costs[i] << " nCost " << nCost << " " << "Eval: "
                     << (abs(cheapest - costs[i] - nCost)) << endl;
                if ((abs(cheapest - costs[i] - nCost)) <= EPS || nCost == 0) {
                    current = neighbors[i];
                    break;
                }
                prev = current;
            }
        }
        else{
            double cheapest = *(sdist + (63 - findIndex(currID)));
            for (i = 0; i < neighbors.size(); i++) {
                double nCost = *(sdist + (64 - findIndex(neighbors[i]->getID())));
                cout << "\tNeighbor: " << i << " Vertex: " << neighbors[i]->getID() << " " << setw(12) << " " <<
                     " Costs " << costs[i] << " nCost " << nCost << " " << "Eval: "
                     << (abs(cheapest - costs[i] - nCost)) << endl;
                if ((abs(cheapest - costs[i] - nCost)) <= EPS || nCost == 0) {
                    current = neighbors[i];
                    break;
                }
                if(i == neighbors.size() - 1){
                    break;
                }
                prev = new Vertex;
            }
        }
    }
    shortest.push_back(findVertex(sourceID));
    dist = (sdist+findIndex(sinkID));
    return shortest;
}


