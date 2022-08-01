#include <vector>
#include "ListIGraph.h"
#include "MatrixIGraph.h"

//// Edge structure

std::size_t Edge::hash() const {
    return static_cast<std::size_t>(std::hash<int>()(this->from)) + (static_cast<std::size_t>(std::hash<int>()(this->to)) << 32);
}

bool Edge::operator==(const Edge& other) const {
    return (from == other.from && to == other.to);
}

//// ListIGraph class

void ListIGraph::copyFromMatrixGraph(const MatrixIGraph& other) {
    edges.clear();
    verticesList.clear();

    int otherSize = other.VerticesCount();
    std::vector<int> connections;
    for (int i = 0; i < otherSize; ++i) {
        other.GetNextVertices(i, connections);
        for (int j : connections) ListIGraph::AddEdge(i, j);
        connections.clear();
    }
}

ListIGraph::ListIGraph(ListIGraph& other) {
    edges = other.edges;
    verticesList = other.verticesList;
}

ListIGraph::ListIGraph(MatrixIGraph& other) {
    copyFromMatrixGraph(other);
}

ListIGraph& ListIGraph::operator=(const ListIGraph& other) {
    if (this == &other) return *this;
    edges = other.edges;
    verticesList = other.verticesList;
    return *this;
}

ListIGraph& ListIGraph::operator=(const MatrixIGraph& other) {
    copyFromMatrixGraph(other);
    return *this;
}

void ListIGraph::AddEdge(int from, int to) {
    Edge newEdge{.from = from, .to = to};
    if (edges.find(newEdge) != edges.end()) return;

    if (verticesList.find(from) == verticesList.end()) verticesList.insert(from);
    if (verticesList.find(to) == verticesList.end()) verticesList.insert(to);
    edges.insert(newEdge);
}

int ListIGraph::VerticesCount() const {
    int maxVertexId = 0;
    for (int v : verticesList) maxVertexId = std::max(maxVertexId, v);
    return maxVertexId + 1;
}

void ListIGraph::GetNextVertices (int vertex, std::vector<int> &vertices) const {
    for (auto& edge : edges) {
        if (edge.from == vertex) vertices.push_back(edge.to);
    }
}

void ListIGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    for (auto& edge : edges) {
        if (edge.to == vertex) vertices.push_back(edge.from);
    }
}

void ListIGraph::displayGraph() const {
    std::cout << "Vertexes: ";
    for (int v : verticesList) std::cout << v << ' ';
    std::cout << std::endl;

    std::cout << "Edges: ";
    for (auto& edge : edges) std::cout << edge.from << "->" << edge.to << ' ';
    std::cout << std::endl;
}