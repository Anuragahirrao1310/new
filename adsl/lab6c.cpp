#include <iostream>
#include <stack>

using namespace std;

const int MAX_VERTICES = 100;

// Function to perform Depth-First Search (DFS)
void DFS(int graph[][MAX_VERTICES], int V, int start) {
    bool visited[MAX_VERTICES] = {false}; // Array to keep track of visited vertices
    stack<int> stk; // Stack for DFS

    visited[start] = true; // Mark the start vertex as visited
    stk.push(start); // Push the start vertex onto the stack

    cout << "DFS Traversal starting from vertex " << start << ": ";

    while (!stk.empty()) {
        int current = stk.top();
        stk.pop();
        cout << current << " ";

        // Explore all adjacent vertices of current vertex
        for (int i = 0; i < V; ++i) {
            if (graph[current][i] && !visited[i]) {
                visited[i] = true;
                stk.push(i);
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
    cout << "Enter the starting vertex for DFS traversal: ";
    cin >> startVertex;

    DFS(graph, V, startVertex);

    return 0;
}
