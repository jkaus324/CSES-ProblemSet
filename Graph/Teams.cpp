#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> getTeams(vector<vector<int>>& adj, int n) {
    vector<int> team(n, 0); 
    queue<int> q;

    for (int start = 0; start < n; start++) {
        if (team[start] == 0) {
            team[start] = 1; 
            q.push(start);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (team[v] == 0) {
                        team[v] = 3 - team[u];
                        q.push(v);
                    } else if (team[v] == team[u]) {
                        return {};
                    }
                }
            }
        }
    }

    return team; 
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--; 
        adj[a].push_back(b);
        adj[b].push_back(a); 
    }

    vector<int> team = getTeams(adj, n);

    if (team.empty()) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << team[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
