#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void heightUnion(int, int);
int collapsingFind(int);

int t;             // the # of trees
int *height;       // the height of tree t
int parent[1000];  // the parent of the node
int *root;         // the root of tree t

int main() {
    int n, p, q;  // n: the # of nodes in tree t
                  // p: the id of the node
                  // q: the id of the parent node
    string cmd;

    // Set all trees
    cin >> t;
    height = new int[t];
    root = new int[t];
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            scanf("%d%d", &p, &q);

            // root
            if (q < 0) {
                height[i] = -q;
                parent[p] = -1;
                root[i] = p;
            }
            // not root
            else {
                parent[p] = q;
            }
        }
    }

    // Input commands
    while (cin >> cmd, cmd != "STOP") {
        if (cmd == "UNION") {
            int r1, r2;

            cin >> r1 >> r2;
            heightUnion(r1, r2);
        } else if (cmd == "FIND") {
            int node;
            cin >> node;

            int total_step = collapsingFind(node);
            printf("%d\n", total_step);
        }
    }

    delete[] height;
    delete[] root;

    return 0;
}

void heightUnion(int r1, int r2) {
    int t1, t2;  // t stands for tree
    int h1, h2;  // h stands for height

    // Get heights of trees
    for (int i = 0; i < t; i++) {
        if (root[i] == r1) {
            t1 = i;
            h1 = height[i];
        } else if (root[i] == r2) {
            t2 = i;
            h2 = height[i];
        }
    }

    // Update the height of the larger tree
    // and update the root of the smaller tree
    if (h1 >= h2) {
        parent[r2] = r1;
        height[t1] = (h1 >= h2 + 1) ? h1 : h2 + 1;
        root[t2] = root[t1];
    } else {
        parent[r1] = r2;
        height[t2] = (h2 >= h1 + 1) ? h2 : h1 + 1;
        root[t1] = root[t2];
    }
}

int collapsingFind(int index) {
    int r, lead, trail;  // r: root
    int total_step = 0;

    // Find root
    for (r = index; parent[r] != -1; r = parent[r]) {
        total_step++;
    }

    // Collapse tree
    for (trail = index; parent[trail] != r; trail = lead) {
        lead = parent[trail];
        parent[trail] = r;
        total_step++;
    }

    return total_step;
}