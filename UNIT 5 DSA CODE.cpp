\#include \<iostream>
\#include \<vector>
\#include \<queue>
\#include \<climits>
\#include \<algorithm>
using namespace std;

int main() {
&#x20;   int n = 5;

&#x20;   vector\<vector\<pair\<int, int>>> graph(n);

&#x20;   auto addRoute = [&]\(int u, int v, int w) {
&#x20;       graph[u].push_back({v, w});
&#x20;       graph[v].push_back({u, w});
&#x20;   };

&#x20;   addRoute(0, 1, 4);
&#x20;   addRoute(0, 2, 2);
&#x20;   addRoute(1, 2, 1);
&#x20;   addRoute(1, 3, 5);
&#x20;   addRoute(2, 3, 8);
&#x20;   addRoute(2, 4, 10);
&#x20;   addRoute(3, 4, 2);

&#x20;   vector\<string> names = {
&#x20;       "Current Location",
&#x20;       "Station A",
&#x20;       "Station B",
&#x20;       "Station C",
&#x20;       "Selected Station"
&#x20;   };

&#x20;   int source = 0, destination = 4;

&#x20;   vector\<int> dist(n, INT_MAX);
&#x20;   vector\<int> parent(n, -1);

&#x20;   priority_queue\<pair\<int, int>,
&#x20;       vector\<pair\<int, int>>,
&#x20;       greater\<pair\<int, int>>> pq;

&#x20;   dist[source] = 0;
&#x20;   pq.push({0, source});

&#x20;   while (!pq.empty()) {
&#x20;       int d = pq.top().first;
&#x20;       int u = pq.top().second;
&#x20;       pq.pop();

&#x20;       if (d != dist[u])
&#x20;           continue;

&#x20;       for (auto edge : graph[u]) {
&#x20;           int v = edge.first;
&#x20;           int weight = edge.second;

&#x20;           if (dist[u] + weight < dist[v]) {
&#x20;               dist[v] = dist[u] + weight;
&#x20;               parent[v] = u;
&#x20;               pq.push({dist[v], v});
&#x20;           }
&#x20;       }
&#x20;   }

&#x20;   vector\<int> path;

&#x20;   for (int v = destination; v != -1;
&#x20;        v = parent[v]) {
&#x20;       path.push_back(v);
&#x20;   }

&#x20;   reverse(path.begin(), path.end());

&#x20;   cout << "EV CHARGING STATION ROUTE FINDER\n";
&#x20;   cout << "--------------------------------\n";
&#x20;   cout << "Starting point : "
&#x20;        << names[source] << "\n";
&#x20;   cout << "Destination    : "
&#x20;        << names[destination] << "\n";
&#x20;   cout << "Shortest route : ";

&#x20;   for (int i = 0; i < path.size(); i++) {
&#x20;       cout << names[path[i]];

&#x20;       if (i + 1 < path.size())
&#x20;           cout << " -> ";
&#x20;   }

&#x20;   cout << "\nMinimum distance: "
&#x20;        << dist[destination] << " km\n";

&#x20;   return 0;
} give output
