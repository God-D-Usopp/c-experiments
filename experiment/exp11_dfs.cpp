#include <iostream>
using namespace std;

#define MAX 100  

class Graph {
private:
    int adj[50][50]; 
    bool visited[50]; 
    int vertices;

public:
    Graph(int v) {
        vertices = v;
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
            for (int j = 0; j < vertices; j++) {
                adj[i][j] = 0;
            }
        }
    }
    void addEdge(int src, int dest) {
        adj[src][dest] = 1;
        adj[dest][src] = 1; 
    }
    void DFS(int vertex) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int i = 0; i < vertices; i++) {
            if (adj[vertex][i] == 1 && !visited[i]) {
                DFS(i);
            }
        }
    }
    void resetVisited() {
        for (int i = 0; i < vertices; i++) {
            visited[i] = false;
        }
    }
};
int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;

    Graph graph(v);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter each edge (source destination):\n";
    for (int i = 0; i < e; ++i) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    cout << "DFS traversal starting from vertex "<<start << ":";
    graph.DFS(start);
    cout << endl;

    return 0;
}