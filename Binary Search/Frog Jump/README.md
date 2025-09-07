### Problem Description


```
A frog has to cross a river. The river has a path of floating stones on which the frog can jump and cross the river.
There are n stones in the path to cross the river. First stone in the path to cross the river is numbered 1 and the last stone is numbered n. 
But some of the stones out of these n stones are flawed and they sink when the frog jumps on them, therefore the frog cant jump on those stones.
One jump takes 1 unit of time and the frog wants to cross the river in at most k units of time. Frog is initially at one side of the river (i.e 0th stone).
You are given an array in which you are provided the indices of the flawed stones.
Your task is to minimize the maximum jump size (i.e the number of stones he skips in one jump) that the frog should take to reach the other end of the river 
(i.e to n+1 stone ) in at most k unit of time.
```

#### Input format

```
First line has two space separated integers n and k representing the total no of stones in the path to cross the river and the maximum time that can be taken respectively.

Next line contains a single integer m denoting the size of the array which contains the index of the flawed stones.

Next line contains m space separated integers which are the index of the flawed stones.
```

#### Output format

```
A single line representing the minimum jump size that the frog should take to reach the other end (i.e n+1 stone) in at most k units of time, if not possible then return -1.
```

#### Sample Input 1

```
5 3

2

2 3
```

#### Sample Output 1

```
3
```

#### Explanation

```
If frog takes jump of size 1 or 2, then it is not possible to cross a river, because stone 2 and 3 are flawed, jump of size atleast 3 is required to go from stone 1 to stone 4.

If frog takes jump of size 3, then one of the possible way to cross a river is as follows:

First the frog will jump on stone 1 (1-0=1).

Second the frog will jump on stone 4 which is jump of size (4-1=3).

Third frog will jump on the other side of the river(i.e 6th stone) (6-4=2).
```

#### Constraints

```
1 <= k,n <= 5*1e5

1 <= m <= n

1 <= a[i] <= n
```
