#include <iostream>
#include <vector>
#define MAX_N 606
using namespace std;

int n,m;
int dp[MAX_N][MAX_N];
int balls[MAX_N];

void solve() {
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (balls[i] == balls[j]) {
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]);
                continue;
            }
            int ans = 0x7fffffff;
            for (int t = i; t < j; t++)
                ans = min(ans, dp[i][t] + dp[t+1][j]);
            dp[i][j] = ans;
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &balls[i]);
    for (int i = 0; i < n; i++)
        dp[i][i] = 1;
    solve();
    printf("%d\n", dp[0][n-1]);
    return 0;
}