#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Node {
    int vertex;
    int distance;
};

struct CompareNodes {
    bool operator()(const Node& a, const Node& b) {
        return a.distance > b.distance;
    }
};

vector<int> dijkstra(vector<vector<pair<int, int> > >& graph, int source) {
    int numVertices = graph.size();
    vector<int> distances(numVertices, numeric_limits<int>::max());
    vector<bool> visited(numVertices, false);

    priority_queue<Node, vector<Node>, CompareNodes> pq;

    distances[source] = 0;
    pq.push(Node{source, 0}); // Use uniform initialization correctly

    while (!pq.empty()) {
        Node node = pq.top();
        pq.pop();
        int vertex = node.vertex;
        int distance = node.distance;

        if (visited[vertex]) {
            continue;
        }

        visited[vertex] = true;

        for (const auto& neighbor : graph[vertex]) {
            int neighborVertex = neighbor.first;
            int edgeWeight = neighbor.second;

            if (distance + edgeWeight < distances[neighborVertex]) {
                distances[neighborVertex] = distance + edgeWeight;
                pq.push(Node{neighborVertex, distances[neighborVertex]}); // Use uniform initialization correctly
            }
        }
    }

    return distances;
}

int main() {
    int numVertices = 5;
    vector<vector<pair<int, int> > > graph(numVertices); // Add space between consecutive angle brackets

    // Add edges to the graph
    graph[0].push_back(make_pair(1, 4));
    graph[0].push_back(make_pair(2, 1));
    graph[1].push_back(make_pair(3, 1));
    graph[2].push_back(make_pair(1, 2));
    graph[2].push_back(make_pair(3, 5));
    graph[3].push_back(make_pair(4, 3));

    vector<int> distances = dijkstra(graph, 0);

    cout << "Shortest distances from source 0:" << endl;
    for (int i = 0; i < numVertices; i++) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
// g++ -std=c++11 Q3.cpp -o Q3