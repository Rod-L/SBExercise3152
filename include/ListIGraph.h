#pragma once

class MatrixIGraph; // Forward reference for constructor

#include <unordered_set>
#include "IGraph.h"

struct Edge {
    int from;
    int to;

    // Hash function
    std::size_t hash() const;
    // Equal Function
    bool operator==(const Edge& other) const;
};

// Register hash function for 'Edge' structure.
namespace std {
    template <>
    class hash<Edge> {
    public:
        size_t operator()(const Edge& e) const {
            return e.hash();
        }
    };
}

class ListIGraph: public IGraph {
    std::unordered_set<Edge> edges;
    std::unordered_set<int> verticesList;

    void copyFromMatrixGraph(const MatrixIGraph& other);

public:
    ~ListIGraph() override = default;

    ListIGraph() = default;

    ListIGraph(ListIGraph& other);

    explicit ListIGraph(MatrixIGraph& other);

    ListIGraph& operator=(const ListIGraph& other);

    ListIGraph& operator=(const MatrixIGraph& other);

    // Метод принимает вершины начала и конца ребра и добавляет ребро
    void AddEdge(int from, int to) override;

    // Метод должен считать текущее количество вершин
    int VerticesCount() const override;

    // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    void GetNextVertices (int vertex, std::vector<int> &vertices) const override;

    // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

    void displayGraph() const override;
};
