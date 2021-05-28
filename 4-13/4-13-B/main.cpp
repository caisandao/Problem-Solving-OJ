#include <iostream>
#include <algorithm>
#define MAX_M 10004
using namespace std;

int t;
int n,m;
int y[MAX_M];

int solve() {
    int res = 0;
    for (int i = 1; i < m+1; i++) {
        if (y[i] != 0) {
            res = i;
            break;
        }
    }
    for (int i = 0; i < m+1; i++) {
        int tmp = i - res;
        if (tmp >= 0)
            y[i] = y[i] - y[tmp];
    }
    return res;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= m; i++)
            scanf("%d", &y[i]);
        for (int i = 0; i < n; i++) {
            printf("%d", solve());
            if (i == n-1) printf("\n");
            else printf(" ");
        }
    }
}