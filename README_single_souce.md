# Single Source

## Functions
* void BellmanFord(int, int, int**, int*, int*): finds shortest path with BellmanFord Algorithm
* void printPath(int, int, int**, int*, int*): prints out the path starting from vertex 0 to the target vertex
* int get_path(int, int*): gets the path starting from vertex 0 to the target vertex

## Main Function
### Local Variables
* int n: the # of vertices
* int m: the # of edges
* int **w: w[v][u] is the cost of edges between vertex v and vertex u
* int *pred: pred[v] is the predecessor of vertex v
* int *dist; dist[v] is the distance starting from vertex 0

### Procedure
1. Input the # of vertices and edges
2. Check if EOF is met, if true, terminate the program
3. Allocate memory to w, pred and dist, and then initialize their values
4. Input edges and their weight
5. Find the shortest path to every vertex starting from vertex 0 and print out the result
6. Release memory and jump back to step 1