#include <cstdio>

int *topological_sort(bool **, int);
void getEarliestEventTime(int *, int *, bool **, int **, int);
void getLatestEventTime(int *, int *, bool **, int **, int);

const int INF = 2e9;

typedef struct _Activity {
    int startVertex, endVertex;
    int e, l, slack; // e: the earliest time of this activity
                     // l: the latest time of this activity
                     // slack = l - e
} Activity;

int main() {
    int n, maxVertex; // the # of activities
    bool **adjMatrix; // adjMatrix[u][v]: true if edge <u, v> exists
    int **duration;   // duration[u][v]: the duration of edge <u, v>
    int *ee, *le;     // ee[j]: the earliest event time event j can occur
                      // le[j]: the latest event time event j must occur without increasing the project duration
    Activity *act;

    scanf("%d", &n);
    maxVertex = n + 1;

    // Allocate memory
    adjMatrix = new bool *[maxVertex];
    duration  = new int *[maxVertex];
    ee        = new int[maxVertex];
    le        = new int[maxVertex];
    act       = new Activity[n];

    for (int i = 0; i < maxVertex; i++) {
        ee[i]        = INF;
        le[i]        = INF;
        adjMatrix[i] = new bool[maxVertex];
        duration[i]  = new int[maxVertex];

        for (int j = 0; j < maxVertex; j++) {
            adjMatrix[i][j] = false;
            duration[i][j]  = INF;
        }
    }

    // Input activity data
    int maxVertexIndex = 0;
    for (int i = 0; i < n; i++) {
        int index, startVertex, endVertex;

        scanf("%d%d%d", &index, &startVertex, &endVertex);
        scanf("%d", &duration[startVertex][endVertex]);
        adjMatrix[startVertex][endVertex] = true;
        act[index - 1].startVertex        = startVertex;
        act[index - 1].endVertex          = endVertex;

        // Get the # of vertices
        int maxIndex   = (startVertex > endVertex) ? startVertex : endVertex;
        maxVertexIndex = (maxIndex > maxVertexIndex) ? maxIndex : maxVertexIndex;
    }
    maxVertex = maxVertexIndex + 1;

    // Sort
    int *sortedList = topological_sort(adjMatrix, maxVertex);

    getEarliestEventTime(ee, sortedList, adjMatrix, duration, maxVertex);

    // last le = last ee
    le[sortedList[maxVertex - 1]] = ee[sortedList[maxVertex - 1]];
    getLatestEventTime(le, sortedList, adjMatrix, duration, maxVertex);

    // Update activity
    for (int i = 0; i < n; i++) {
        int startVertex = act[i].startVertex;
        int endVertex   = act[i].endVertex;

        act[i].e     = ee[startVertex];
        act[i].l     = le[endVertex] - duration[startVertex][endVertex];
        act[i].slack = act[i].l - act[i].e;
    }

    // Output the results
    printf("%-8s%-8s%-8s\n", "event", "ee", "le");
    for (int i = 0; i < maxVertex; i++) {
        int vertex = sortedList[i];
        printf("%-8d%-8d%-8d\n", vertex, ee[vertex], le[vertex]);
    }
    printf("\n\n");

    printf("%-8s%-8s%-8s%-8s%-8s\n", "act.", "e", "l", "slack", "critical");
    for (int i = 0; i < n; i++) {
        printf("%-8d%-8d%-8d%-8d%-8s\n", i + 1, act[i].e, act[i].l, act[i].slack, (act[i].slack == 0) ? "Yes" : "No");
    }
    printf("\n\n");

    bool first = true;
    for (int i = 0; i < n; i++) {
        if (act[i].slack == 0) {
            if (first) {
                first = false;
                printf("%d", i + 1);
            } else {
                printf(" %d", i + 1);
            }
        }
    }
    printf("\n");

    return 0;
}

int *topological_sort(bool **adjMatrix, int maxVertex) {
    int *sortedList = new int[maxVertex];
    bool *marked    = new bool[maxVertex];
    int count       = 0;

    for (int i = 0; i < maxVertex; i++) {
        marked[i] = false;
    }

    while (true) {
        bool allMarked = true;
        for (int i = 0; i < maxVertex; i++) {
            if (!marked[i]) {
                allMarked = false;
                break;
            }
        }
        if (allMarked)
            break;

        for (int col = 0; col < maxVertex; col++) {
            if (!marked[col]) {
                bool noPredecessor = true;
                for (int row = 0; row < maxVertex; row++) {
                    if (!marked[row] && adjMatrix[row][col]) {
                        noPredecessor = false;
                        break;
                    }
                }
                if (noPredecessor) {
                    sortedList[count++] = col;
                    marked[col]         = true;
                }
            }
        }
    }

    delete[] marked;

    return sortedList;
}

void getEarliestEventTime(int *ee, int *sortedList, bool **adjMatrix, int **duration, int maxVertex) {
    int startVertex = sortedList[0];

    ee[0]                              = 0;
    duration[startVertex][startVertex] = 0;

    for (int i = 0; i < maxVertex; i++) {
        startVertex = sortedList[i];
        for (int endVertex = 0; endVertex < maxVertex; endVertex++) {
            if (adjMatrix[startVertex][endVertex]) {
                if (ee[endVertex] == INF || ee[startVertex] + duration[startVertex][endVertex] > ee[endVertex]) {
                    ee[endVertex] = ee[startVertex] + duration[startVertex][endVertex];
                }
            }
        }
    }
}

void getLatestEventTime(int *le, int *sortedList, bool **adjMatrix, int **duration, int maxVertex) {
    for (int i = maxVertex - 1; i >= 0; i--) {
        int startVertex = sortedList[i];
        for (int endVertex = 0; endVertex < maxVertex; endVertex++) {
            if (adjMatrix[endVertex][startVertex]) {
                if (le[startVertex] - duration[endVertex][startVertex] < le[endVertex]) {
                    le[endVertex] = le[startVertex] - duration[endVertex][startVertex];
                }
            }
        }
    }
}
