#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_N 100005
#define MAX_K 12
#define MAX_COST 200000008
using namespace std;

int n,m,k;
int cost[MAX_N][MAX_K];
int vis[MAX_N][MAX_K];
vector<pair<int, int>> edges[MAX_N]; // first: destination, second: weight

int minimum(int a, int b) {
    return a < b ? a : b;
}

void dijkstra(int t) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    cost[1][t] = 0;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        const auto state = pq.top();
        pq.pop();
        int cur_cost = state.first;
        int cur_idx = state.second;
        if (vis[cur_idx][t]) continue;
        vis[cur_idx][t] = 1;
        for (const auto & edge : edges[cur_idx]) {
            int new_idx = edge.first;
            if (vis[new_idx][t])  continue;
            int new_cost;
            if (t == 0)
                new_cost = cur_cost + edge.second;
            else
                new_cost = minimum(cur_cost+edge.second, cost[cur_idx][t-1]);
            if (new_cost < cost[new_idx][t]) {
                pq.push({new_cost, new_idx});
                cost[new_idx][t] = new_cost;
            }
        }
    }
}

int main() {
    memset(cost, 0x3f, sizeof(cost));
    scanf("%d%d%d", &n, &m, &k);
    int u,v,d;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &d);
        edges[u].emplace_back(v, d);
        edges[v].emplace_back(u, d);
    }
    for (int i = 0; i <= k; i++)
        dijkstra(i);
    printf("%d\n", cost[n][k]);
    return 0;
}