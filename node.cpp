#include "node.h"

int Node::nextId = 0;

Node::Node(string value) : id(nextId++), value(value)
{
}

Node::~Node()
{
}

int Node::getId()
{
    return id;
}

string Node::getValue()
{
    return value;
}

