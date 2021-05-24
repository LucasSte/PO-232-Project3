#include "Parser.h"
#include "Graph.h"

int main() {
    Parser p;
    int maxSize = 0;
    int source, sink;
    p.readEdgesFromFile(&maxSize, "../g1.dat", &source, &sink);
    auto ret = p.getEdges();

    cout << "Source: " << source << endl;
    cout << "Sink: " << sink << endl;
    Graph g(maxSize);
    g.buildGraph(ret);
    g.setSourceAndSink(source, sink);

    cout << "Maximum Flow = " << g.fordFulkerson() << endl;

    shared_ptr<list<Edge>> ptr = g.getUniqueEdgeList();

    p.printGraph("../out1.dat", ptr, "g1");

    return 0;
}
