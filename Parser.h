#include <bits/stdc++.h>
#include "misc.h"
#ifndef UNTITLED_PARSER_H
#define UNTITLED_PARSER_H

using namespace std;

class Parser {
public:
    Parser() {};

    void readEdgesFromFile(int *maxSize, string fileName, int * source, int * sink);
    list<Edge> &getEdges();
    void printGraph(string fileName, shared_ptr<list<Edge>> ptr, string graphName);


private:
    list<Edge> edges;
};

#endif //UNTITLED_PARSER_H
