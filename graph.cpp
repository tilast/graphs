#include "graph.h"
#include <algorithm>

Graph::Graph()
{
    tuples = new vector<Tuple*>;
}

Graph::~Graph()
{
}

void Graph::addNode(Node * node)
{
    tuples->push_back(new Tuple(node));
}

void Graph::removeNode(Node * node)
{
    if(nodeExists(node))
    {
        Tuple *t = getTupleByNode(node);
        Nodes* nodes = new Nodes(*(t->adjNodes));
        for(auto iter = nodes->begin(); iter != nodes->end(); ++iter)
        {
            removeEdge(node, *iter);
        }

        tuples->erase(std::remove(tuples->begin(), tuples->end(), t), tuples->end());
    }
}

void Graph::addEdge(Node * n1, Node * n2)
{
    if(!edgeExists(n1, n2))
    {
        Tuple *t1 = getTupleByNode(n1);
        Tuple *t2 = getTupleByNode(n2);

        t1->adjNodes->push_back(n2);
        t2->adjNodes->push_back(n1);
    }
}

void Graph::removeEdge(Node * n1, Node * n2)
{
    if(edgeExists(n1, n2))
    {
        Tuple *t1 = getTupleByNode(n1);
        Tuple *t2 = getTupleByNode(n2);

        Nodes* adjNodes1 = t1->adjNodes;
        Nodes* adjNodes2 = t2->adjNodes;

        adjNodes1->erase(std::remove(adjNodes1->begin(), adjNodes1->end(), n2), adjNodes1->end());
        adjNodes2->erase(std::remove(adjNodes2->begin(), adjNodes2->end(), n1), adjNodes2->end());

    }
}

Node *Graph::getNodeById(int id)
{
    for(auto iter = tuples->begin(); iter != tuples->end(); ++iter)
    {
        if((*iter)->node->getId() == id)
        {
            return (*iter)->node;
        }
    }

    return nullptr;
}

typename Graph::Nodes *Graph::getAdjNodes(Node * node)
{
    if(nodeExists(node))
    {
        Tuple *t1 = getTupleByNode(node);
        Nodes* copy = new Nodes(*(t1->adjNodes));

        return copy;
    }

    return new Nodes;
}

bool Graph::nodeExists(Node * node)
{
    for(auto iter = tuples->begin(); iter != tuples->end(); ++iter)
    {
        if((*iter)->node == node)
        {
            return true;
        }
    }

    return false;
}

bool Graph::edgeExists(Node * n1, Node * n2)
{
    if(nodeExists(n1) && nodeExists(n2))
    {
        Tuple *t1 = getTupleByNode(n1);
        for(auto iter = t1->adjNodes->begin(); iter != t1->adjNodes->end(); ++iter)
        {
            if(*iter == n2)
            {
                return true;
            }
        }

        return false;
    }

    return false;
}

string Graph::toString()
{
    string log = "";
    for(auto iter = tuples->begin(); iter != tuples->end(); ++iter)
    {
        log += "Node " + std::to_string((*iter)->node->getId()) + ": ";

        for(auto adjNode = (*iter)->adjNodes->begin(); adjNode != (*iter)->adjNodes->end(); ++adjNode)
        {
            log += std::to_string((*adjNode)->getId()) + " ";
        }

        log += "\n";
    }

    log += "\n";

    return log;
}

typename Graph::Tuple *Graph::getTupleByNode(Node * node)
{
    for(auto iter = tuples->begin(); iter != tuples->end(); ++iter)
    {
        if((*iter)->node == node)
        {
            return *iter;
        }
    }

    return nullptr;
}

