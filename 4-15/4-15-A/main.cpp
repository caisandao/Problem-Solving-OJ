#include <iostream>
#define MAX 25
#define ll long long
using namespace std;

ll n;
ll a[MAX], b[MAX];

inline ll Gcd(ll a, ll b) {
    if (b == 0) return a;
    else return Gcd(b, a%b);
}

inline ll multi(ll a, ll b, ll m) {
    ll res = 0;
    while (b) {
        if (b & 1) res = (res + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return res;
}

inline ll exgcd(ll a, ll b, ll& x, ll& y) {
    ll d;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

inline ll pow(ll a, ll b, ll m) {
    ll ans = 1;
    a %= m;
    while (b) {
        if (b & 1) ans = ans * a % m;
        b >> 1;
        a = a * a % m;
    }
    return ans;
}

inline ll reverse(ll a, ll m) {
    return pow(a, m-2, m);
}

ll china() { // a[]为余数，b[]为除数
    ll ans = 0;
    ll lcm = 1;
    for (int i = 0; i < n; i++) {
        lcm *= b[i];
    }
    ll x, y;
    for (int i = 0; i < n; i++) {
        ll p = lcm / b[i];
        exgcd(p, b[i], x, y);
        x = (x % b[i] + b[i]) % b[i];
        ans = (ans+multi(multi(p,x,lcm),a[i],lcm))%lcm;
    }
    return (ans + lcm) % lcm;
}

int flag;

ll china2() {
    ll m1 = b[0], a1 = a[0], m2, a2, k1, k2, x0, gcd, c;
    ll lcm = b[0];
    for (int i = 1; i < n; i++) {
        m2 = b[i];
        a2 = a[i];
        c = a2 - a1;
        gcd = exgcd(m1, m2, k1, k2);
        lcm = lcm * b[i] / Gcd(lcm, b[i]);
        if (c % gcd) {
            flag = 1;
            return 0;
        }
        x0 = c / gcd * k1;
        ll t = m2/gcd;
        x0 = (x0%t+t)%t;
        a1 += m1 * x0;
        m1 = m2 / gcd * m1;
    }
    return a1;
}

int main() {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &b[i], &a[i]);
    }
    printf("%lld\n", china2());
    return 0;
}