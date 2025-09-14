#### Problem Description
```
Given a set of N Countries which are numbered from 1 to N, split the Countries into two groups, of any size, such that the following condition is met.

If a Country dislikes another Country, they should not be in the same group. If dislikes[i] = [a, b], we should not put Country numbered a and Country numbered b into the same group.

Print out if this kind of partitioning is possible or not.
```
##### Input format
```
First line contains a single integer T, which is the number of test cases.

For each test case, we’ll see the following lines:

First line contains two space separated integers N and M, where N denotes the number of countries in the list and M denotes the number of dislikes between countries.

Next M lines contain two space separated integers each, which denote the country numbers that dislike each other. Countries are numbered from 1 to N.
```

##### Output format
```
For each test case, output in a new line, "Possible" without quotes if and only if it is possible to split every Country into the two groups, otherwise print "Not Possible" without quotes.
```
##### Constraints
```
1 <= T <= 1000

0 <= N <= 100000

0 <= M <= min((N*(N-1))/2,100000)
```
##### Sample Input 1
```
1

5 4

2 1

1 3

4 2

2 5
```
##### Sample Output 1
```
Possible
```
##### Explanation 1
```
        ---->4
       |
1----->2
|      |
|       ---->5
|
------>3

The partitioning that works is this {1,4,5} and {2,3}
```
##### Sample Input 2
```
1

3 3

2 1

1 3

2 3
```

##### Sample Output 2
```
Not Possible
```
##### Explanation 2
```
It is not possible to partition these three countries into two groups according to the condition.
```
