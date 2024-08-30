# Question : [Delete Node in a Linked List - (LeetCode : 237)](https://leetcode.com/problems/delete-node-in-a-linked-list/description/)

There is a singly-linked list `head` and we want to delete a node `node` in it.

You are given the `node`. You will **not be given access** to the first node of `head`.

All the values of the linked list are **unique**, and it is guaranteed that the given node `node` is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

-   The value of the given node should not exist in the linked list.
-   The number of nodes in the linked list should decrease by one.
-   All the values before `node` should be in the same order.
-   All the values after `node` should be in the same order.

**Custom testing**:

For the input, you should provide the entire linked list `head` and the node to be given `node`. `node` should not be the last node of the list and should be an actual node in the list.
We will build the linked list and pass the node to your function.
The output will be the entire list after calling your function.

### Example 1

![](https://assets.leetcode.com/uploads/2020/09/01/node1.jpg)

```
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
```

### Example 2

![](https://assets.leetcode.com/uploads/2020/09/01/node2.jpg)

```
Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.
```

### Constraints

-   The number of nodes in the list is in the range `[2, 1000].`
-   `-1000 <= Node.val <= 1000`
-   The value of each node in the list is **unique**.
-   The `node` to be deleted is **in the list** and is **not a tail** node.

## Solution

```Cpp
Approach : Using Slow & Fast Pointer Technique

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Check if the node to be deleted is NULL or if it's the last node.
        // Deletion cannot be performed in these cases.
        if (node == NULL || node->next == NULL) {
            return;
        }

        // Store the next node in a temporary pointer.
        ListNode* temp = node->next;

        // Copy the value from the next node to the current node.
        // This effectively overwrites the current node's value with the next node's value.
        node->val = temp->val;

        // Update the current node's next pointer to skip over the next node.
        // This effectively removes the next node from the list.
        node->next = temp->next;

        // Delete the temporary node to free up the memory.
        delete temp;
    }
};

Time Complexity = O(1)
Space Complexity = O(1)
```
