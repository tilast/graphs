#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "node.h"
#include <string>

using std::vector;
using std::string;

class Graph
{
public:
    typedef vector<Node*> Nodes;

    Graph();
    ~Graph();

    void addNode(Node*);
    void removeNode(Node*);

    void addEdge(Node*, Node*);
    void removeEdge(Node*, Node*);

    Node* getNodeById(int);
    Nodes* getAdjNodes(Node*);

    bool nodeExists(Node*);
    bool edgeExists(Node*, Node*);

    string toString();

private:
    struct Tuple {
        Node* node;
        Nodes* adjNodes;

        Tuple(Node* node) : node(node) {
            adjNodes = new Nodes;
        }
    };

    vector<Tuple*>* tuples;

    Tuple* getTupleByNode(Node*);
};

#endif // GRAPH_H
