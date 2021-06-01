#include <iostream>
#include <cmath>
#include <cassert>
#define PI 3.1415926
using namespace std;

// 可调参数 t_origin, delta, t_min, N

double a,b,c,d,e,f;
double dx, dy, dz;
double sx,sy,sz; // selected point
double ans;
double t_origin = 0.000001;
double delta = 0.999997;
double t_min;

inline bool inside(double x, double y) {
    return (x-d)*(x-d)/(a*a)+(y-e)*(y-e)/(b*b) <= 1;
}

inline double calculate_z(double x, double y) {
    double tmp = 1 - (x-d)*(x-d)/(a*a) - (y-e)*(y-e)/(b*b);
    return c*sqrt(tmp);
}

inline double calculate_dis(double x, double y, double z) {
    double x1 = x - dx;
    double y1 = y - dy;
    double z1 = z - dz;
    return sqrt(x1*x1 + y1*y1 + z1*z1);
}

void get_new_state(double &nx, double &ny, double x, double y, double t) {
    float angle = 2 * PI * (float(rand() % RAND_MAX) / RAND_MAX);
    double r = /*sqrt(a*a+b*b)*/a * t / t_origin;
    nx = x + r * cos(angle);
    ny = y + r * sin(angle);
}

void sa(double T) {
    double nx,ny,nz;
    while (T > t_min) {
        do {
            get_new_state(nx, ny, sx, sy, T);
        } while (!inside(nx, ny));
        nz = calculate_z(nx, ny);
        double delta_e = ans - min(calculate_dis(nx,ny,f+nz), calculate_dis(nx,ny,f-nz));
        if (delta_e > 0 || (double(rand() % RAND_MAX) / RAND_MAX) < exp(delta_e/T)) {
            sx = nx;
            sy = ny;
            ans = min(calculate_dis(nx,ny,f+nz), calculate_dis(nx,ny,f-nz));
        }
        T = delta * T;
    }
}

int main() {
    scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f);
    scanf("%lf%lf%lf", &dx, &dy, &dz);
    srand((unsigned)time(NULL));
    sx = 2*a*(double(rand() % RAND_MAX) / RAND_MAX) - a + d;
    double y_bound = sqrt(b*b-(b*b)/(a*a)*(sx-d)*(sx-d));
    sy = 2*y_bound*(double(rand() % RAND_MAX) / RAND_MAX) - y_bound + e;
    assert(inside(sx, sy));
    sz = calculate_z(sx, sy);
    ans = min(calculate_dis(sx, sy, f+sz), calculate_dis(sx,sy,f-sz));
    t_min = t_origin * 1e-4 /(/*sqrt(a*a+b*b)*/a);
    sa(t_origin);
    printf("%lf\n", ans);
    return 0;
}