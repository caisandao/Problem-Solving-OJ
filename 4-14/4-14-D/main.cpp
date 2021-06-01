#include <iostream>
#include <cmath>
#include <cassert>
#define MAX_M 1003
#define MAX_DIS 1000000.0
#define PI 3.1415926
using namespace std;

int T;
int x,y,m;
pair<double, double> points[MAX_M];
double sx, sy;
double delta = 0.999;
double t_origin = 0.1;
double t_min;
double dis;

double find_min_dis(double a, double b) {
    double res = MAX_DIS;
    for (int i = 0; i < m; i++) {
        double tmp = sqrt((points[i].first-a)*(points[i].first-a)+(points[i].second-b)*(points[i].second-b));
        if (res > tmp)
            res = tmp;
    }
    return res;
}

inline bool inside(double a, double b) {
    return a >= 0 && a <= x && b >= 0 && b <= y;
}

void get_new_state(double &a, double &b, double t_cur) {
    float angle = 2 * PI * ((double)(rand() % RAND_MAX) / RAND_MAX);
    double r = (min(x,y)/2) * t_cur / t_origin;
    a = sx + r * cos(angle);
    b = sy + r * sin(angle);
}

void sa(double t) {
    double nx, ny;
    while (t > t_min) {
        do {
            get_new_state(nx, ny, t);
        } while (!inside(nx, ny));
        double new_dis = find_min_dis(nx, ny);
        double delta_e = new_dis- dis;
        if (delta_e > 0 || (double)(rand() % RAND_MAX) / RAND_MAX < exp(delta_e / t)) {
            sx = nx;
            sy = ny;
            dis = new_dis;
        }
        t = delta * t;
    }
}

int main() {
    scanf("%d", &T);
    srand((unsigned)time(NULL));
    while (T--) {
        scanf("%d%d%d", &x, &y, &m);
        for (int i = 0,u,v; i < m; i++) {
            scanf("%d%d", &u, &v);
            points[i].first = u;
            points[i].second = v;
        }
        sx = x * ((double)(rand() % RAND_MAX) / RAND_MAX);
        sy = y * ((double)(rand() % RAND_MAX) / RAND_MAX);
        assert(inside(sx, sy));
        dis = find_min_dis(sx, sy);
        t_min = t_origin * 1e-3 / (min(x,y)/2);
        sa(t_origin);
        int sx_10 = round(sx * 10);
        int sy_10 = round(sy * 10);
        double sx_out = double(sx_10) / 10.0;
        double sy_out = double(sy_10) / 10.0;
        printf("The safest point is (%.1lf, %.1lf).\n", sx_out, sy_out);
    }
}