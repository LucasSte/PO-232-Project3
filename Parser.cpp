#include "Parser.h"


void Parser::readEdgesFromFile(int *maxSize, string fileName, int * source, int * sink) {
    *maxSize = 0;
    string line;

    ifstream file;
    file.open(fileName);

    // Read first lines
    getline(file, line);

    // Get
    int from = 0, to = 0, cost;
    int status;

    unordered_set<int> posSource;
    unordered_set<int> posSink;

    while (getline(file, line)) {
        status = sscanf(line.data(), "%d -> %d [label = \"%d\"]", &from, &to, &cost);
        if(status == 3) {
            posSource.insert(from);
            posSink.insert(to);

            edges.emplace_back(Edge{from, to, cost, 0});
            *maxSize = max(*maxSize, max(from+1, to+1));
        }
    }

    unordered_set<int> aux = posSource;
    for(int e : posSink)
        aux.erase(e);
    *source = *aux.begin();

    aux = posSink;
    for(int e : posSource)
        aux.erase(e);

    *sink = *aux.begin();

    file.close();
}

list<Edge> & Parser::getEdges() {
    return edges;
}

void Parser::printGraph(string fileName, shared_ptr<list<Edge>> ptr, string graphName) {
    ofstream file;
    file.open(fileName);

    file << "digraph " << graphName << " {" << endl;

    for(Edge & e : *ptr) {
        file << e.from << " -> " << e.to << " [label = \"" << e.flow << "/" << e.capacity << "\"]" << endl;
    }

    file << "}\n";

    file.close();
}
