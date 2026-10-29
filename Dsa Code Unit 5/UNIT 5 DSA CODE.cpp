
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n = 5;

    vector<vector<pair<int, int>>> graph(n);

    auto addRoute = [&](int u, int v, int w) {
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    };

    addRoute(0, 1, 4);
    addRoute(0, 2, 2);
    addRoute(1, 2, 1);
    addRoute(1, 3, 5);
    addRoute(2, 3, 8);
    addRoute(2, 4, 10);
    addRoute(3, 4, 2);

    vector<string> names = {
        "Current Location",
        "Station A",
        "Station B",
        "Station C",
        "Selected Station"
    };

    int source = 0, destination = 4;

    vector<int> dist(n, INT_MAX);
    vector<int> parent(n, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u])
            continue;

        for (auto edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    vector<int> path;

    for (int v = destination; v != -1;
         v = parent[v]) {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    cout << "EV CHARGING STATION ROUTE FINDER\n";
    cout << "--------------------------------\n";

    cout << "Starting point : "
         << names[source] << "\n";

    cout << "Destination    : "
         << names[destination] << "\n";

    cout << "Shortest route : ";

    for (int i = 0; i < path.size(); i++) {
        cout << names[path[i]];

        if (i + 1 < path.size())
            cout << " -> ";
    }

    cout << "\nMinimum distance: "
         << dist[destination] << " km\n";

    return 0;
}
