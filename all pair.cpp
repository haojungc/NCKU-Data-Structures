#include <cstdio>

void BellmanFord(int, int, int, int **, int **, int **);
void printPath(int, int, int, int **, int **, int **);
int *get_path(int, int, int **);

int main() {
    while (true) {
        int n;      // the # of vertices
        int m;      // the # of edges
        int **w;    // w[v][u]: the cost of edges between vertex v and vertex u
        int **pred; // pred[v][u]: the predecessor of vertex u in the case where vertex v is the starting point
        int **dist; // dist[v][u]: the distance starting from vertex v to vertex u

        // EOF
        if (scanf("%d%d", &n, &m) != 2) {
            break;
        }

        // Initialize
        w    = new int *[n];
        pred = new int *[n];
        dist = new int *[n];
        for (int i = 0; i < n; i++) {
            w[i]    = new int[m];
            pred[i] = new int[n];
            dist[i] = new int[n];

            for (int j = 0; j < m; j++) {
                w[i][j] = -1;
            }
            for (int j = 0; j < n; j++) {
                pred[i][j] = -1;
                dist[i][j] = 1e9;
            }
        }

        // Input edges and their weight
        for (int i = 0; i < m; i++) {
            int v1, v2;
            scanf("%d%d", &v1, &v2);
            scanf("%d", &w[v1][v2]);
        }

        for (int v = 0; v < n; v++) {
            // Find the shortest paths of every vertex starting from vertex 0
            BellmanFord(v, n, m, w, pred, dist);

            // Output the results
            printPath(v, n, m, w, pred, dist);
        }
        printf("\n");

        // Free memory
        for (int i = 0; i < n; i++) {
            delete[] w[i];
            delete[] pred[i];
            delete[] dist[i];
        }
        delete[] w;
        delete[] pred;
        delete[] dist;
    }

    return 0;
}

void BellmanFord(int start, int n, int m, int *w[], int *pred[], int *dist[]) {
    dist[start][start] = 0;

    // Relax (n - 1) times
    for (int i = 0; i < n - 1; i++) {
        for (int v1 = 0; v1 < n; v1++) {
            for (int v2 = 0; v2 < n; v2++) {
                if (w[v1][v2] != -1 && dist[start][v1] + w[v1][v2] < dist[start][v2]) {
                    dist[start][v2] = dist[start][v1] + w[v1][v2];
                    pred[start][v2] = v1;
                }
            }
        }
    }
}

void printPath(int start, int n, int m, int *w[], int *pred[], int *dist[]) {
    for (int v = 0; v < n; v++) {
        bool first = true;

        if (v != start) {
            int *sequence = get_path(start, v, pred);

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
            printf(" %d\n", dist[start][v]);

            delete[] sequence;
        }
    }
}

int *get_path(int start, int goal, int *pred[]) {
    int *sequence;
    int count = 1;

    // Count the # of vertices in the path
    // including vertex 0 and the last vertex
    for (int v = goal;; v = pred[start][v]) {
        if (v == start) {
            sequence = new int[count];
            break;
        }
        count++;
    }

    // Reverse predecessor and store the result in sequence
    for (int v = goal, i = count - 1; i >= 0; v = pred[start][v], i--) {
        sequence[i] = v;
    }

    return sequence;
}