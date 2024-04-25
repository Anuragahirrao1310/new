#include <iostream>
#include <queue>

using namespace std;

const int MAX_VERTICES = 100;

// Function to perform Breadth-First Search (BFS)
void BFS(int graph[][MAX_VERTICES], int V, int start) {
    bool visited[MAX_VERTICES] = {false}; // Array to keep track of visited vertices
    queue<int> q; // Queue for BFS

    visited[start] = true; // Mark the start vertex as visited
    q.push(start); // Enqueue the start vertex

    cout << "BFS Traversal starting from vertex " << start << ": ";
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Explore all adjacent vertices of current vertex
        for (int i = 0; i < V; ++i) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    int graph[MAX_VERTICES][MAX_VERTICES] = {0}; // Adjacency matrix to represent the graph

    cout << "Enter edges (source destination): \n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1; // Assuming it's an undirected graph
        graph[v][u] = 1;
    }

    int startVertex;
    cout << "Enter the starting vertex for BFS traversal: ";
    cin >> startVertex;

    BFS(graph, V, startVertex);

    return 0;
}
