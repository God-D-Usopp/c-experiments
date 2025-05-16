#include <iostream>
using namespace std;

#define MAX 100  

class Graph {
private:
    int adj[50][50]; 
    int vertices;

public:
    Graph(int v) {
        vertices = v;
        for (int i = 0; i < vertices; ++i)
            for (int j = 0; j < vertices; ++j)
                adj[i][j] = 0;
    }
    void addEdge(int src, int dest) {
        adj[src][dest] = 1;
        adj[dest][src] = 1; // Remove for directed graph
    }

    // Perform BFS traversal
    void BFS(int start) {
        bool visited[50] = {false}; // Track visited nodes
        int queue[50];              // Array as a queue
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        cout << "BFS Traversal starting from vertex " << start << ": ";

        while (front < rear) {
            int current = queue[front++];
            cout << current << " ";

            for (int i = 0; i < vertices; ++i) {
                if (adj[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i;
                }
            }
        }

        cout << endl;
    }
};

// Main function
int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;

    Graph g(v);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter each edge (source destination):\n";
    for (int i = 0; i < e; ++i) {
        int src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }

    int start;
    cout << "Enter starting vertex for BFS: ";
    cin >> start;

    g.BFS(start);

    return 0;
}