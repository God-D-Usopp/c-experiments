#include <iostream>

using namespace std;

const int MAX = 100;

// Function to find the vertex with minimum key value
int minKey(int key[], bool mstSet[], int V) {
    int min = 99999, min_index;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the MST
void printMST(int parent[], int graph[MAX][MAX], int V) {
    cout << "\nMinimum Spanning Tree (Prim's Algorithm):\n";
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
    }
}

// Prim's Algorithm
void primMST(int graph[MAX][MAX], int V) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];

    for (int i = 0; i < V; i++) {
        key[i] = 99999;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

// Main function
int main() {
    int V, E;
    int graph[MAX][MAX] = {0};

    cout << "Enter the number of vertices: ";
    cin >> V;

    cout << "Enter the number of edges: ";
    cin >> E;

    cout << "Enter the edges (u v weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // Because the graph is undirected
    }

    primMST(graph, V);

    return 0;
}
