# Dynamic Programming!

## Floyd Warshall Algorithm
Finds the shortest distance between two nodes

- Create a matrix of the distances between all the nodes
- Create a matrix to store the shortest pathes from each node to another node (same size matrix as above)
- Iterate over each possible size path (where k=the amount of nodes) and record if the "longer path" takes less time (is weighted less)

```C++
for(k=1; k <= n; k++)
  for(i=1; i <= n; i++)
    for(j=1; j <= n; j++)
      if (D[i][k] + D[i][j] < D[i][j])
      {
        P[i][j] = k;
        D[i][j] = D[i][k] + D[k][i];
      }
```
