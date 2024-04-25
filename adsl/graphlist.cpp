#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    int vertices;
    list<int>* adjacencyList;

public:
    Graph(int v) : vertices(v) {
        adjacencyList = new list<int>[vertices];
    }

    void addEdge(int v1, int v2) {
        adjacencyList[v1].push_back(v2);
        adjacencyList[v2].push_back(v1); 
    }

    void printAdjacencyList() {
        for (int i = 0; i < vertices; ++i) {
            cout << "Vertex " << i << ": ";
            for (const auto& neighbor : adjacencyList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    ~Graph() {
        delete[] adjacencyList;
    }
};

int main() {
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);

    cout << "Adjacency List:" << endl;
    graph.printAdjacencyList();

    return 0;
}
