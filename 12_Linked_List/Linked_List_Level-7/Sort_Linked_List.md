# Question : [Sort List - (LeetCode : 148)](https://leetcode.com/problems/sort-list/description/)

Given the `head` of a linked list, return _the list after sorting it in_ **_ascending order_**.

### Example 1

![](https://assets.leetcode.com/uploads/2020/09/14/sort_list_1.jpg)

```
Input: head = [4,2,1,3]
Output: [1,2,3,4]
```

### Example 2

![](https://assets.leetcode.com/uploads/2020/09/14/sort_list_2.jpg)

```
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
```

### Example 3

```
Input: head = []
Output: []
```

### Constraints

-   The number of nodes in both lists is in the range `[0, 5 * 10^4].`
-   `-10^5 <= Node.val <= 10^5`

## Solution

```Cpp
Approach : Using Merge Sort

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base cases1: If list1 is empty, return list2 as the merged list.
        if(list1 == NULL) return list2;

        // Base cases2: If list2 is empty, return list1 as the merged list.
        if(list2 == NULL) return list1;

        // Create a dummy node to serve as the starting point of the merged list.
        // This simplifies handling edge cases, such as when the first node of list1 or list2 is the smallest.
        ListNode* head = new ListNode(0);

        // 'tail' is a pointer that will keep track of the last node in the merged list as we build it.
        ListNode* tail = head;

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

    // Function to find and return the middle node of a linked list using the slow and fast pointer technique
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;          // Slow pointer starts at the head of the list.
        ListNode* fast = head->next;    // Fast pointer starts at the node after the head.

        // Traverse the list with the 'fast' pointer moving twice as fast as the 'slow' pointer
        while (fast && fast->next) {
            slow = slow->next;           // Move 'slow' one step forward
            fast = fast->next->next;     // Move 'fast' two steps forward
        }

        // When 'fast' reaches the end of the list (or becomes NULL), 'slow' will be at the middle node
        return slow;
    }

    // Function to perform merge sort on a linked list.
    // This function recursively divides the list into halves and merges the sorted halves.
    ListNode* mergeSort(ListNode* head) {
        // Base case: if the list is empty or has only one element, return the head.
        if (head == NULL || head->next == NULL)
            return head;

        // Find the middle of the list.
        ListNode* mid = findMid(head);

        // Split the list into two halves.
        ListNode* leftStart = head;         // Start of the left half.
        ListNode* rightStart = mid->next;   // Start of the right half.

        // Disconnect the two halves.
        mid->next = NULL;                   // End the left half of the list.

        // Recursively sort the two halves.
        leftStart = mergeSort(leftStart);
        rightStart = mergeSort(rightStart);

        // Merge the two sorted halves into a single sorted list.
        return mergeLinkedList(leftStart, rightStart);
    }

    // Function to sort a linked list using merge sort.
    ListNode* sortList(ListNode* head) {
        // Call mergeSort to sort the list.
        head = mergeSort(head);

        // Return the head of the sorted list.
        return head;
    }
};

Time Complexity = O(nlog(n))
Space Complexity = O(log(n))
```
