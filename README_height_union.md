# Height Union

## Global Variables
* int t: the # of trees
* int *height: the height of tree t
* int parent[1000]: the parent of the node
* int *root: the root of tree t

## Functions
* void heightUnion(int, int): merges two trees into one tree
* int collapsingFind(int): collapses the tree and returns the total step of collapsing

## Main Function
1. Set the nodes, parents, roots and height of all trees
2. Input commands
    * UNION: input two roots you want to merge and call heightUnion(int, int)
    * FIND: input the node you want to find and count the total step by calling collapsingFind(int)
    * STOP: terminates the program

## Comparison of Collapsing Find between Weight Union & Height Union
### Weight Union:
* Slower: the speed of collapsing find depends on the height of the tree, so the worse result may occur when the lighter tree is a skewed tree
### Height Union:
* Faster: unlike weight union, the maximum increment of height of the tree is one, so it will always come up with the best result