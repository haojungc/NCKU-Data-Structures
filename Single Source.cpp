#include <cstdio>

void BellmanFord(int, int, int **, int *, int *);
void printPath(int, int, int **, int *, int *);
int *get_path(int, int *);

int main() {
    while (true) {
        int n;     // the # of vertices
        int m;     // the # of edges
        int **w;   // w[v][u]: the cost of edges between vertex v and vertex u
        int *pred; // pred[v]: the predecessor of vertex v
        int *dist; // the distance between two vertices

        // EOF
        if (scanf("%d%d", &n, &m) != 2) {
            break;
        }

        // Initialize
        w    = new int *[n];
        pred = new int[n];
        dist = new int[n];
        for (int i = 0; i < n; i++) {
            pred[i] = -1;
            dist[i] = 1e9;
            w[i]    = new int[m];
            for (int j = 0; j < m; j++) {
                w[i][j] = -1;
            }
        }
        dist[0] = 0;

        // Input edges and their weight
        for (int i = 0; i < m; i++) {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            scanf("%d", &w[v1][v2]);
        }

        // Find the shortest paths of every vertex starting from vertex 0
        BellmanFord(n, m, w, pred, dist);

        // Output the results
        printPath(n, m, w, pred, dist);

        // Free memory
        delete[] pred;
        delete[] dist;
        for (int i = 0; i < n; i++) {
            delete[] w[i];
        }
        delete[] w;
    }

    return 0;
}

void BellmanFord(int n, int m, int *w[], int pred[], int dist[]) {
    // Relax (n - 1) times
    for (int i = 0; i < n - 1; i++) {
        for (int v1 = 0; v1 < n; v1++) {
            for (int v2 = 1; v2 < n; v2++) {
                if (w[v1][v2] != -1 && dist[v1] + w[v1][v2] < dist[v2]) {
                    dist[v2] = dist[v1] + w[v1][v2];
                    pred[v2] = v1;
                }
            }
        }
    }
}

void printPath(int n, int m, int *w[], int pred[], int dist[]) {
    for (int v = 1; v < n; v++) {
        bool first = true;

        if (dist[v] == 1e9) {
            printf("Impossible\n");
        } else {
            int *sequence = get_path(v, pred);

            for (int j = 0;; j++) {
                if (first) {
                    first = false;
                    printf("%d", sequence[j]);
                } else {
                    printf(",%d", sequence[j]);
                }

                if (sequence[j] == v)
                    break;
            }
            printf(" %d\n", dist[v]);

            delete[] sequence;
        }
    }
    printf("\n");
}

int *get_path(int goal, int pred[]) {
    int *sequence;
    int count = 1;

    // Count the # of vertices in the path
    // including vertex 0 and the last vertex
    for (int v = goal;; v = pred[v]) {
        if (v == 0) {
            sequence = new int[count];
            break;
        }
        count++;
    }

    // Reverse predecessor and store the result in sequence
    for (int v = goal, i = count - 1; i >= 0; v = pred[v], i--) {
        sequence[i] = v;
    }

    return sequence;
}