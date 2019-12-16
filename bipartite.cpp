#include <iostream>
#include <list>
#include <queue>
using namespace std;

int n, m;        // n: # of vertices
                 // m: # of edges
int *partition;  // valid value: 1 & 2
bool *visited;

class Graph {
   public:
    Graph();
    void setVertex(int);
    void addEdge(int, int);
    bool bfs(int);
    void print();

   private:
    int vertexCount;
    list<int> *vertex;
};

Graph::Graph() {}

void Graph::setVertex(int n) {
    vertexCount = n;
    vertex = new list<int>[n];
}
void Graph::addEdge(int v1, int v2) {
    vertex[v1].push_front(v2);
    vertex[v2].push_front(v1);
}
bool Graph::bfs(int start) {
    queue<int> vertexQueue;

    visited[start] = true;
    vertexQueue.push(start);
    partition[start] = 1;

    while (!vertexQueue.empty()) {
        int origin = vertexQueue.front();
        vertexQueue.pop();

        for (list<int>::iterator it = vertex[origin].begin(); it != vertex[origin].end(); it++) {
            int i = *it;

            if (!visited[i]) {
                visited[i] = true;
                vertexQueue.push(i);
                partition[i] = 3 - partition[origin];  // switch value between 1 & 2
            } else {
                // Check if there is any conflict vertex
                for (list<int>::iterator target = vertex[i].begin(); target != vertex[i].end(); target++) {
                    int j = *target;

                    if (visited[j] && partition[j] != partition[origin]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void Graph::print() {
    for (int i = 0; i < vertexCount; i++) {
        for (list<int>::iterator it = vertex[i].begin(); it != vertex[i].end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
}

Graph graph;

bool isBipartite() {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bool result = graph.bfs(i);

            if (!result) {
                return false;
            }
        }
    }
    return true;
}

void printBipartiteSet() {
    // Print set 1
    for (int i = 0; i < n; i++) {
        if (partition[i] == 1) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Print set 2
    for (int i = 0; i < n; i++) {
        if (partition[i] == 2) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    cin >> n >> m;  // Input # of vertices & # of edges

    partition = new int[n];
    visited = new bool[n];

    // Initialize
    graph.setVertex(n);
    for (int i = 0; i < n; i++) {
        partition[i] = 0;
        visited[i] = false;
    }

    // Input edges
    for (int i = 0; i < m; i++) {
        int v1, v2;

        cin >> v1 >> v2;
        graph.addEdge(v1, v2);
    }

    // Check if the graph is bipartite
    if (isBipartite()) {
        cout << "true" << endl;
        printBipartiteSet();
    } else {
        cout << "false" << endl;
    }

    return 0;
}