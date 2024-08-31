# Question : [Add Two Numbers - (LeetCode : 2)](https://leetcode.com/problems/add-two-numbers/description/)

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

### Example 1

![](https://assets.leetcode.com/uploads/2020/10/02/addtwonumber1.jpg)

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

### Example 2

```
Input: l1 = [0], l2 = [0]
Output: [0]
```

### Example 3

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

### Constraints

-   The number of nodes in each linked list is in the range `[1, 100]`.
-   `0 <= Node.val <= 9`
-   It is guaranteed that the list represents a number that does not have leading zeros.

## Solution 1

```Cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;   // Pointer to traverse the first linked list
        ListNode* curr2 = l2;   // Pointer to traverse the second linked list

        // Pointers for the result linked list.
        ListNode* head = NULL;  // Head of the resulting linked list.
        ListNode* tail = NULL;  // Tail to keep track of the end of the list.

        int sum = 0;            // Variable to store the sum of two digits and carry
        int carry = 0;          // Variable to store the carry for the next digit

        // Traverse both linked lists until all nodes are processed
        while (curr1 || curr2) {
            // Get the value of the current nodes or 0 if the node is NULL.
            int val1 = (curr1 ? curr1->val : 0);
            int val2 = (curr2 ? curr2->val : 0);

            // Calculate the sum of the two digits plus the carry from the previous digit.
            sum = val1 + val2 + carry;

            // If the result list is empty, create the first node
            if (!tail) {
                // If the result list is empty, initialize the head and tail with the new node.
                tail = new ListNode(sum % 10);
                head = tail;        // Set both head and tail to point to the new node.
            }
            // If the result list is not empty, append a new node to the end of the list.
            else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;  // Move the tail pointer to the new node.
            }

            // Update carry for the next iteration
            carry = sum / 10;

            // Move to the next nodes in both lists if they exist
            if (curr1) curr1 = curr1->next;
            if (curr2) curr2 = curr2->next;
        }

        // If there is a carry left after processing both lists, add a new node with the carry value
        if (carry) {
            tail->next = new ListNode(carry);
        }

        // Return the head of the result list
        return head;
    }
};

Time Complexity = O(max(m, n))
Space Complexity = O(max(m, n))
=> where m and n are the lengths of the input linked lists.
```

## Solution 2

```Cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Pointers to traverse the input linked lists.
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        // Create a dummy head node for the result linked list.
        // 'tail' will point to the end of the result list where we append new nodes.
        ListNode* head = new ListNode(0);
        ListNode* tail = head;

        // Variables to store the sum of the current digits and the carry for the next digit.
        int sum = 0;
        int carry = 0;

        // Traverse both linked lists as long as there are nodes in both lists.
        while (curr1 && curr2) {
            // Calculate the sum of the current digits plus the carry.
            sum = curr1->val + curr2->val + carry;

            // Create a new node with the digit value (sum % 10) and append it to the result list.
            tail->next = new ListNode(sum % 10);

            // Move to the next nodes in both input lists.
            curr1 = curr1->next;
            curr2 = curr2->next;

            // Move the tail pointer to the new node and update the carry.
            tail = tail->next;
            carry = sum / 10;   // Update carry for the next iteration.
        }

        // If there are remaining nodes in the first list, process them.
        while (curr1) {
            sum = curr1->val + carry;
            tail->next = new ListNode(sum % 10);
            curr1 = curr1->next;
            tail = tail->next;
            carry = sum / 10;   // Update carry for the next iteration.
        }

        // If there are remaining nodes in the second list, process them.
        while (curr2) {
            sum = curr2->val + carry;
            tail->next = new ListNode(sum % 10);
            curr2 = curr2->next;
            tail = tail->next;
            carry = sum / 10;   // Update carry for the next iteration.
        }

        // If there is a carry left after processing both lists, add it as a new node.
        while (carry) {
            tail->next = new ListNode(carry % 10);
            tail = tail->next;
            carry /= 10;        // No need to update carry anymore as it should be 0 now.
        }

        // Return the result list starting from the first node (skipping the dummy head).
        return head->next;
    }
};

Time Complexity = O(max(m, n))
Space Complexity = O(max(m, n))
=> where m and n are the lengths of the input linked lists.
```
