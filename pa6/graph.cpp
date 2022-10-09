#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "graph.h"
#include "edge.h"

template<class FirstItem>
int Graph<FirstItem>::getNumVertices() const{
    return vertices;
}

template<class FirstItem>
int Graph<FirstItem>::getNumEdges() const{
    return edges;
}

/*template<class FirstItem>
int Graph<FirstItem>::getEdgeWeight(Edge edge) const{
    return edge.weight;
}*/

template<class FirstItem>
bool Graph<FirstItem>::add(){

}

template<class FirstItem>
bool Graph<FirstItem>::remove(){

}

template<class FirstItem>
void Graph<FirstItem>::depthFirstTraversal(){

}

template<class FirstItem>
void Graph<FirstItem>::breadthFirstTraversal(){

}

#endif