#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_VALUE = 1000000; // Maximum value to represent infinity

// Function to add an edge to the adjacency matrix
void add_edge(int u, int v, int weight, vector<vector<pair<int, int>>>& adj) {
    adj[u].push_back(make_pair(v, weight));
}

// Function to implement Dijkstra's algorithm to find shortest path from source to destination
void dijkstra(vector<vector<pair<int, int>>>& graph, int src, int dest) {
    int V = graph.size(); // Number of vertices
    vector<int> dist(V, MAX_VALUE); // Array to store the shortest distance from source to each vertex
    vector<int> parent(V, -1); // Array to store the parent vertex in the shortest path
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Priority queue for Dijkstra's algorithm

    // Distance of source vertex from itself is always 0
    dist[src] = 0;
    pq.push(make_pair(0, src));

    // Dijkstra's algorithm
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (u == dest)
            break; // Stop the algorithm if the destination vertex is reached

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    // If destination vertex is not reachable from the source
    if (dist[dest] == MAX_VALUE) {
        cout << "Destination vertex is not reachable from the source." << endl;
        return;
    }

    // Print the shortest path from source to destination
    cout << "Shortest Path from " << src << " to " << dest << ": ";
    int vertex = dest;
    vector<int> path;
    while (vertex != -1) {
        path.push_back(vertex);
        vertex = parent[vertex];
    }
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << path[i];
        if (i > 0)
            cout << " -> ";
    }
    cout << "\nShortest Distance: " << dist[dest] << endl;
}

int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;
    vector<vector<pair<int, int>>> Arr(v); // Adjacency list for the graph

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges and their weights (format: source destination weight):" << endl;
    for(int i = 1; i <= e; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        add_edge(source, destination, weight, Arr);
    }

    int source, dest;
    cout << "Enter the source vertex: ";
    cin >> source;
    cout << "Enter the destination vertex: ";
    cin >> dest;

    dijkstra(Arr, source, dest);

    return 0;
}
