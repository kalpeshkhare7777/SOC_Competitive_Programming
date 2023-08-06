#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

vector<int> v[1 << 14];
vector<int> ans;

void dfs(int x) {
    while (!v[x].empty()) {
        int nxt = v[x].back();
        v[x].pop_back();
        dfs(nxt);
        ans.push_back(nxt & 1);
    }
}

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "01\n";
        return 0;
    }

    for (int i = 0; i < (1 << (n - 1)); i++) {
        v[i].push_back((i << 1) & ((1 << (n - 1)) - 1));
        v[i].push_back((i << 1 | 1) & ((1 << (n - 1)) - 1));
    }

    dfs(0);

   
    reverse(ans.begin(), ans.end());

    for (int i = 0; i < n - 1; i++) {
        cout << 0;
    }

    for (int i : ans) {
        cout << i;
    }

    cout << "\n";

    return 0;
}
