#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    long long total_edges = (static_cast<long long>(n) * (n - 1)) / 2;

    if (m < (n - 1) || m > total_edges)
        cout << "NO";
    else if (n == 1)
        cout << (k > 1 ? "YES" : "NO");
    else if (m == total_edges)
        cout << (k > 2 ? "YES" : "NO");
    else
        cout << (k > 3 ? "YES" : "NO");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
        cout << '\n';
    }

    return 0;
}
