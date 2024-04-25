#include<iostream>
#include<vector>
using namespace std;

void displayMatrix(const vector<vector<int>>& Arr) {
    int i, j;
    cout << "The Adjacency Matrix is : " << endl;
    cout << "  ";
    for (j = 0; j < Arr.size(); j++) {
        cout << j << " ";
    }
    cout << endl;
    for (i = 0; i < Arr.size(); i++) {
        cout << i << " ";
        for (j = 0; j < Arr.size(); j++) {
            cout << Arr[i][j] << " ";
        }
        cout << endl;
    }
}


void add_edge(int u, int v, vector<vector<int>>& Arr) { 
    Arr[u][v] = 1;
    Arr[v][u] = 1;
}

int main() {
    int v;
    cout << "Enter the number of vertices: ";
    cin >> v;
    vector<vector<int>> Arr(v, vector<int>(v,0));
    int e;
    cout << "Enter the number of edges: ";
    cin >> e;
    cout << "Enter the edges (format: source destination):" << endl;
    for(int i = 1; i <= e; i++) {
        int source, destination;
        cin >> source;
        cin >> destination;
        add_edge(source, destination, Arr);
    }
    displayMatrix(Arr);
    return 0;
}