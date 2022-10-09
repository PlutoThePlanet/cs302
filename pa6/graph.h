#ifndef GRAPH_H
#define GRAPH_H

template<class FirstItem> // how to template two item types
class Graph{
private:
    int vertices;
    int edges;
public: 
    int getNumVertices() const;
    int getNumEdges() const;
    // int getEdgeWeight(Edge e) const;
    bool add(/*parameters*/);
    bool remove(/*parameters*/);
    void depthFirstTraversal(/*parameters*/);
    void breadthFirstTraversal(/*parameters*/);
};

#include "graph.cpp"
#endif