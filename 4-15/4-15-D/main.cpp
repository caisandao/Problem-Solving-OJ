#include <iostream>
#define MAX 20004
using namespace std;

int T;
int n;
int h[MAX];
int a[MAX], b[MAX];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &h[0]);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &b[i]);
    }
    return 0;
}