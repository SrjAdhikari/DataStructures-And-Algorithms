# Question : [First non-repeating character in a stream - GFG](https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1)

Given an input stream `A` of `n` characters consisting only of lower case alphabets. While reading characters from the stream, you have to tell which character has appeared only once in the stream upto that point. If there are many characters that have appeared only once, you have to tell which one of them was the first one to appear. If there is no such character then append '#' to the answer.

**NOTE**
1. You need to find the answer for every i (0 <= i < n)
2. In order to find the solution for every i you need to consider the string from starting position till ith position.

### Example 1

```
Input: A = "aabc"
Output: "a#bb"
Explanation: For every ith character we will
consider the string from index 0 till index i first non
repeating character is as follow-
"a" - first non-repeating character is 'a'
"aa" - no non-repeating character so '#'
"aab" - first non-repeating character is 'b'
"aabc" - there are two non repeating characters 'b' and 'c', 
first non-repeating character is 'b' because 'b' comes before
'c' in the stream.
```

### Example 2

```
Input: A = "zz"
Output: "z#"
Explanation: For every character first non
repeating character is as follow-
"z" - first non-repeating character is 'z'
"zz" - no non-repeating character so '#'
```

### Your Task:

You don't need to read or print anything. Your task is to complete the function `FirstNonRepeating()` which takes A as input parameter and returns a string after processing the input stream.

```
Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)
```

### Constraints

`1 <= N <= 10^5`

## Solution

```Cpp
class Solution {
public:
    string FirstNonRepeating(string A) {
        // Create a map to store the frequency of each character in the stream.
        unordered_map<char, int> freq;
        
        // Create a queue to maintain the order of characters as they appear.
        queue<char> q;
        
        // Initialize an empty string to store the answer/result.
        string ans = "";
        
        // Loop through each character in the input string A.
        for (int i = 0; i < A.length(); i++) {
            freq[A[i]]++;  // Increment the frequency of the current character.
            q.push(A[i]);  // Push the current character into the queue.
            
            // Check the front of the queue for the first non-repeating character.
            while (!q.empty()) {
                // Check if the front character of the queue has a frequency of 1.
                if (freq[q.front()] == 1) {
                    // If it's non-repeating, add it to the result string.
                    ans.push_back(q.front());  

                    // Break out of the loop as we found the first non-repeating character.
                    break;
                }
                // If the front character has a frequency greater than 1 (repeating), pop it from the queue.
                else {
                    q.pop();
                }
            }
            
            // If the queue becomes empty, it means no non-repeating character exists at this point.
            // Append '#' to the result string.
            if (q.empty()) {
                ans.push_back('#');
            }
        }
        
        // Return the final result string containing the first non-repeating characters.
        return ans;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```