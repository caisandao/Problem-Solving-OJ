#include  <iostream>
#include <stack>
#define MAX 100005
#define MAX_D 1000006
using namespace std;

int n,q;
int d[MAX];
int s,k;
int l[MAX], r[MAX];

struct node {
    int id = -1;
    int size = 0;
    struct node *left = nullptr;
    struct node *right = nullptr;
    struct node *parent = nullptr;
}nodes[MAX];
typedef struct node node;
node *root;

void calculate_l() {
    stack<pair<int, int>> s; // pair first: id, second: value
    for (int i = 1; i < n; i++) {
        while (!s.empty() && s.top().second < d[i])
            s.pop();
        if (s.empty())
            l[i] = 0;
        else
            l[i] = s.top().first;
        s.push({i, d[i]});
    }
}

void calculate_r() {
    stack<pair<int, int>> s;
    for (int i = n-1; i > 0; i--) {
        while (!s.empty() && s.top().second < d[i])
            s.pop();
        if (s.empty())
            r[i] = 0;
        else
            r[i] = s.top().first;
        s.push({i, d[i]});
    }
}

void connect(int p, int c) {
    nodes[c].parent = &nodes[p];
    if (c < p)
        nodes[p].left = &nodes[c];
    else
        nodes[p].right = &nodes[c];
}

void build_tree() {
    for (int i = 1; i < n; i++) {
        nodes[i].id = i;
        if (l[i] == 0 && r[i] == 0) {
            root = &nodes[i];
        } else {
            if (d[l[i]] < d[r[i]])
                connect(l[i], i);
            else
                connect(r[i], i);
        }
    }
}

int dfs(node *r) {
    if (r == nullptr) return 0;
    int size = dfs(r->left) + dfs(r->right) + 1;
    return r->size = size;
}

int find_first_parent(int x ,int k) {
    int ret = x;
    while (nodes[ret].size < k) {
        ret = nodes[ret].parent->id;
    }
    return ret;
}

int handle_query(int s, int k) {
    int x = 0;
    if (s == 1) x = 1;
    else if (s == n) x = n-1;
    else if (d[s-1] < d[s]) x = s-1;
    else x = s;

    if (nodes[x].size >= k) {
        if (nodes[x].id == s-1)
            return s-k;
        else
            return s+k;
    } else {
        int y = find_first_parent(x, k);
        if (nodes[x].id < nodes[y].id)
            return nodes[y].id + (k - nodes[y].left->size);
        else
            return nodes[y].id + 1 - (k - nodes[y].right->size); 
    }
}

int main() {
    scanf("%d%d", &n, &q);
    d[0] = MAX_D;
    for (int i = 1; i < n; i++)
        scanf("%d", &d[i]);

    calculate_l();
    calculate_r();
    build_tree();
    dfs(root);

    while (q--) {
        scanf("%d%d", &s, &k);
        if (k == 1)
            printf("%d\n", s);
        else
            printf("%d\n", handle_query(s, k-1));
    }
    return 0;
}