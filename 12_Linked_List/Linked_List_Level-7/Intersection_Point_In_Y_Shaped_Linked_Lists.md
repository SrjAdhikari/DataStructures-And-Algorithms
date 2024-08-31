# Question : [Intersection Point in Y Shaped Linked Lists - GFG](https://www.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1)

Given two singly linked lists, return the point where two linked lists intersect.

**Note**: If the linked lists do not merge at any point, return -1.

### Example 1

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700163/Web/Other/blobid1_1721764552.png)

```
Input: Linked list 1: 4->4->4->4->4, Linked list 2: 4->4->4
Output: 4
Explanation: From the above image, it is clearly seen that the common part is 4->4 whose starting point is 4.
```

### Example 2

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700163/Web/Other/blobid0_1721764467.png)

```
Input: Linked list 1: 4->1->8->4->5, Linked List 2: 5->6->1->8->4->5
Output: 8
Explanation: From the above image, it is clearly seen that the common part is 8->4->5 whose starting point is 8.
```

### Example 3

```
Input: Linked list 1: 1->2->3, Linked list 2: 4->5->6
Output: -1
Explanation: There is no common part, so there is no interaction point.
```

```
Expected Time Complexity :  O(n + m)
Expected Auxiliary Space :  O(n)
```

### Constraints

-   `2 ≤ size of first linkedist + size of second linkedlist ≤ 2*10^5`
-   `1000 ≤ data of nodes ≤ 1000`

**Challenge** : Try to solve the problem without using any extra space.

## Solution

```Cpp
Approach : Slow & Fast Pointer Technique

class Solution {
public:
    // Function to find intersection point in Y shaped Linked Lists.
    int intersectPoint(Node* head1, Node* head2) {
        // Traverse the first linked list (head1) to the end.
        Node* temp1 = head1;    // Create a temporary pointer to traverse the first linked list

        // Traverse to the end of the first linked list
        while(temp1->next) {
            temp1 = temp1->next;
        }

        // Create a cycle by connecting the last node of the first list to the head of the first list.
        temp1->next = head1;

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
            return -1;

        // Reset the slow pointer to the head of the second list to find the intersection point
        slow = head2;

        // Move both pointers one step at a time until they meet at the intersection point
        while(slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        // The node where slow and fast meet is the intersection point. Remove the cycle
        // Restore the list by breaking the cycle
        temp1->next = NULL;

        // Return the data at the intersection point
        return slow->data;
    }
};

Time Complexity = O(n + m)
Space Complexity = O(1)
```
