#include <iostream>
#include <queue>

using namespace std;

#define MAX_VERTICES 100

class Graph {
private:
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];

public:
    Graph(int vertices) {
        numVertices = vertices;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; 
    }

    void BFS(int startVertex) {
        bool visited[MAX_VERTICES] = {false};
        queue<int> bfsQueue;

        visited[startVertex] = true;
        bfsQueue.push(startVertex);

        while (!bfsQueue.empty()) {
            int currentVertex = bfsQueue.front();
            cout << currentVertex << " ";
            bfsQueue.pop();

            for (int i = 0; i < numVertices; ++i) {
                if (adjMatrix[currentVertex][i] && !visited[i]) {
                    visited[i] = true;
                    bfsQueue.push(i);
                }
            }
        }
    }
};

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    Graph graph(numVertices);

    cout << "Enter the edges (source destination):" << endl;
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "Breadth First Traversal starting from vertex " << startVertex << ": ";
    graph.BFS(startVertex);

    return 0;
}
