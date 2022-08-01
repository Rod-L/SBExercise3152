#pragma once

class ListIGraph; // Forward reference for constructor

#include <cassert>
#include <iostream>
#include "IGraph.h"

class MatrixIGraph: public IGraph {
    int vertexesCount;
    int** matrix{};

    static int** intSquareMatrix(int sideSize);

    void clearMatrix();

    void copyFromOther(const MatrixIGraph& other);

    void copyFromListGraph(const ListIGraph& other);

    void resizeMatrix(int newVertexesCount);

public:

    explicit MatrixIGraph(int _vertexesCount);

    MatrixIGraph(const MatrixIGraph& other);

    explicit MatrixIGraph(const ListIGraph& other);

    MatrixIGraph& operator=(const MatrixIGraph& other);

    MatrixIGraph& operator=(const ListIGraph& other);

    ~MatrixIGraph() override;

    // Метод принимает вершины начала и конца ребра и добавляет ребро
    void AddEdge(int from, int to) override;

    // Метод должен считать текущее количество вершин
    int VerticesCount() const override;

    // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    void GetNextVertices(int vertex, std::vector<int> &vertices) const override;

    // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    void GetPrevVertices(int vertex, std::vector<int> &vertices) const override;

    void displayGraph() const override;
};

