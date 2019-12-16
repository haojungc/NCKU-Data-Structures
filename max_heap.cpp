#include <cstdio>
#include <iostream>
using namespace std;

void max_heap(int);
void swap(int, int);
int find_max_price(int);

int m, n;  // m: the # of rows in the stadium
           // n: the # of football fans waiting in the line
int *x;    // x[i]: the initial # of empty seats in row "i"

int main() {
    int t;  // the # of test cases

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> m >> n;
        x = new int[m];

        // Input the ＃ of empty seats in each row
        // and generate max heap
        for (int j = 0; j < m; j++) {
            scanf("%d", &x[j]);
            max_heap(j);
        }

        int total = 0;
        for (int j = 0; j < n; j++) {
            total += find_max_price(0);
        }

        printf("%d\n", total);

        delete[] x;
    }

    return 0;
}

void max_heap(int child) {
    int parent = (child - 1) / 2;

    if (child != 0 && x[child] > x[parent]) {
        swap(child, parent);
        max_heap(parent);
    }
    return;
}

void swap(int a, int b) {
    int tmp = x[a];
    x[a] = x[b];
    x[b] = tmp;
}

int find_max_price(int parent) {
    int child1 = parent * 2 + 1;
    int child2 = child1 + 1;
    int max_child = -1;

    // only one child
    if (child1 == m - 1) {
        max_child = child1;
    }
    // two children
    else if (child2 < m) {
        max_child = (x[child1] >= x[child2]) ? child1 : child2;
    }

    if (max_child != -1 && x[max_child] == x[parent]) {
        return find_max_price(max_child);
    } else {
        int increment;
        increment = x[parent];
        x[parent]--;
        return increment;
    }
}