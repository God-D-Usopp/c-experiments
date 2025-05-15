#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjList;
    vector<bool> visited;

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjList.resize(v);
        visited.resize(v, false);
    }

    // Function to add an edge to the graph
    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); // Remove this line for a directed graph
    }

    // DFS traversal
    void DFS(int vertex) {
        visited[vertex] = true;
        cout << vertex << " ";

        for (int neighbor : adjList[vertex]) {
            if (!visited[neighbor]) {
                DFS(neighbor);
            }
        }
    }

    // Reset visited for repeated traversals
    void resetVisited() {
        fill(visited.begin(), visited.end(), false);
    }
};

int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;

    Graph graph(v);

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter each edge (source and destination):\n";
    for (int i = 0; i < e; ++i) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    int start;
    cout << "Enter starting vertex for DFS: ";
    cin >> start;

    cout << "DFS Traversal starting from vertex " << start << ": ";
    graph.DFS(start);
    cout << endl;

    return 0;
}