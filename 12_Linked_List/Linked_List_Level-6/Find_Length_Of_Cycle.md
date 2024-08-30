# Question : [Find length of Loop - GFG](https://www.geeksforgeeks.org/problems/find-length-of-loop/1)

Given the head of a linked list, determine whether the list contains a loop. If a loop is present, **return the number of nodes** in the loop, otherwise **eturn 0**.

![](https://contribute.geeksforgeeks.org/wp-content/uploads/linkedlist.png)

**Note**: 'c' is the position of the node which is the next pointer of the last node of the linkedlist. If c is 0, then there is no loop.

### Example 1

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700620/Web/Other/blobid0_1722797558.png)

```
Input: LinkedList: 25->14->19->33->10->21->39->90->58->45, c = 4
Output: 7
Explanation: The loop is from 33 to 45. So length of loop is 33->10->21->39-> 90->58->45 = 7.
The number 33 is connected to the last node of the linkedlist to form the loop because according to the input the 4th node from the beginning(1 based indexing)
will be connected to the last node for the loop.
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700620/Web/Other/blobid3_1722798030.png)

```
Input: LinkedList: 5->4, c = 0
Output: 0
Explanation: There is no loop.
```

```
Expected Time Complexity :  O(n)
Expected Auxiliary Space :  O(1)
```

### Constraints

`1 <= no. of nodes <= 10^6` <br>
`0 <= node.data <= 10^6` <br>
`0 <= c <= n-1`

## Solution

```Cpp

class Solution {
public:
    int countNodesinLoop(Node *head) {
        // Initialize two pointers, slow and fast, both pointing to the head of the linked list.
        ListNode* slow = head;
        ListNode* fast = head;

        // Iterate through the linked list as long as the fast pointer and the node after the fast pointer are not null.
        // This ensures that 'fast' and 'fast->next' are valid nodes.
        while(fast && fast->next) {
            // Move the slow pointer one step forward.
            slow = slow->next;

            // Move the fast pointer two steps forward.
            fast = fast->next->next;

            // Check if the 'slow' pointer and 'fast' pointer meet at the same node.
            // If they do, it means there is a cycle in the linked list.
            if(slow == fast)
                break; // Exit the loop as soon as a cycle is detected.
        }

        // If 'fast' reaches the end of the list (i.e., 'fast' is NULL or 'fast->next' is NULL),
        // there is no cycle in the list.
        if(fast == NULL || fast->next == NULL)
            return 0; // Return 0 indicating no cycle in the list.

        // Initialize the count of nodes in the loop.
        int count = 1;

        // Move the 'slow' pointer to the node next to where 'fast' is currently pointing.
        slow = fast->next;

        // Traverse the loop to count the number of nodes in the cycle.
        while(slow != fast) {
            count++;            // Increment the count of nodes in the loop.
            slow = slow->next;  // Move 'slow' one step forward.
        }
        return count;           // Return the total count of nodes in the loop.
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
