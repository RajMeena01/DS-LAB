#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(vector<vector<int>>& graph, int startVertex) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);

    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        cout << vertex << " ";

        for (int neighbor : graph[vertex]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
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

    cout<<endl<< "Breadth-First Search Traversal: ";
    BFS(graph, 0);
    cout<<endl;
    return 0;
}