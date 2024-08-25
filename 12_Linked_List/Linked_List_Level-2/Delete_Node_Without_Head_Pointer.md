# Question : [Delete without head pointer - GFG](https://www.geeksforgeeks.org/problems/delete-without-head-pointer/1)

You are given a node **del_node** of a Singly Linked List where you have to **delete** a **value** of the given node from the linked list but you are not given the **head** of the list.

By deleting the node value, we do not mean removing it from memory. We mean:

-   The value of the given node should not exist in the linked list.
-   The number of nodes in the linked list should decrease by one.
-   All the values before & after the del_node node should be in the same order.

### Note:

    1. Multiple nodes can have the same values as the del_node, but you must only remove the node whose pointer del_node is given to you.
    2. It is guaranteed that there exists a node with a value equal to the del_node value and it will **not be the last node** of the linked list.

### Example 1

```
Input: Linked List = 1 -> 2, del_node = 1
Output: 2
Explanation: After deleting 1 from the linked list, we have remaining nodes as 2.
```

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700161/Web/Other/blobid0_1724435615.png)

### Example 2

```
Input: Linked List = 10 -> 20 -> 4 -> 30, del_node = 20
Output: 10->4->30
Explanation: After deleting 20 from the linked list, we have remaining nodes as 10, 4, 30.
```

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700161/Web/Other/blobid1_1724435635.png)

```
Expected Time Complexity: O(1).
Expected Auxilliary Space: O(1).
```

**Note**: This recursive solution lead to a time limit exceeded (TLE) error on large inputs because of the exponential time complexity. In the future, we will solve this problem using dynamic programming to optimize the solution and pass all test cases.

### Constraints

`2 <= number of nodes <= 10^6  `
`1 <= node->data <= 10^6`

## Solution

```Cpp
class Solution {
public:
    void deleteNode(Node* curr) {
        // Check if the current node is not NULL
        if (curr == NULL || curr->next == NULL) {
            // Cannot delete the node or it's the last node in the list
            cout << "Invalid operation: Node to delete is NULL or the next node is NULL." << endl;
            return;
        }

        // Pointer to the node that will be deleted
        Node* temp = curr->next;

        // Copy the data from the next node to the current node
        curr->data = temp->data;

        // Update the current node's next pointer to skip the node to be deleted
        curr->next = temp->next;

        // Delete the node that has been skipped
        delete temp;
    }
};

Time Complexity = O(1)
Space Complexity = O(1)
```
