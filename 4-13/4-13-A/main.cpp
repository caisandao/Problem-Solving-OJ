#include <iostream>
#define MOD 1000000007
#define ll uint64_t
using namespace std;

int t;
ll a,b,c,d;

ll plus_mod(ll x, ll y, ll p) {
    ll a = x % p;
    ll b = y % p;
    return  (a + b) % p;
}

ll multi_mod(ll x, ll y, ll p) {
    ll ans = 0;
    ll tmp = y;
    for (int i = 0; i < 64; i++) {
        if (x & 1 == 1) {
            ans = plus_mod(ans, tmp, p);
        }
        tmp = plus_mod(tmp, tmp, p);
        x >>= 1;
    }
    return ans;
}

ll pow_mod(ll x, ll y, ll p) {
    ll ans = 1;
    while (y > 0) {
        if (y & 1 == 1) {
            ans = multi_mod(ans, x, p);
        }
        x = multi_mod(x, x, p);
        y >>= 1;
    }
    return ans;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%ld%ld%ld%ld", &a, &b, &c, &d);
        ll ans = 0;
        ans = plus_mod(pow_mod(2, a, MOD), ans, MOD);
        ans = plus_mod(pow_mod(2, b, MOD), ans, MOD);
        ll tmp = multi_mod(plus_mod(a, c, MOD), pow_mod(2, b, MOD), MOD);
        ans = plus_mod(tmp, ans, MOD);
        ans = plus_mod(MOD-plus_mod(a, 1, MOD), ans, MOD);
        ans = multi_mod(pow_mod(2, d, MOD), ans, MOD);
        printf("%ld\n", ans);
    }
    return 0;
}
