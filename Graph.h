#include <bits/stdc++.h>
#include "misc.h"

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H
using namespace std;
class Graph {

public:
    explicit Graph(int size);
    void addEdge(int a, int b, int cap);
    void buildGraph(list<Edge> & edges);
    // getUniqueEdgeList does the opposite of buildGraph
    shared_ptr<list<Edge>> getUniqueEdgeList(); //Get unique edge list to print in a file
    int fordFulkerson();
    void setSourceAndSink(int source, int sink);

private:
    int capacity;
    vector<vector<int>> gr;
    vector<vector<int>> fgr;
    int s;
    int t;
    bool fulkersonBfs(vector<int> * parent, vector<vector<int>> & auxGr);
};

#endif //UNTITLED_GRAPH_H
