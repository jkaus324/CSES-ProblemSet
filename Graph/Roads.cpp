#include<iostream>
#include<vector>
using namespace std;

void dfs(int i, int parent, vector<int> &visit, vector<vector<int>> &adj) {
    visit[i] = visit[parent]; // Assign the same component id as parent
    for(auto x: adj[i]) {
        if(visit[x] == -1) {
            dfs(x, i, visit, adj);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n); // Adjacency list

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--; // Convert 1-indexed input to 0-indexed for adjacency list
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n, -1);
    vector<int> componentLeaders;

    for(int i = 0; i < n; i++) {
        if(visited[i] == -1) {
            visited[i] = i; // Assign component id as the current node
            dfs(i, i, visited, adj);
            componentLeaders.push_back(i); // Store the component leader
        }
    }

    int numComponents = componentLeaders.size();
    cout << numComponents - 1 << endl;

    for(int i = 0; i < numComponents - 1; i++) {
        cout << componentLeaders[i] + 1 << " " << componentLeaders[i + 1] + 1 << endl; // Output in 1-indexed format
    }

    return 0;
}
