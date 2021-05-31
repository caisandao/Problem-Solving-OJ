#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
#define MAX_N 55
#define MAX_M 10004
using namespace std;

int t;
int n;
int x[MAX_N];
ll y[MAX_M];
ll yy[MAX_M];
int sum_x;


void solve() {
    y[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= sum_x; j++) {
            int tmp = j - x[i];
            if (tmp >= 0)
                yy[j] = y[j] + y[tmp];
        }
        for (int j = 1; j <= sum_x; j++) {
            y[j] = yy[j];
        }
    }
}

void init() {
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    memset(yy, 0, sizeof(yy));
    sum_x = 0;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        init();
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &x[i]);
        sort(x, x+n);
        for (int i = 0; i < n; i++)
            sum_x += x[i];
        solve();
        for (int i = 0; i <= sum_x; i++) {
            printf("%lld", y[i]);
            if (i == sum_x)
                printf("\n");
            else
                printf(" ");
        }
    }
}