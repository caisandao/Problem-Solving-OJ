#include <iostream>
#include <queue>
#include <cstring>
#define MAX 20004
#define ll long long
using namespace std;

ll T;
ll n;
ll h[MAX];
ll a[MAX], b[MAX];
priority_queue<ll> big_heap;
ll study_days;

void init() {
    memset(h, 0, sizeof(h));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    while (!big_heap.empty())
        big_heap.pop();
}


int main() {
    scanf("%lld", &T);
    while (T--) {
        init();
        scanf("%lld%lld", &n, &h[0]);
        study_days = n;
        for (ll i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        for (ll i = 0; i < n; i++)
            scanf("%lld", &b[i]);
        for (ll i = 1; i <= n; i++) {
            big_heap.emplace(b[i-1]);
            h[i] = h[i-1] + a[i-1] - b[i-1];
            while (h[i] <= 0) {
                if (big_heap.empty()) {
                    printf("Bob will be unhappy!\n");
                    goto R;
                }
                h[i] += big_heap.top();
                big_heap.pop();
                study_days--;
            }
        }
        printf("%lld %lld\n", study_days, h[n]);
        R: ;
    }
    return 0;
}