# Question : [Remove Duplicates from Sorted List - (LeetCode : 83)](https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/)

Given the `head` of a sorted linked list, _delete all duplicates such that each element appears only once. Return the linked list ***sorted*** as well_.

### Example 1

![](https://assets.leetcode.com/uploads/2021/01/04/list1.jpg)

```
Input: head = [1,1,2]
Output: [1,2]
```

### Example 2

![](https://assets.leetcode.com/uploads/2021/01/04/list2.jpg)

```
Input: head = [1,1,2,3,3]
Output: [1,2,3]
```

### Constraints

-   The number of nodes in the list is the range `[0, 300].`
-   `-100 <= Node.val <= 100`
-   The list is guaranteed to be **sorted** in ascending order.

## Solution 1

```Cpp
Approach : Brute-force (Using Extra-Space)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Check if the linked list is empty. If it's empty, return NULL because there's nothing to remove.
        if(head == NULL) {
            return NULL;
        }

        // Create a vector to store unique values encountered in the linked list.
        vector<int> ans;

        // Initialize a pointer 'curr' to traverse the linked list, starting from the head.
        ListNode* curr = head;

        // Since the head node is the first node, we add its value to the 'ans' vector.
        ans.push_back(curr->val);

        // Move 'curr' to the next node in the linked list.
        curr = head->next;

        // Traverse the linked list to collect only unique values.
        // This loop continues until 'curr' becomes NULL, indicating the end of the linked list.
        while(curr) {
            // 'n' stores the index of the last element in the 'ans' vector.
            int n = ans.size() - 1;

            // Check if the value of the current node ('curr->val') is different from
            // the last value stored in the 'ans' vector.
            // If it's different, it means this value is unique and should be added to 'ans'.
            if(ans[n] != curr->val) {
                ans.push_back(curr->val); // Add the unique value to 'ans'.
            }

            // Move 'curr' to the next node in the list.
            curr = curr->next;
        }

        // Now, we need to update the original linked list with the unique values collected in 'ans'.

        // Reset 'curr' to point to the head of the linked list to start updating it from the beginning.
        curr = head;

        // 'prev' will be used to keep track of the previous node while updating the list.
        ListNode* prev = NULL;

        // 'index' is used to iterate over the 'ans' vector.
        int index = 0;

        // Iterate through the 'ans' vector and update the linked list nodes with these unique values.
        while(index < ans.size())  {
            // Set the current node's value to the unique value from 'ans' at position 'index'.
            curr->val = ans[index];

            // Move to the next position in the 'ans' vector.
            index++;

            // Update 'prev' to be the current node.
            prev = curr;

            // Move 'curr' to the next node in the linked list.
            curr = curr->next;
        }

        // Set the next pointer of the last node to NULL to mark the end of the modified linked list
        prev->next = NULL;

        // Return the head of the modified linked list, which now contains only unique values.
        return head;
    }
};

Time Complexity = O(N)
Space Complexity = O(N)
```

## Solution 2

```Cpp
Approach : Without Using Extra Space (In-place)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Check if the linked list is empty or has only one node.
        // If either is true, return the head as there's nothing to remove.
        if(head == NULL || head->next == NULL) {
            return head;
        }

        // Initialize two pointers:
        // 'curr' starts at the second node and is used to traverse the list.
        // 'prev' starts at the first node and is used to track the last unique node.
        ListNode* curr = head->next;
        ListNode* prev = head;

        // Traverse the linked list until 'curr' becomes NULL (end of the list).
        while(curr) {
            // If the value of the current node is the same as the previous node's value,
            // it means 'curr' is a duplicate.
            if(curr->val == prev->val) {
                // To remove the duplicate, link 'prev->next' to 'curr->next',
                // bypassing the current (duplicate) node.
                prev->next = curr->next;

                // Delete the current node to free up memory.
                delete curr;

                // Move 'curr' to the next node (which was 'curr->next' before deletion).
                curr = prev->next;
            }
            else {
                // If 'curr' is not a duplicate, move both 'prev' and 'curr' one step forward.
                prev = prev->next;
                curr = curr->next;
            }
        }

        // Return the head of the modified linked list, which now has no duplicates.
        return head;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
