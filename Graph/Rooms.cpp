#include <iostream>
#include <vector>
using namespace std;

void dfs(int x, int y, vector<vector<char>> &map, vector<vector<bool>> &visited, int n, int m) {
    if (x < 0 || x >= n || y < 0 || y >= m || map[x][y] == '#' || visited[x][y])
        return;
    
    visited[x][y] = true;

    // Move in all four possible directions
    dfs(x - 1, y, map, visited, n, m); // up
    dfs(x + 1, y, map, visited, n, m); // down
    dfs(x, y - 1, map, visited, n, m); // left
    dfs(x, y + 1, map, visited, n, m); // right
}

int countRooms(vector<vector<char>> &map, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int roomCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '.' && !visited[i][j]) {
                // Found a new room, perform DFS
                dfs(i, j, map, visited, n, m);
                roomCount++;
            }
        }
    }

    return roomCount;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int result = countRooms(map, n, m);
    cout << result << endl;

    return 0;
}
