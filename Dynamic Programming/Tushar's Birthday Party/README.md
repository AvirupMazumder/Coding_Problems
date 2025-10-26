#### Problem Description
```
As it is Tushar's Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune. Given are the eating capacity of each friend, the filling capacity of each dish and the cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar's friends are satisfied (reached their eating capacity).

NOTE:
Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish an unlimited number of times.
There always exists a dish with a filling capacity of 1 so that a solution always exists.
```

##### Problem Constraints
```
1 <= Capacity of friend <= 1000
1 <= No. of friends <= 1000
1 <= No. of dishes <= 1000
```

##### Input Format
```
Friends: A: List of integers denoting eating capacity of friends separated by space.
Capacity: B: List of integers denoting filling capacity of each type of dish.
Cost: C: List of integers denoting cost of each type of dish.
```

##### Example Input
```
A = [4, 6]
B = [1, 3]
C = [5, 3]
```

##### Example Output
```
14
```

##### Example Explanation
```
The first friend will take 1st and 2nd dish, the second friend will take 2nd dish twice. Thus, total cost = (5+3)+(3*2)= 14
```
