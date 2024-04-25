#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int v) : vertices(v), adjacencyMatrix(v, vector<int>(v, 0)) {}

    void addEdge(int v1, int v2) {
        adjacencyMatrix[v1][v2] = 1;
        adjacencyMatrix[v2][v1] = 1; 
    }

    void printAdjacencyMatrix() {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    cout << "Adjacency Matrix:" << endl;
    graph.printAdjacencyMatrix();

    return 0;
}
