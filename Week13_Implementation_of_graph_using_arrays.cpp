#include <iostream>
using namespace std;

class Graph {
    int n;                  // Number of vertices
    int adjMatrix[10][10];   // Adjacency matrix

public:
    // Constructor to initialize the graph
    Graph(int size) {
        n = size;
        // Initialize the adjacency matrix with all zeros
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Method to add an edge between two vertices u and v
    void addEdge(int u, int v) {
        adjMatrix[u][v] = 1;  // Add edge from u to v
        adjMatrix[v][u] = 1;  // For undirected graph, also add edge from v to u
    }

    // Method to display the adjacency matrix
    void displayGraph() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n, e, u, v;

    // Taking input for number of vertices
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Create a graph with 'n' vertices
    Graph g(n);

    // Taking input for number of edges
    cout << "Enter the number of edges: ";
    cin >> e;

    // Adding edges as per user input
    for (int i = 0; i < e; i++) {
        cout << "Enter edge (u v): ";
        cin >> u >> v;
        g.addEdge(u, v);  // Add the edge between vertices u and v
    }

    // Display the adjacency matrix
    g.displayGraph();

    return 0;
}
