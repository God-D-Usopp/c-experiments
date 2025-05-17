#include <iostream>

using namespace std;

void dijkstra(int graph[][10], int vertices, int source) {
    int dist[vertices];  // To store the shortest distance from the source
    bool visited[vertices];  // To track whether a vertex has been visited

    // Initialize distances to a large value and visited to false
    for (int i = 0; i < vertices; i++) {
        dist[i] = 1000000;  // We use a large number to represent infinity
        visited[i] = false;
    }

    dist[source] = 0;  // The distance from the source to itself is 0

    // Process all vertices
    for (int count = 0; count < vertices - 1; count++) {
        int minDist = 1000000;
        int u = -1;

        // Find the unvisited vertex with the smallest distance
        for (int i = 0; i < vertices; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        // Mark this vertex as visited
        visited[u] = true;

        // Update the distances for the neighbors of the selected vertex
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] != 0 && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the shortest distance from the source to each vertex
    cout << "Vertex\tDistance from Source " << source << endl;
    for (int i = 0; i < vertices; i++) {
        if (dist[i] == 1000000) {  // If the distance is still infinity, it means not reachable
            cout << i << "\tINF" << endl;
        } else {
            cout << i << "\t" << dist[i] << endl;
        }
    }
}

int main() {
    int vertices, edges;

    // Input the number of vertices and edges
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;

    // Initialize the graph as an adjacency matrix
    int graph[10][10] = {0};

    // Input the edges and their weights
    cout << "Enter the edges (u, v, weight): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph[u][v] = weight;  // Directed edge from u to v
        graph[v][u] = weight;  
    }
    int source;
    cout << "Enter source vertex: ";
    cin >> source;
    dijkstra(graph, vertices, source);

    return 0;
}
