#include <iostream>

using namespace std;

int main() {
    long long int q;
    cin >> q;
    for(int i=0; i<q; i++)
    {
        long long int n;
        cin >> n;
        cout << ((n + 1) * n) + n + 2 << "\n";
    }
    return 0;
}