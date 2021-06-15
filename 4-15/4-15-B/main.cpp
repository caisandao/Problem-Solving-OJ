#include <iostream>
#include <cstring>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define MAX_L 1006
#define MAX_R 5003
using namespace std;

int n;
//int Map[MAX_L][MAX_R];
unordered_map<int, int> dices[MAX_R];
int cl[MAX_L], cr[MAX_R];
bool vis[MAX_L];
int L, R;
set<int> num;

bool dfs(int u) { // 从右边进入
    for (auto iter = num.begin(); iter != num.end(); iter++) {
        if (dices[u][*iter] && !vis[*iter] && *iter >= L && *iter <= R) {
            vis[*iter] = 1;
            if (cl[*iter] == -1 || dfs(cl[*iter])) {
                cr[u] = *iter;
                cl[*iter] = u;
                return 1;
            }
        }
    }
    return 0;
}

int maxmatch() {
    int ans = 0;
    memset(cl, -1, sizeof(cl));
    memset(cr, -1, sizeof(cr));
    for (int i = 0; i < n; i++) {
        if (cr[i] == -1) {
            memset(vis, 0, sizeof(vis));
            ans += dfs(i);
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    int x[6];
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d%d%d%d", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5]);
        for (int j = 0; j < 6; j++) {
            num.insert(x[j]);
            dices[i][x[j]] = 1;
        }
    }
    //sort(num.begin(), num.end());
    L = *num.begin();
    R = *num.begin();
    int ans = 0;
    auto iter = num.begin();
    iter++;
    auto iter2 = iter;
    iter--;
    while (iter2 != num.end()) {
        while (iter2 != num.end() && *iter2 == *iter + 1) {
            iter++;
            iter2++;
        }
        R = *iter;
        int tmp = maxmatch();
        if (tmp > ans) ans = tmp;
        if (iter2 != num.end()) {
            L = *iter2;
            R = *iter2;
            iter = iter2;
            iter2++;
        } else break;
    }
    printf("%d\n", ans);
    return 0;
}