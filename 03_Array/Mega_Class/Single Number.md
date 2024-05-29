# Question : [Single Number - (LeetCode : 136)](https://leetcode.com/problems/single-number/description/?source=submission-ac)

Given a **non-empty** array of integers `nums`, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

### Example 1

```plaintext
Input: nums = [2,2,1]
Output: 1
```

### Example 2

```plaintext
Input: nums = [4,1,2,1,2]
Output: 4
```

### Example 3

```plaintext
Input: nums = [1]
Output: 1
```

### Constraints

`1 <= nums.length <= 3 * 10^4`

`-3 * 104 <= nums[i] <= 3 * 10^4`

`Each element in the array appears twice except for one element which appears only once.`

### Follow up

How can we prove that at least one duplicate number must exist in `nums`?

Can you solve the problem in linear runtime complexity?

## Solution 1

```Cpp
Using XOR Operator :

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;
        int size = nums.size();

        for(int i = 0; i < size; i++){
            ans = ans ^ nums[i];
        }

        return ans;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```

## Solution 2

```Cpp
Using Hash Table : 

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freqMap;    // Create a hash table to store frequency of each number
        
        // Add frequency of numbers to the hash table
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            freqMap[num]++;
        }

        unordered_map<int, int>::iterator it;   // Iterator for traversing the hash table
        int ans;                                // Variable to store the single number
        
        // Iterate through the hash table
        for (it = freqMap.begin(); it != freqMap.end(); it++) {
            int key = it->first;        // Get the key (number)
            int freq = it->second;      // Get the frequency
            
            // If frequency is 1, it means this is the single number
            if (freq == 1) {
                ans = key;      // Store the single number
                break;          // Break out of the loop as we have found the single number
            }
        }
        return ans;             // Return the single number
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```