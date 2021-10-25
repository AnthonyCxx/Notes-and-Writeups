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

## Examples
1.
2.
3.
4. Edge (V1, V2) is incident on verticed V1 and V2
5. 5. If (V1, V2) is an edge in E(G) then we say that V1 and V2 are adjacent
6. .
7. .
8. If <V1, V2< or (V1, V2) is an edge in E(G) then V1=V2
9. E(G) can be empty (no edges)
10. Only one edge per set of nodes
11. Out-degree is how many edges come out from a node, in-degree is how many go in

## Calculating the amount of Possible Edges
The amount of possible edges is nodeCount*(nodeCount-1)
