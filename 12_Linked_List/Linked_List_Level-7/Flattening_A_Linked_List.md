# Question : [Flattening a Linked List - GFG](https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1)

Given a Linked List, where every node represents a sub-linked-list and contains two pointers:
(i) a `next` pointer to the next node,
(ii) a `bottom` pointer to a linked list where this node is head.
Each of the sub-linked lists is in sorted order.
Flatten the Link List so all the nodes appear in a single level while maintaining the sorted order.

**Note**: The flattened list will be printed using the `bottom pointer` instead of the next pointer. Look at the printList() function in the driver code for more clarity.

### Example 1

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700192/Web/Other/blobid0_1722066129.png)

```
Output:  5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation: The resultant linked lists has every node in a single level.(Note: | represents the bottom pointer.)
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700192/Web/Other/blobid1_1722066171.png)

```
Output: 5-> 7-> 8-> 10-> 19-> 22-> 28-> 30-> 50
Explanation: The resultant linked lists has every node in a single level.(Note: | represents the bottom pointer.)
```

**Note**: In the output section of the above examples, the -> represents the bottom pointer.

```
Expected Time Complexity: O(n * n * m)
Expected Auxiliary Space: O(n)
```

### Constraints

-   `0 <= number of nodes <= 50`
-   `1 <= no. of nodes in sub-LinkesList(mi) <= 20`
-   `1 <= node->data <= 10^3`

## Solution

```Cpp
class Solution {
public:
    Node* mergeTwoLists(Node* list1, Node* list2) {
        // Base cases1: If list1 is empty, return list2 as the merged list.
        if(list1 == NULL) return list2;

        // Base cases2: If list2 is empty, return list1 as the merged list.
        if(list2 == NULL) return list1;

        // Create a dummy node to serve as the starting point of the merged list.
        // This simplifies handling edge cases, such as when the first node of list1 or list2 is the smallest.
        Node* head = new ListNode(0);

        // 'tail' is a pointer that will keep track of the last node in the merged list as we build it.
        Node* tail = head;

        // While neither list1 nor list2 is empty, compare their current nodes and append the smaller one to the merged list.
        while(list1 && list2) {
            // If the current value in list1 is smaller or equal, add list1's node to the merged list.
            if(list1->val <= list2->val) {
                tail->next = list1;  // Attach list1's current node to the merged list.
                list1 = list1->next; // Move to the next node in list1.
                tail = tail->next;   // Move the 'tail' pointer to the newly added node.
                tail->next = NULL;   // Ensure the next pointer of the newly added node is set to NULL.
            }
            else {
                // If the current value in list2 is smaller, add list2's node to the merged list.
                tail->next = list2;  // Attach list2's current node to the merged list.
                list2 = list2->next; // Move to the next node in list2.
                tail = tail->next;   // Move the 'tail' pointer to the newly added node.
                tail->next = NULL;   // Ensure the next pointer of the newly added node is set to NULL.
            }
        }

        // After the while loop, one of the lists might still have nodes left.
        // We simply attach the remaining part of the non-empty list to the merged list.

        // If there are remaining nodes in list1, attach them to the merged list.
        if(list1) {
            tail->next = list1;
        }

        // If there are remaining nodes in list2, attach them to the merged list.
        if(list2) {
            tail->next = list2;
        }

        // The first node of the merged list is the dummy node we created initially.
        // We need to move the head pointer to the actual first node of the merged list.
        tail = head;        // Temporarily store the dummy node in 'tail'.
        head = head->next;  // Move 'head' to the first real node of the merged list.

        // Delete the dummy node to free up memory.
        delete tail;

        // Return the head of the merged list.
        return head;
    }

    // Flattens a multilevel linked list by merging each level into a single sorted list
    Node *flatten(Node *root) {
        // If the root is NULL, return NULL as there is nothing to flatten
        if(root == NULL)
            return NULL;

        Node* head1 = NULL;  // Pointer for the first list to be merged
        Node* head2 = NULL;  // Pointer for the second list to be merged
        Node* head3 = NULL;  // Pointer to keep track of the remaining list

        // Traverse through the list, merging two lists at a time.
        while(root->next) {
            head1 = root;             // First list to be merged
            head2 = root->next;       // Second list to be merged
            head3 = root->next->next; // Remaining list to be merged later

            head1->next = NULL; // Disconnect  the first list from the remaining lists
            head2->next = NULL; // Disconnect  the second list from the remaining lists

            // Merge head1 and head2 into a single list, and update root to the merged list.
            root = mergeTwoLists(head1, head2);

            // Attach the remaining list to the merged list
            root->next = head3;
        }
        // Return the root of the flattened list.
        return root;
    }
};

Time Complexity = O(n^2 * m)
Space Complexity = O(1)
```
