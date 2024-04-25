#include <iostream>
#include <queue>

using namespace std;

#define MAX_VERTICES 100

struct Node {
    int data;
    Node* next;
};

class Graph {
private:
    int numVertices;
    Node* adjList[MAX_VERTICES];

public:
    Graph(int vertices) {
        numVertices = vertices;
        for (int i = 0; i < numVertices; ++i) {
            adjList[i] = nullptr;
        }
    }

    void addEdge(int src, int dest) {
        Node* newNode = new Node;
        newNode->data = dest;
        newNode->next = nullptr;

        newNode->next = adjList[src];
        adjList[src] = newNode;

        newNode = new Node;
        newNode->data = src;
        newNode->next = nullptr;
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
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

            Node* temp = adjList[currentVertex];
            while (temp != nullptr) {
                int adjacentVertex = temp->data;
                if (!visited[adjacentVertex]) {
                    visited[adjacentVertex] = true;
                    bfsQueue.push(adjacentVertex);
                }
                temp = temp->next;
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
