# Question : [Merge K sorted linked lists - GFG](https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1)

Given an array of sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

### Example 1

```
Input: arr = [1->2->3, 4->5, 5->6, 7->8]
Output: 1->2->3->4->5->5->6->7->8
Explanation:
The test case has 4 sorted linked
list of size 3, 2, 2, 2
1st    list     1 -> 2-> 3
2nd   list      4->5
3rd    list      5->6
4th    list      7->8
The merged list will be
```

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700265/Web/Other/blobid0_1722513367.png)

### Example 2

```
Input: arr = [1->3, 4->5->6, 8]
Output: 1->3->4->5->6->8
Explanation:
The test case has 3 sorted linked
list of size 2, 3, 1.
1st list 1 -> 3
2nd list 4 -> 5 -> 6
3rd list 8
The merged list will be
```

![](https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/700265/Web/Other/blobid1_1722513386.png)

```
Expected Time Complexity: O(n*log(n))
Expected Auxiliary Space: O(n)
```

**Note**: **n** is the maximum size of all the LinkedList

### Constraints

-   `1 <= total no. of nodes <= 10^5`
-   `1 <= node->data <= 10^3`

## Solution 1

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

    // Function to merge K sorted linked lists into a single sorted linked list.
    // This function iteratively merges each list in the array.
    Node* mergeKLists(vector<Node*>& arr) {
        // Initialize the head of the merged list with the first list in the array.
        Node* head = arr[0];

        // Iterate through the remaining lists and merge them one by one with the current merged list.
        for (int i = 1; i < arr.size(); i++) {
            // Merge the current list with the next list.
            head = mergeTwoLists(head, arr[i]);
        }

        // Return the head of the merged list containing all K lists.
        return head;
    }
};

Time Complexity = O(k^2 * n)
Space Complexity = O(1)
=> 'k' is the number of linked lists
```

## Solution 2

```Cpp
Approach : Using Merge Sort

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

    // Function to perform merge sort on an array of linked lists.
    void mergeSort(vector<Node*>& arr, int start, int end) {
        // Base case: If the subarray has one or zero elements, it's already sorted.
        if (start >= end)
            return;

        // Find the midpoint of the current subarray.
        int mid = start + (end - start) / 2;

        // Recursively sort the first and second halves of the array.
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        // Merge the two sorted halves.
        arr[start] = mergeTwoLists(arr[start], arr[mid + 1]);
    }

    // Function to merge K sorted linked lists into a single sorted linked list.
    Node* mergeKLists(vector<Node*>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        // Perform merge sort on the array of linked lists.
        mergeSort(arr, start, end);

        // Return the merged list (which will be the first element of the sorted array)
        return arr[0];
    }
};

Time Complexity = O(nlog(k))
Space Complexity = O(log(k))
=> 'k' is the number of linked lists
```
