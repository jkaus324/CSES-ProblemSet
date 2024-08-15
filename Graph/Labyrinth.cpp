#include <bits/stdc++.h>
using namespace std;

string findPath(vector<vector<char>> &map, int ax, int ay, int bx, int by) {
    int n = map.size();
    int m = map[0].size();
    vector<vector<bool>> visit(n, vector<bool>(m, false));

    queue<pair<int, int>> q;
    vector<vector<char>> direction(n, vector<char>(m, 0));
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    string dir = "DRUL"; // Down, Right, Up, Left

    q.push({ax, ay});
    visit[ax][ay] = true;

    while (!q.empty()) {
        auto z = q.front();
        auto x = z.first;
        auto y = z.second;
        q.pop();

        if (x == bx && y == by) {
            string path;
            while (x != ax || y != ay) {
                char d = direction[x][y];
                path += d;
                int idx = dir.find(d);
                x -= dx[idx];
                y -= dy[idx];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visit[nx][ny] && map[nx][ny] != '#') {
                q.push({nx, ny});
                visit[nx][ny] = true;
                direction[nx][ny] = dir[i]; // Store the direction taken to reach this cell
            }
        }
    }

    return ""; // No path found
}

int main() {
    int n, m;
    cin >> n >> m;
    int ax, ay, bx, by;
    vector<vector<char>> map(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 'A') {
                ax = i, ay = j;
            } else if (map[i][j] == 'B') {
                bx = i, by = j;
            }
        }
    }

    string result = findPath(map, ax, ay, bx, by);
    if (result.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << result.length() << endl;
        cout << result << endl;
    }

    return 0;
}
