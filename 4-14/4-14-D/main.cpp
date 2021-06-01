#include <iostream>
#define MAX_M 1003
using namespace std;

int T;
int x,y,m;
pair<double, double> points[MAX_M];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &x, &y, &m);
        for (int i = 0,u,v; i < m; i++) {
            scanf("%d%d", &u, &v);
            points[i].first = u;
            points[i].second = v;
        }
    }
}