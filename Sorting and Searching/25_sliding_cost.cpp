/*
Time limit: 1.00 s Memory limit: 512 MB
You are given an array of n integers. Your task is to calculate for each window of k elements, from left to right, the minimum total cost of making all elements equal.

You can increase or decrease each element with cost x where x is the difference between the new and the original value. The total cost is the sum of such costs.

Input

The first input line contains two integers n and k: the number of elements and the size of the window.

Then there are n integers x1,x2,…,xn: the contents of the array.

Output

Output n−k+1 values: the costs.

Constraints
1≤k≤n≤2⋅105
1≤xi≤109
Example

Input:
8 3
2 4 3 5 8 1 2 1

Output:
2 2 5 7 7 1
*/