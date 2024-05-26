# Question : [Key Pair - GFG](https://www.geeksforgeeks.org/problems/key-pair5616/1)

```plaintext
Given an array Arr of N positive integers and another number X. Determine whether or not there exist two elements in Arr whose sum is exactly X.
```

### Example 1:
```plaintext
Input :
N = 6, X = 16
Arr[] = {1, 4, 45, 6, 10, 8}
Output: Yes
Explanation: Arr[3] + Arr[4] = 6 + 10 = 16
```

### Example 2 : 
```plaintext
Input :
N = 5, X = 10
Arr[] = {1, 2, 4, 3, 6}
Output: Yes
Explanation: Arr[2] + Arr[4] = 4 + 6 = 10
```

### Your Task:
You don't need to read input or print anything. Your task is to complete the function hasArrayTwoCandidates() which takes the array of integers arr, n and x as parameters and returns a boolean denoting the answer.

```plaintext
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
```

### Constraints:
```plaintext
1 ≤ N ≤ 105`
1 ≤ Arr[i] ≤ 105`
```


## Solution 1

```Cpp
Brute Force Approach :

class Solution{
public:	
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
        
	    for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(arr[i][j] == x){
                    return true;
                }
            }
            return false;
        }
	}
};

Time Complexity = O(n^2)
Space Complexity = O(1)
```

## Solution 2

```Cpp
Two pointer And Sorting Approach :

class Solution{
public:	
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
        
	    // Sort the given array
	    sort(arr, arr + n);
	    
	    int start = 0;
	    int end = n - 1;
	    
	    while(start < end){
	        if(arr[start] + arr[end] == x){
	            return true;
	        }
	        else if(arr[start] + arr[end] > x){
	            end--;
	        }
	        else{
	            start++;
	        }
	    }
	    return false;
	}
};

Time Complexity = O(nlogn) + O(n) => O(nlogn)
Space Complexity = O(1)
```