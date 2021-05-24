#include "Graph.h"

Graph::Graph(int size) :    gr(size, vector<int>(size, 0)),
                            fgr(size, vector<int>(size, 0)) {
    capacity = size;
}

// a->b with capacity (cap)
void Graph::addEdge(int a, int b, int cap) {
    gr[a][b] = cap;
}

void Graph::setSourceAndSink(int source, int sink) {
    s = source;
    t = sink;
}

void Graph::buildGraph(list<Edge> & edges) {
    for(auto p : edges)
    {
        addEdge(p.from, p.to, p.capacity);
    }
}

bool Graph::fulkersonBfs(vector<int> *parent, vector<vector<int>> & auxGr) {

    vector<bool> visited(capacity, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    (*parent)[s] = -1;

    int a;
    while(!q.empty()) {
        a = q.front();
        q.pop();
        for(int b=0; b < capacity; b++) {
            if(!visited[b] && auxGr[a][b] > 0) {
                if(b == t) {
                    (*parent)[b] = a;
                    return true;
                }
                q.push(b);
                (*parent)[b] = a;
                visited[b] = true;
            }
        }
    }

    return false;
}

int Graph::fordFulkerson() {
    int a, b;

    vector<int> parent(capacity);
    int maxFlow = 0;
    int pathFlow;
    vector<vector<int>> auxGr = gr;

    while(fulkersonBfs(&parent, auxGr)) {
        pathFlow = INT_MAX;
        for(b = t; b != s; b = parent[b]) {
            a = parent[b];
            pathFlow = min(pathFlow, auxGr[a][b]);
        }

        for(b = t; b != s; b = parent[b]) {
            a = parent[b];
            auxGr[a][b] -= pathFlow;
            auxGr[b][a] += pathFlow;
            fgr[a][b] += auxGr[a][b] >= 0? pathFlow :  pathFlow + auxGr[a][b];
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}


shared_ptr<list<Edge>> Graph::getUniqueEdgeList() {
    shared_ptr<list<Edge>> ptr = make_shared<list<Edge>>();

    for(int i=0; i<capacity; i++) {
        for(int j=0; j<capacity; j++) {
            if(gr[i][j] > 0) {
                ptr->push_back(Edge{
                    i, j, gr[i][j], fgr[i][j]
                });
            }
        }
    }

    return ptr;
}

