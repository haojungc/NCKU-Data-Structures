# All Pair

## Functions
* void BellmanFord(int, int, int, int**, int**, int**): finds shortest path with BellmanFord Algorithm
* void printPath(int, int, int, int**, int**, int**): prints out the path between to arbitrary vertices
* int get_path(int, int, int**): gets the path starting from two arbitrary vertices

## Main Function
### Local Variables
* int n: the # of vertices
* int m: the # of edges
* int **w: w[v][u] is the cost of edges between vertex v and vertex u
* int **pred: pred[v][u] is the predecessor of vertex u in the case where vertex v is the starting point
* int **dist; dist[v][u] is the distance starting from vertex v to vertex u

### Procedure
1. Input the # of vertices and edges
2. Check if EOF is met, if true, terminate the program
3. Allocate memory to w, pred and dist, and then initialize their values
4. Input edges and their weight
5. Find the shortest paths to every vertex starting from vertex v(where 0 <= v < n) and print out the result
6. Release memory and jump back to step 1