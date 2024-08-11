#include <iostream>
#include <vector>
using namespace std;
void DFS(vector<vector<int>>& graph, int vertex, vector<bool>& visited) {
    visited[vertex] = true;
    cout << vertex << " ";

    for (int neighbor : graph[vertex]) {
        if (!visited[neighbor]) {
            DFS(graph, neighbor, visited);
        }
    }
}
int main() {
    int numVertices = 5;
    vector<vector<int>> graph(numVertices);
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[1].push_back(4);
    vector<bool> visited(numVertices, false);
    cout << "Depth-First Search Traversal: ";
    DFS(graph, 0, visited);
    cout<<endl<<endl;
    return 0;
}