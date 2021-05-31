#include <iostream>
#include <vector>
#include <queue>
#define MAX_N 100005
#define MAX_K 12
using namespace std;

int n,m,k;
int cost[MAX_N][MAX_K];
int vis[MAX_N];
vector<pair<int, int>> edges[MAX_N]; // first: destination, second: weight

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    cost[1][0] = 0;
    pq.emplace(0, 1);
    while (!pq.empty()) {
        const auto state = pq.top();
        pq.pop();
        const int cur_cost = state.first;
        const int cur_idx = state.second;
        if (vis[cur_idx]) continue;
        vis[cur_idx] = 1;
        for (const auto & edge : edges[cur_idx]) {
            const int new_cost = cur_cost + edge.second;
            const int new_idx = edge.first;
            if (new_cost < cost[new_idx]) {
                pq.push({new_cost, new_idx});
                cost[new_idx][0] = new_cost;
            }
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    int u,v,d;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &d);
        edges[u].emplace_back(v, d);
        edges[v].emplace_back(u, d);
    }
    

}