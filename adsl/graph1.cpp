#include <iostream>

using namespace std;

const int MAX_VERTICES = 100;

class Graph {
private:
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];

public:
    Graph(int vertices) {
        numVertices = vertices;
        // Initialize all elements of adjacency matrix to 0
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest) {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            adjMatrix[src][dest] = 1;
            adjMatrix[dest][src] = 1; // Assuming undirected graph
        } else {
            cout << "Invalid vertices!" << endl;
        }
    }

    void display() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    Graph graph(vertices);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    graph.display();

    return 0;
}
