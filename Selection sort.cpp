#include <bits/stdc++.h> 
void selectionSort(vector<int>& arr, int n)
{   
    // Write your code here.
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            min=j;
        }
        swap(arr[min],arr[i]);
    }
}

The given code implements selection sort, which sorts a vector of integers in ascending order. It iterates over the vector
from the first element to the second last element, and for each iteration, it finds the minimum element in the unsorted part of the vector. 
 The minimum element is then swapped with the current element, so that it is placed in the correct position in the sorted part of the vector. The function takes a reference to the vector
and its size as parameters, and returns the sorted vector. Overall, selection sort has a time complexity of O(n^2) and a space complexity of O(1).

#  QuestionProblem Statement

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
1
5
6 2 8 4 10
Sample Output 1:
2 4 6 8 10
Explanation :
In the first step, the minimum element is 2. Thus it is swapped with the starting element of the unsorted region.
In the second step, 4 is the minimum element. Now, it is swapped with the starting element of the unsorted region.
Similarly, in the third step, the minimum element is 6, which is swapped accordingly.
In the final step, all elements are arranged as per the non-decreasing order. Thus the array is sorted. 
Sample Input 2:
2
2
1 2
4
4 3 2 1
Sample Output 2:
1 2
1 2 3 4

