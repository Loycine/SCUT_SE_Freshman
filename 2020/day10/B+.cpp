#include <bits/stdc++.h>

using namespace std;

const int MxN = int(2e5);
const int INF = int(1e9)+10;
int n, q, A[MxN+1] ,B[MxN+1], e[2*MxN+1];
multiset<int> K[MxN+1];

void update(int i) {
    int k = i + MxN;
    if (K[i].size() == 0) {
        e[k] = INF;
    } else {
        auto y = K[i].end();
        y--;
        e[k] = *y;
    }
    for (; k > 1; k >>= 1) {
        e[k>>1] = min(e[k], e[k^1]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        cin >> B[i];
        B[i]--;
        K[B[i]].insert(A[i]);
    }
    for (int i = 0; i < MxN; i++) {
        if (K[i].size() == 0) {
            e[i+MxN] = INF;
        } else {
            auto y = K[i].end();
            y--;
            e[i+MxN] = *y;
        }
    }
    for (int i = MxN - 1; i > 0; i--) {
        int a = INF, b = INF;
        if (e[i<<1] != 0) a = e[i<<1];
        if (e[i<<1|1] != 0) b = e[i<<1|1];
        e[i] = min(a, b);
    }
    for (int i = 0; i < q; i++) {
        int c, d;
        cin >> c >> d;
        c--;
        d--;
        K[B[c]].erase(K[B[c]].find(A[c]));
        update(B[c]);
        K[d].insert(A[c]);
        B[c] = d;
        update(d);
        cout << e[1] << "\n";
    }
}
