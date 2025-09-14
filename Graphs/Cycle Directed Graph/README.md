#### Problem Description

```
Given a directed graph having A nodes. A matrix B of size M x 2 is given which represents

the M edges such that there is an edge directed from node B[i][0] to node B[i][1].

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.
```

##### Input format

```
The first line of the input has 2 integers n and e, representing the number of nodes and the number of edges in the graph.

The next e lines contains 2 integers u and v, showing that there exists an edge directed from node u to node v.
```

##### Output format
```
Return 1 if cycle is present else return 0.
```

##### Sample Input 1
```
5 6

1 2

4 1

2 4

3 4

5 2

1 3
```

##### Sample Output 1
```
1
```
##### Explanation
```
The given graph contain cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1.
```
##### Constraints
```
2 <= n <= 10^5
1 <= edges.size <= min(200000,A(A-1))
```

1 <= edges[i][0], edges[i][1] <= n
