#include "googlePalomar.h"

int Vertex::vertex_count = 0;
int main() {
    string mapFile = "palomar_-_updated_-_double_linked.txt";
    double *dist = nullptr;
    PalomarReader sp(mapFile);
    Graph googlePalomar(sp);
    string src, sink;
    vector<Vertex*> path;
    cout << "Enter Starting loc: ";
    getline(cin, src);
    cout  << "Enter Destination loc: ";
    getline(cin, sink);

    path = googlePalomar.shortest_path(src, sink, dist);
    googlePalomar.print_path(path);
    cout<<endl;
    cout << "Total Dist : " << googlePalomar.compute_weight(path);
    delete dist;

    return 0;
}
