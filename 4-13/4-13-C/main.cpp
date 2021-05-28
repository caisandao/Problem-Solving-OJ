#include <iostream>
#include <vector>
#define MAX 10004
using namespace std;

int t;
int n;
vector<int> c;

vector<int> prefix_function(vector<int> a) {
    vector<int> pi(n);
    for (int i = 1; i < a.size(); i++) {
        int j = pi[i-1];
        while (j > 0 && a[i] != a[j])
            j = pi[j-1];
        if (a[i] == a[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        c.clear();
        scanf("%d", &n);
        int tmp;
        for (int i = 0; i < n; i++) {
            scanf("%d", &tmp);
            c.emplace_back(tmp);
        }
        vector<int> next = prefix_function(c);
        int check = n % (n - next[n-1]);
        if (check == 0 && next[n-1] != 0) {
            printf("0\n");
        } else {
            printf("%d\n", (n - next[n-1]) - check);
        }
    }
    return 0;
}