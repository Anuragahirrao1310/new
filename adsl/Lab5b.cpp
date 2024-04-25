#include <iostream>

using namespace std;

const int MAX_VERTICES = 100;

// Function to add an edge to the graph
void addEdge(int adj[][MAX_VERTICES], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Function to print the adjacency list representation of graph
void printGraph(int adj[][MAX_VERTICES], int V) {
    for (int v = 0; v < V; ++v) {
        cout << "Adjacency list of vertex " << v << "\nhead ";
        for (int u = 0; u < V; ++u) {
            if (adj[v][u])
                cout << "-> " << u;
        }
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Create an array to represent adjacency list
    int adj[MAX_VERTICES][MAX_VERTICES] = {0};

    // Input edges
    cout << "Enter edges (source destination): \n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(adj, u, v);
    }

    // Print adjacency list representation of graph
    printGraph(adj, V);

    return 0;
}
