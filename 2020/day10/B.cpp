#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int n,q;
multiset<int> st_global;

const int maxn = 2e5 + 5;
int value[maxn];
int belongs[maxn];
multiset<int> gardens[maxn];
set<int> records;


int main() {
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; i++) {
        scanf("%d%d", &value[i], &belongs[i]);
        gardens[belongs[i]].insert(value[i]);
        records.insert(belongs[i]);
    }

    for(auto x:records) {
        st_global.insert(-*gardens[x].rbegin());
    }

    int child_id, garden_id;
    for(int i=0; i<q; i++)
    {
        scanf("%d%d", &child_id, &garden_id);
        int from = belongs[child_id];
        int to = garden_id;

        st_global.erase(st_global.find(-*gardens[from].rbegin()));
        gardens[from].erase(gardens[from].find(value[child_id]));
        if(!gardens[from].empty()){
            st_global.insert(-*gardens[from].rbegin());
        }

        if(!gardens[to].empty()) {
            st_global.erase(st_global.find(-*gardens[to].rbegin()));
        }
        gardens[to].insert(value[child_id]);
        st_global.insert(-*gardens[to].rbegin());

        belongs[child_id] = garden_id;

        int ans = -*st_global.rbegin();
        printf("%d\n", ans);
    }
}