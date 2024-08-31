# Question : [Reverse a Linked List in Groups - GFG](https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1)

Given a linked list, the task is to reverse every `k` node (where k is an input to the function) in the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should be considered as a group and must be reversed (See Example 2 for clarification).

### Example 1

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700013/Web/Other/blobid0_1723298986.png)

```
Input: Linked List: 1->2->2->4->5->6->7->8, k = 4
Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5
Explanation: The first 4 elements 1,2,2,4 are reversed first and then the next 4 elements 5,6,7,8.
Hence, the resultant linked list is 4->2->2->1->8->7->6->5.
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700013/Web/Other/blobid1_1723298995.png)

```
Input: LinkedList: 1->2->3->4->5, k = 3
Output: 3 -> 2 -> 1 -> 5 -> 4
Explanation: The first 3 elements 1,2,3 are reversed first and then element 4,5 are reversed.
Hence, the resultant linked list is 3->2->1->5->4.
```

```
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
```

### Constraints

-   `1 <= size of linked list <= 10^6`
-   `1 <= data of nodes <= 10^6`
-   `1 <= k <= size of linked list`

## Solution 1

```Cpp
class Solution {
public:
    node* reverseIt(node* head, int k) {
        // Base case: If the head is NULL, return NULL
        if (head == NULL) {
            return NULL;
        }

        // Initialize pointers for reversal.
        node* curr = head;      // The current node in the list
        node* prev = NULL;      // Pointer to the previous node (start as NULL for the first node).
        node* next = NULL;      // Pointer to the next node of "curr"
        int count = 0;          // Counter to keep track of nodes processed

        // Step 1: Reverse the first k nodes
        while (curr != NULL && count < k) {
            next = curr->next;    // Store the next node (to avoid losing it).
            curr->next = prev;    // Reverse the link: make the current node point to the previous node.
            prev = curr;          // Move 'prev' to the current node (current node becomes the previous one for the next iteration).
            curr = next;          // Move to the next node in the original list.
            count++;              // Increment the counter.
        }

        // Step 2: Recursively reverse the rest of the list after k nodes and link it to the end of the reversed segment.
        if (next != NULL) {
            head->next = reverseIt(curr, k);
        }

        // Step 3: // Return the new head of the reversed segment (prev is the new head after reversal).
        return prev;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```

## Solution 2

```Cpp
class Solution {
public:
    node* reverseIt(node* head, int k) {
        // Create a dummy node to simplify edge cases like reversing the head of the list
        node* first = new node(0);          // Dummy node
        first->next = head;                 // Point dummy node to the current head
        head = first;                       // Update head to point to the dummy node

        // Iterate through the list to reverse nodes in groups of k
        while (first->next) {
            int count = k;                  // Counter for the number of nodes to reverse in this group
            node* second = first->next;     // Start of the current group to reverse
            node* prev = first;             // Node before the current group
            node* curr = first->next;       // Current node in the group to reverse

            // Reverse k nodes in the current group
            while (times && curr) {
                node* next = curr->next;    // Save the next node
                curr->next = prev;          // Reverse the link
                prev = curr;                // Move prev forward
                curr = next;                // Move curr forward
                count--;                    // Decrement the counter
            }

            // Connect the reversed group with the rest of the list
            first->next = prev;             // Connect the previous part to the new head of the reversed segment
            second->next = curr;            // Connect the end of the reversed segment to the remaining list
            first = second;                 // Move first to the end of the reversed segment for the next iteration
        }

        // Restore the original head by removing the dummy node
        first = head;                       // Point first to the dummy node
        head = head->next;                  // Update head to the new head of the list
        delete first;                       // Delete the dummy node to free memory

        return head;                        // Return the new head of the reversed list
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
