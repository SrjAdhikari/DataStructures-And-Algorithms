# Question : [Merge Two Sorted Lists - (LeetCode : 21)](https://leetcode.com/problems/merge-two-sorted-lists/description/)

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return _the head of the merged linked list_.

### Example 1

![](https://assets.leetcode.com/uploads/2020/10/03/merge_ex1.jpg)

```
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
```

### Example 2

```
Input: list1 = [], list2 = []
Output: []
```

### Example 3

```
Input: list1 = [], list2 = [0]
Output: [0]
```

### Constraints

-   The number of nodes in both lists is in the range `[0, 50].`
-   `-100 <= Node.val <= 100`
-   Both `list1` and `list2` are sorted in **non-decreasing** order.

## Solution

```Cpp
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
};

Time Complexity = O(N + M)
Space Complexity = O(1)
=> Where 'N' is the length of 'list1' and 'M' is the length of 'list2'
```
