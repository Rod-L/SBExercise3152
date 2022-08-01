#include <vector>
#include "MatrixIGraph.h"
#include "ListIGraph.h"

int** MatrixIGraph::intSquareMatrix(int sideSize) {
    int** matrix = new int*[sideSize];
    for (int i = 0; i < sideSize; ++i) {
        matrix[i] = new int[sideSize];
        for (int j = 0; j < sideSize; ++j) matrix[i][j] = 0;
    }
    return matrix;
}

void MatrixIGraph::clearMatrix() {
    for (int i = 0; i < vertexesCount; ++i) {
        for (int j = 0; j < vertexesCount; ++j) matrix[i][j] = 0;
    }
}

void MatrixIGraph::resizeMatrix(int newVertexesCount) {
    int** newMatrix = intSquareMatrix(newVertexesCount);
    for (int i = 0; i < vertexesCount; ++i) {
        for (int j = 0; j < vertexesCount; ++j) {
            newMatrix[i][j] = matrix[i][j];
        }
    }
    delete[] matrix;
    matrix = newMatrix;
    vertexesCount = newVertexesCount;
}

void MatrixIGraph::copyFromOther(const MatrixIGraph& other) {
    if (vertexesCount != other.vertexesCount) {
        delete[] matrix;
        matrix = intSquareMatrix(vertexesCount);
    }

    for (int i = 0; i < vertexesCount; ++i) {
        for (int j = 0; j < vertexesCount; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
    vertexesCount = other.vertexesCount;
}

void MatrixIGraph::copyFromListGraph(const ListIGraph& other) {
    int otherSize = other.VerticesCount();
    if (vertexesCount != otherSize) {
        delete[] matrix;
        matrix = intSquareMatrix(otherSize);
    } else {
        clearMatrix();
    }

    std::vector<int> connections;
    for (int i = 0; i < otherSize; ++i) {
        other.GetNextVertices(i, connections);
        for (int j : connections) ++matrix[i][j];
        connections.clear();
    }
    vertexesCount = otherSize;
}

MatrixIGraph::MatrixIGraph(int _vertexesCount): vertexesCount(_vertexesCount) {
    matrix = intSquareMatrix(vertexesCount);
}

MatrixIGraph::MatrixIGraph(const MatrixIGraph& other) {
    copyFromOther(other);
}

MatrixIGraph::MatrixIGraph(const ListIGraph& other) {
    copyFromListGraph(other);
}

MatrixIGraph& MatrixIGraph::operator=(const MatrixIGraph& other) {
    if (this == &other) return *this;
    copyFromOther(other);
    return *this;
}

MatrixIGraph& MatrixIGraph::operator=(const ListIGraph& other) {
    copyFromListGraph(other);
    return *this;
}

MatrixIGraph::~MatrixIGraph() {
    delete[] matrix;
}

void MatrixIGraph::AddEdge(int from, int to) {
    int maxVertexId = std::max(from, to);
    if (maxVertexId >= vertexesCount) resizeMatrix(maxVertexId + 1);
    ++matrix[from][to];
}

int MatrixIGraph::VerticesCount() const {
    return vertexesCount;
}

void MatrixIGraph::GetNextVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex < vertexesCount);
    for (int i = 0; i < vertexesCount; ++i) {
        if (matrix[vertex][i] > 0) vertices.push_back(i);
    }
}

void MatrixIGraph::GetPrevVertices(int vertex, std::vector<int> &vertices) const {
    assert(vertex < vertexesCount);
    for (int i = 0; i < vertexesCount; ++i) {
        if (matrix[i][vertex] > 0) vertices.push_back(i);
    }
}

void MatrixIGraph::displayGraph() const {
    for (int i = 0; i < vertexesCount; ++i) {
        for (int j = 0; j < vertexesCount; ++j) std::cout << matrix[i][j] << ' ';
        std::cout << std::endl;
    }
}