#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ii pair<int, int>
#define mp make_pair
#define f first
#define s second

int n, m;
char A[1000][1000];
char previousStep[1000][1000];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string stepDir = "URDL";

bool isValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && A[x][y] != '#');
}

void bfs(ii begin, ii end) {
    queue<ii> q;
    q.push(begin);
    while (!q.empty()) {
        ii u = q.front();
        q.pop();
        if (u == end) break;
        for (int i = 0; i < 4; i++) {
            int x = u.f + dx[i];
            int y = u.s + dy[i];
            if (isValid(x, y) && previousStep[x][y] == 0) {
                previousStep[x][y] = stepDir[i];
                q.push(mp(x, y));
            }
        }
    }
}

int main() {
    cin >> n >> m;
    ii begin, end;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'A') {
                begin = mp(i, j);
            } else if (A[i][j] == 'B') {
                end = mp(i, j);
            }
        }
    }

    previousStep[begin.f][begin.s] = 'X'; // Mark the starting point
    bfs(begin, end);

    if (previousStep[end.f][end.s] != 0) {
        cout << "YES" << endl;
        vector<char> steps;
        ii cur = end;
        while (cur != begin) {
            steps.push_back(previousStep[cur.f][cur.s]);
            int idx = stepDir.find(previousStep[cur.f][cur.s]);
            cur = mp(cur.f - dx[idx], cur.s - dy[idx]);
        }
        int stepCount = steps.size();
        cout << stepCount << endl;
        for (int i = stepCount - 1; i >= 0; i--) {
            cout << steps[i];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
