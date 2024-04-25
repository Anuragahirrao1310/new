#include <iostream>
#include <list>
#include <queue>

using namespace std;

// Class to represent a graph using adjacency list
class Graph {
    int V; // Number of vertices
    list<int> *adj; // Pointer to an array containing adjacency lists

public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Function to perform Breadth-First Search (BFS)
    void BFS(int start) {
        bool *visited = new bool[V]; // Array to keep track of visited vertices
        for (int i = 0; i < V; ++i)
            visited[i] = false;

        queue<int> q; // Queue for BFS

        visited[start] = true; // Mark the start vertex as visited
        q.push(start); // Enqueue the start vertex

        cout << "BFS Traversal starting from vertex " << start << ": ";

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            // Explore all adjacent vertices of current vertex
            for (auto it = adj[current].begin(); it != adj[current].end(); ++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    q.push(*it);
                }
            }
        }
        cout << endl;

        delete[] visited;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph graph(V); // Create a graph with V vertices

    cout << "Enter edges (source destination): \n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS traversal: ";
    cin >> startVertex;

    graph.BFS(startVertex);

    return 0;
}
