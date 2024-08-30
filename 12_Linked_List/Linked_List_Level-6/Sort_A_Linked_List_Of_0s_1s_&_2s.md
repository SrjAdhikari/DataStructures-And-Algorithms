# Question : [Sort a linked list of 0s, 1s and 2s - GFG](https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1)

Given a linked list where nodes can contain values `0s`, `1s`, and `2s` only. The task is to segregate `0s`, `1s`, and `2s` linked list such that all zeros segregate to the head side, 2s at the end of the linked list, and 1s in the middle of 0s and 2s.

### Example 1

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700028/Web/Other/blobid1_1723665173.png)

```
Input: LinkedList: 1->2->2->1->2->0->2->2
Output: 0->1->1->2->2->2->2->2
Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700028/Web/Other/blobid0_1723665157.png)

```
Input: LinkedList: 2->2->0->1
Output: 0->1->2->2
Explanation: After arranging all the 0s,1s and 2s in the given format, the output will be 0 1 2 2.
```

### Your Task:

The task is to complete the function `deleteK()` which takes `head` of linked list and integer `k` as input parameters and delete every `kth` node from the linked list and return its head.

```
Expected Time Complexity :  O(n)
Expected Auxiliary Space :  O(n)
```

### Constraints

`1 <= no. of nodes <= 10^6`
`0 <= node->data <= 2`

## Solution

```Cpp

class Solution {
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        // Pointer to traverse the linked list.
        Node* curr = head;

        // Initialize counters for the number of nodes with values 0, 1, and 2.
        int zeroCount = 0, oneCount = 0, twoCount = 0;

        // Traverse the linked list to count the number of 0s, 1s, and 2s.
        while(curr) {
            // Check the value of the current node and increment the corresponding counter.
            if(curr->data == 0)
                zeroCount++; // Increment zeroCount for each node with value 0.

            else if(curr->data == 1)
                oneCount++;  // Increment oneCount for each node with value 1.

            else
                twoCount++;  // Increment twoCount for each node with value 2.

            // Move to the next node in the linked list.
            curr = curr->next;
        }

        // Reset the pointer to the head of the list to start updating node values.
        curr = head;

        // Update the nodes in the linked list to have all 0s first.
        while(zeroCount > 0) {
            curr->data = 0;     // Set the data of the current node to 0.
            curr = curr->next;  // Move to the next node in the list.
            zeroCount--;        // Decrement the zeroCount as one 0 has been placed.
        }

        // Update the nodes to have all 1s after the 0s.
        while(oneCount > 0) {
            curr->data = 1;     // Set the data of the current node to 1.
            curr = curr->next;  // Move to the next node in the list.
            oneCount--;         // Decrement the oneCount as one 1 has been placed.
        }

        // Update the nodes to have all 2s after the 1s.
        while(twoCount > 0) {
            curr->data = 2;     // Set the data of the current node to 2.
            curr = curr->next;  // Move to the next node in the list.
            twoCount--;         // Decrement the twoCount as one 2 has been placed.
        }

        // Return the head of the modified linked list where nodes are segregated by their values.
        return head;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
