#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cstring>
#include <unordered_set>
#define MAX 50005
#define MAX_NUM 1000006
using namespace std;

map<int, bool> dices[MAX];
vector<int> d;
int n;
int d_end;
int cx[MAX_NUM], cy[MAX];
unordered_set<int> vis2;

bool dfs(int l, int r, int u) {
    for (int v = l; v < r; v++) {
        if (dices[u][d[v]] && vis2.find(d[v]) == vis2.end()) {
            vis2.insert(d[v]);
            if (cx[d[v]] == -1 || dfs(l, r, cx[d[v]])) {
                cy[u] = d[v];
                cx[d[v]] = u;
                return true;
            }
        }
    }
    return false;
}

int maxmatch(int l, int r) {
    int ans = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for (int i = 0; i < n; i++) {
        if (cy[i] == -1) {
            vis2.clear();
            ans += dfs(l, r,i);
        }
    }
    return ans;
}

int solve() {
    int l = 0, r = 1, ans = 1;
    while (r < d_end) {
        if (d[r] == d[r-1] + 1)
            r += 1;
        else {
            l = r;
            r += 1;
        }
        if (r - l < ans) continue;
        int tmp = maxmatch(l ,r);
        if (tmp == r - l)
            ans = max(ans, r-l);
        else
            l += 1;
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    int x[6];
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d%d%d", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5]);
        for (int & j : x) {
            dices[i][j] = true;
            d.emplace_back(j);
        }
    }
    sort(d.begin(), d.end());
    auto tmp = unique(d.begin(), d.end());
    d_end = tmp - d.begin();
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}
