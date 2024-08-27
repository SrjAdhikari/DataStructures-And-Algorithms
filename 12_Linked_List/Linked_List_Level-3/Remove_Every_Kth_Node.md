# Question : [Remove every kth node - GFG](https://www.geeksforgeeks.org/problems/remove-every-kth-node/1)

Given a singly linked list having `n` nodes, your task is to remove every `kth` node from the linked list.

### Example 1

```
Input:
n = 8
linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8
k = 2
Output:
1 -> 3 -> 5 -> 7
Explanation:
After removing every 2nd node of the linked list, the resultant linked list will be: 1 -> 3 -> 5 -> 7.
```

### Example 2

```
Input:
n = 10
linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10
k = 3
Output:
1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10
Explanation:
After removing every 3rd node of the linked list, the resultant linked list will be: 1 -> 2 -> 4 -> 5 -> 7 -> 8 -> 10.
```

### Your Task:

The task is to complete the function `deleteK()` which takes `head` of linked list and integer `k` as input parameters and delete every `kth` node from the linked list and return its head.

```
Expected Time Complexity :  O(n)
Expected Auxiliary Space :  O(1)
```

### Constraints

`1 <= n <= 10^5`
`-10^9 <= elements of linked list <= 10^9`
`1 <= k <= n`

## Solution

```Cpp

class Solution {
public:
    // Function to delete every K-th node from the linked list
    Node* deleteK(Node *head, int K) {
        Node* prev = NULL;  // Pointer to keep track of the previous node
        Node* curr = head;  // Pointer to traverse the linked list
        int count = 1;      // Counter to keep track of the position of the current node

        // Edge case: If K is 1, all nodes need to be deleted. Return NULL (empty list)
        if (K == 1) {
            return NULL;    // Return NULL as the resulting list will be empty
        }

        // Traverse the list to process each node
        while (curr) {
            // Check if the current node is the K-th node
            if (count == K) {
                // Delete the K-th node
                prev->next = curr->next;    // Bypass the K-th node by linking prev to the node after curr
                delete curr;                // Deallocate memory of the K-th node
                curr = prev->next;          // Move curr to the next node after the deleted node
                count = 1;                  // Reset the counter after deletion
            } else {
                // Move to the next node
                prev = curr;                // Update prev to be the current node
                curr = curr->next;          // Move curr to the next node
                count++;                    // Increment the counter
            }
        }
        return head;                        // Return the updated head of the list
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
