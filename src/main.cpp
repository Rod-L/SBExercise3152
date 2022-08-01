#include <iostream>

#include "ListIGraph.h"
#include "MatrixIGraph.h"

int main() {
    std::cout << "Creating 4x4 matrix graph." << std::endl;
    MatrixIGraph m_graph(4);

    std::cout << "Inserting edge from 1 to 2." << std::endl;
    m_graph.AddEdge(1, 2);
    std::cout << "Inserting edge from 2 to 1." << std::endl;
    m_graph.AddEdge(2, 1);
    std::cout << "Displaying matrix graph:" << std::endl;
    m_graph.displayGraph();
    std::cout << std::endl;

    std::cout << "Creating list graph based on matrix graph." << std::endl;
    ListIGraph l_graph(m_graph);
    std::cout << "Inserting edge from 0 to 1." << std::endl;
    l_graph.AddEdge(0, 1);
    std::cout << "Displaying list graph:" << std::endl;
    l_graph.displayGraph();
    std::cout << std::endl;

    std::cout << "Using '=' operator to apply list graph to matrix graph:" << std::endl;
    m_graph = l_graph;
    m_graph.displayGraph();
    std::cout << std::endl;

    std::cout << "Inserting edge between non existing vertexes (from 4 to 6), "
                 "graph will be extended automatically." << std::endl;
    m_graph.AddEdge(4, 6);
    m_graph.displayGraph();
    std::cout << std::endl;

    std::cout << "Using '=' operator to apply matrix graph back to list graph:" << std::endl;
    l_graph = m_graph;
    l_graph.displayGraph();
    std::cout << std::endl;

    std::cout << "And back again:" << std::endl;
    m_graph = l_graph;
    m_graph.displayGraph();
}
