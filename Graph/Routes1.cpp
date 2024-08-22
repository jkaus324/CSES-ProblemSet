#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const long long INF = numeric_limits<long long>::max();

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> adj(n + 1); // Adjacency list

    for (int i = 0; i < m; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    vector<long long> dist(n + 1, INF);
    dist[1] = 0; // Starting point Syrjälä
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();

        // If the distance to u is greater than what's recorded, continue
        if (current_dist > dist[u]) {
            continue;
        }

        for (auto [v, length] : adj[u]) {
            if (dist[u] + length < dist[v]) {
                dist[v] = dist[u] + length;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
