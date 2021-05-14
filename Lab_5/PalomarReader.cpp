#include "PalomarReader.h"
#include <math.h>
PalomarReader::PalomarReader(string src) : FileIO(src){}

vector<Vertex*> PalomarReader::readData() {
    ifstream *myFile;
    myFile = getFP();
    while(!myFile->eof()){
        string buffer;
        getline(*myFile, buffer);
        stringstream s_stream(buffer);
        string name, temp;
        double xloc, yloc;
        getline(s_stream, name, ',');
        getline(s_stream, temp, ',');
        xloc = stof(temp);
        getline(s_stream, temp, ',');
        yloc = stof(temp);

        pair<double ,double> loc(xloc, yloc);
        Vertex *v = new Vertex(name, loc);
        head.push_back(v);
    }
    myFile->seekg(0); //goto top of file
    for(int i = 0; i < head.size(); i++){
        string buffer;
        getline(*myFile, buffer);
        stringstream s_stream(buffer);
        string temp;
        getline(s_stream, temp, ',');
        getline(s_stream, temp, ',');
        getline(s_stream, temp, ',');
        while (s_stream.good())
        {
            getline(s_stream, temp, ',');
            int index = find_index(temp);
            auto edge = (head[i]->getEdge());
            edge->push_back(head[index]);

            double dist;
            pair<double, double> src = head[i]->getLoc();
            pair<double, double> sink = head[index]->getLoc();
            dist = sqrt(pow(src.first-sink.first,2) + pow(src.second - sink.second, 2));
            auto weight = (head[i]->getWeight());
            weight->push_back(dist);
        }
    }
    return head;
}

int PalomarReader::find_index(string name) const {
    for(int i = 0; i < head.size(); i++){
        if(head[i]->getName() == name){
            return i;
        }
    }
    return  -1;
}