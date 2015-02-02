#ifndef NODE_H
#define NODE_H

#include <string>

using std::string;

class Node
{
public:
    Node(string);
    virtual ~Node();

    int getId();
    string getValue();

    static int nextId;

private:
    int id;
    string value;
};

#endif // NODE_H
