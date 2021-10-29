# Dynamic Programming!

## Floyd Warshall Algorithm
Finds the shortest distance between two nodes

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
