#include <iostream>
using namespace std;

class Graph {
    int adj[10][10];
    int vertices;

public:
    Graph(int v) {
        vertices = v;

        // Initialize matrix with 0
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < vertices; j++) {
                adj[i][j] = 0;
            }
        }
    }

    // Add directed edge
    void addEdge(int u, int v) {
        adj[u][v] = 1;   // Only one direction
    }

    // Display adjacency matrix
    void display() {
        cout << "Adjacency Matrix (Directed Graph):\n";
        for(int i = 0; i < vertices; i++) {
            for(int j = 0; j < vertices; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;

    Graph g(v);

    cout << "Enter number of edges: ";
    cin >> e;

    int u, v1;
    cout << "Enter edges (u -> v):\n";
    for(int i = 0; i < e; i++) {
        cin >> u >> v1;
        g.addEdge(u, v1);
    }

    g.display();

    return 0;
}