# Graph Theory 

### Elements of a Graph
- Vertices (nodes): individual elements in a graph
1. Directed
2.
3.
4.
- Edge: a connection between two elements (vertices/nodes)
1. Directed<A,B>: the edge goes in one direction
2. Undirected (A,B): the edge goes in both directions
3. Weighted: the edge has weight

### Graph Notation
A graph contains two sets and is represented by the notation G(V,E).

Vertices of G1: {A, B, C, D}

## Data Structures for Graphs

1. Adjacency Matrix
| . | A | B | C | D |
| --- | --- | --- | --- | --- |
| A | 0  | 1  | 1  | 0 |
| B | 0 | 0 | 1 | 1 |
| C | 0 | 0 | 0 | 1 |
| D | 0 | 0 | 0 | 0 |


2. Adjacency List
Jagged array or linked list.
A -> B -> C -> nullptr
B -> C -> D -> nullptr
C -> D -> nullptr
D -> nullptr
