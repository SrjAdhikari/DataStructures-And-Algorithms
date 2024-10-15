# Question : [Merge k Sorted Lists - (LeetCode : 23)](https://leetcode.com/problems/merge-k-sorted-lists/description/)

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it*.

### Example 1

```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

### Example 2

```
Input: lists = []
Output: []
```

### Example 3

```
Input: lists = [[]]
Output: []
```

### Constraints
- `k == lists.length`
- `0 <= k <= 10^4`
- `0 <= lists[i].length <= 500`
- `-10^4 <= lists[i][j] <= 10^4`
- `lists[i]` is sorted in ascending order.
- The sum of `lists[i].length` will not exceed `10^4`.

## Solution

```Cpp
// Custom comparator for the priority queue (min-heap) to compare ListNode values
class Compare {
    public:
    // This operator() defines how two ListNode objects are compared.
    // This makes the priority queue behave as a min-heap (for sorting ListNodes by value).
    bool operator() (ListNode* a, ListNode* b) {
        // Return true if 'a' is greater than 'b', so the smallest element is at the top of the heap
        return a->val > b->val;
    }
};

// Function to merge k sorted linked lists
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Priority queue (min-heap) to keep track of the smallest current node from each list.
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // Step 1: Push the head node of each non-empty linked list into the priority queue.
        // This ensures that we start with the smallest element from each list.
        for(ListNode* node : lists) {
            if(node)    // Only push non-null nodes to avoid issues
                pq.push(node); 
        }

        // Step 2: Create a dummy head for the result list to make handling the first node easier.
        // This simplifies handling edge cases, such as when the first node of list1 or list2 is the smallest.
        ListNode* head = new ListNode(0);   // Dummy node to simplify list operations
        ListNode* tail = head;              // Tail pointer that always points to the last node of the merged list

        // Step 3: While there are nodes in the priority queue, process the smallest node
        while(!pq.empty()) {
            // Extract the node with the smallest value from the priority queue
            ListNode* temp = pq.top();      // Top of the priority queue contains the smallest element
            pq.pop();                       // Remove it from the priority queue

            // Append the extracted node to the result list
            tail->next = temp;              // Link the smallest node to the result list
            tail = tail->next;              // Move the tail pointer to the newly added node

            // If the extracted node has a next node, push it to the priority queue
            if(temp->next) {
                pq.push(temp->next);        // Push the next node from the same list into the priority queue
            }
        }

        // Step 4: Return the merged list, which starts from the node after the dummy head (skipping the dummy node)
        return head->next;
    }
};

Time Complexity = O(Nlog(K))
Space Complexity = O(K)
```