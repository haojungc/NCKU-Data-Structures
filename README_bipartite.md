# Bipartite

## Global Variables
* int n: # of vertices
* int m: # of edges
* int *partition: the bipartite sets
* bool *visited: stores the visited status of each vertex

## Class: Graph
### Member Variables
* int vertexCount: # of vertices of the graph
* list&lt;int> *vertex: the adjacency list of the graph

### Member Functions
* void setVertex(int n): sets the # of vertices of the graph
* void addEdge(int vertex1, int vertex2): adds a new edge to the graph
* bool bfs(int start): bfs the adjacency list of the graph, returns false if the graph isn't bipartite

## Other Functions
* bool isBipartite(): ensures every vertex is visited and returns true if the graph is bipartite by calling Graph::bfs(int start)
* void printBipartiteSet(): prints out the two sets of bipartite graph

## Main Function
1. Input the # of vertices & the # of edges of the graph
2. Initialize graph, partition and visited
3. Input edges of graph
4. Check if graph is bipartite by using function isBipartite()
    * true: print "true" and the possible bipartite partition
    * false: print "false"