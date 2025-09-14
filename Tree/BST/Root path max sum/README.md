#### Problem Description
```
Given a binary tree, you need to find the maximum sum among any path starting from root node to any node.

Input format
First line contains an integer t - Number of test cases.

First line of each test case contains an integer n - Number of nodes.

Second line of each test case contains n integers - Value of nodes.

Next n lines contain 3 space separated integers i, l, r describing left and right child of ith node as l and r respectively.
```
##### Output format
```
Print the maximum sum for each test case in a different line.
```
##### Sample Input 1
```
2

6

20 40 -70 -50 60 30

1 2 3

2 -1 4

3 5 6

4 -1 -1

5 -1 -1

6 -1 -1

1

-10

1 -1 -1
```

##### Sample Output 1
```
60

-10
```

##### Explanation
```
First test case:

Tree View:
          20
         /  \
        /    \
       /      \
     40       -70
       \      /  \
      -50    60   30

Total 6 paths are possible with sum = [20,60,10,-50,10,-20]. The maximum sum is 60 on path (20) -> (40).
```
##### Second test case:
```
Tree View:
-10


Only 1 path is possible starting from root with sum = -10.
```
##### Constraints
```
1 <= t <= 10

1 <= n <= 10^5

-10000 <= value of nodes <= 10000
```
