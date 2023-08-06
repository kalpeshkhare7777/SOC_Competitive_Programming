#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int parent, vector<vector<int> >& adj, vector<bool>& visited, vector<int>& path, bool& found, int& start) {
    if (found) return;
    if (visited[node]) {
        if (path.size() > 2) {
            found = true;
            int count = 1;
            vector<int> cyclePath;
            for (int i = path.size() - 1; i >= 0; i--) {
                cyclePath.push_back(path[i]);
                count++;
                if (path[i] == node) {
                    start = path[i];
                    break;
                }
            }
            cout << count << endl;
            for (int i = cyclePath.size() - 1; i >= 0; i--) {
                cout << cyclePath[i];
                if (i > 0)
                    cout << " ";
            }
            cout << " " << start << endl;
        }
        return;
    }
    visited[node] = true;
    path.push_back(node);
    for (vector<int>::iterator it = adj[node].begin(); it != adj[node].end(); ++it) {
        int child = *it;
        if (child == parent) continue;
        dfs(child, node, adj, visited, path, found, start);
    }
    path.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(n + 1, false);
    bool found = false;
    int start = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> path;
            dfs(i, -1, adj, visited, path, found, start);
        }
    }

    if (!found)
        cout << "IMPOSSIBLE" << endl;

    return 0;
}
