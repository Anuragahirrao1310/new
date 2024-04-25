#include <iostream>
#include <vector>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int destination;
    int weight;

    Edge(int dest, int w) : destination(dest), weight(w) {}
};

// Function to add an edge to the adjacency list
void add_edge(int u, int v, int weight, vector<vector<Edge>>& adj) {
    adj[u].push_back(Edge(v, weight));
    adj[v].push_back(Edge(u, weight)); // Assuming undirected graph
}

const int INF = 1000000; // Represents infinity

// Function to find the vertex with the minimum key value
int minKey(const vector<int>& key, const vector<bool>& mstSet) {
    int min = INF, min_index;

    for (int v = 0; v < key.size(); ++v) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the minimum spanning tree
void printMST(const vector<int>& parent, const vector<vector<Edge>>& graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < parent.size(); ++i)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]].weight << endl;
}

// Function to implement Prim's algorithm to find minimum spanning tree
void primMST(const vector<vector<Edge>>& graph) {
    int V = graph.size();
    vector<int> parent(V); // Array to store the parent vertices of each vertex in MST
    vector<int> key(V);    // Array to store key values used to pick minimum weight edge
    vector<bool> mstSet(V, false); // Array to track vertices included in MST

    // Initialize all keys as infinite
    for (int i = 0; i < V; ++i) {
        key[i] = INF;
    }

    // Starting from vertex 0
    key[0] = 0;
    parent[0] = -1; // No parent of the starting vertex

    // Construct MST
    for (int count = 0; count < V - 1; ++count) {
        int u = minKey(key, mstSet);

        mstSet[u] = true;

        // Update key values of adjacent vertices of the picked vertex
        for (const Edge& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            if (!mstSet[v] && weight < key[v]) {
                parent[v] = u;
                key[v] = weight;
            }
        }
    }

    // Print the minimum spanning tree
    printMST(parent, graph);
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<Edge>> graph(V); // Adjacency list for the graph

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges and their weights (format: source destination weight):" << endl;
    for (int i = 0; i < e; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        add_edge(source, destination, weight, graph);
    }

    // Find and print the minimum spanning tree
    primMST(graph);

    return 0;
}
