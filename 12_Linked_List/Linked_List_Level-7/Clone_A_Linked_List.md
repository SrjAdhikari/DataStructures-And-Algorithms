# Question : [Clone a linked list with next and random pointer - GFG](https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1)

You are given a special linked list where each node has a next pointer pointing to its next node. You are also given some random pointers, where you will be given some pairs denoting two nodes `a` and `b` i.e. a->random = b (`random` is a pointer to a random node).

Construct a copy of the given list. The copy should consist of the same number of new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the original and copied list pointers represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes `x` and `y` in the original list, where `x->random` = `y`, then for the corresponding two nodes `xnew` and `ynew` in the copied list, `xnew->random = ynew`.

Return the head of the copied linked list.

### Note:

1. If there is any node whose arbitrary pointer is not given then it's by default NULL.
2. Don't make any changes to the original linked list.

![](https://contribute.geeksforgeeks.org/wp-content/uploads/clone.jpg)

**Not**: The diagram isn't part of any example, it just depicts an example of how the linked list may look.

### Example 1

```
Input: LinkedList: 1->2->3->4 , pairs = [{1,2},{2,4}]
Output: true
Explanation: In this test case, there are 4 nodes in linked list.  Among these 4 nodes,  2 nodes have arbitrary pointer set, rest two nodes have arbitrary pointer as NULL. Second line tells us the value of four nodes. The third line gives the information about arbitrary pointers. The first node arbitrary pointer is set to node 2.  The second node arbitrary pointer is set to node 4.
```

### Example 2

```
Input: LinkedList: 1->3->5->9 , pairs[] = [{1,1},{3,4}]
Output: true
Explanation: In the given testcase, applying the method as stated in the above example, the output will be 1.
```

```
Expected Time Complexity: O(n)
Expected Auxilliary Space: O(1)
```

### Constraints

-   `1 <= numbers of random pointer <= number of nodes <= 100`
-   `0 <= node->data <= 1000`
-   `1 <= a, b <= 100`

## Solution 1

```Cpp
Brute-Force Approach:
class Solution {
public:
    // This function finds the corresponding node in the cloned list (curr2) that matches
    // the position of a given node (randomNode) in the original list (curr1).
    Node* findRandomNode(Node* curr1, Node* curr2, Node* randomNode) {
        // If the random node is NULL, return NULL.
        if(randomNode == NULL)
            return NULL;

        // Traverse the original and cloned lists simultaneously until curr1 points to the random node.
        while(curr1 != randomNode) {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        // Return the corresponding node in the cloned list (curr2).
        return curr2;
    }

    // Function to copy a linked list with next and random pointers.
    Node* copyList(Node *head) {
        // Step 1: Create a dummy head node for the cloned list.
        Node* headCopy = new Node(0);
        Node* tailCopy = headCopy;      // tailCopy will help in building the new list.
        Node* temp = head;              // temp is used to traverse the original list.

        // Step 2: Create a shallow copy of the list (i.e., clone the list without random pointers).
        while(temp) {
            // Create a new node with the same data as the current node in the original list.
            tailCopy->next = new Node(temp->data);

            tailCopy = tailCopy->next;  // Move the tail pointer of the cloned list.
            temp = temp->next;          // Move to the next node in the original list.
        }

        // Step 3: Remove the dummy head node and set headCopy to the actual head of the cloned list.
        tailCopy = headCopy;            // tailCopy temporarily points to the dummy node.
        headCopy = headCopy->next;      // headCopy now points to the actual first node of the cloned list.
        delete tailCopy;                // Delete the dummy node.

        // Step 4: Assign the correct random pointers to the nodes in the cloned list.
        tailCopy = headCopy;            // Reset tailCopy to the start of the cloned list.
        temp = head;                    // Reset temp to the start of the original list.

        // Step 5: Assign the random pointers in the cloned list.
        while(temp) {
            // For each node in the cloned list, find the corresponding random node
            // using the findRandomNode function and assign it to the random pointer.
            tailCopy->random = findRandomNode(head, headCopy, temp->random);

            tailCopy = tailCopy->next;  // Move to the next node in the cloned list.
            temp = temp->next;          // Move to the next node in the original list.
        }

        // Step 6: Return the head of the cloned list.
        return headCopy;
    }
};

Time Complexity = O(n^2)
Space Complexity = O(1)
```

## Solution 2

```Cpp
Using Unordered_map:
class Solution {
public:
    // Function to copy a linked list with next and random pointers.
    Node* copyList(Node *head) {
        // Step 1: Create a dummy head node for the cloned list.
        Node* headCopy = new Node(0);
        Node* tailCopy = headCopy;      // tailCopy will help in building the new list.
        Node* temp = head;              // temp is used to traverse the original list.

        // Step 2: Create a shallow copy of the list (i.e., clone the list without random pointers).
        while(temp) {
            // Create a new node with the same data as the current node in the original list.
            tailCopy->next = new Node(temp->data);

            tailCopy = tailCopy->next;  // Move the tail pointer of the cloned list.
            temp = temp->next;          // Move to the next node in the original list.
        }

        // Step 3: Remove the dummy head node and set headCopy to the actual head of the cloned list.
        tailCopy = headCopy;            // tailCopy temporarily points to the dummy node.
        headCopy = headCopy->next;      // headCopy now points to the actual first node of the cloned list.
        delete tailCopy;                // Delete the dummy node.

        // Step 4: Create a mapping from original nodes to their corresponding cloned nodes.
        tailCopy = headCopy;            // Reset tailCopy to start of the cloned list.
        temp = head;                    // Reset temp to start of the original list.

        unordered_map<Node*, Node*> map; // Map to store the correspondence between original and cloned nodes.

        // Traverse both lists to populate the map with original-cloned node pairs.
        while(temp) {
            map[temp] = tailCopy;       // Map the current original node to the corresponding cloned node.
            temp = temp->next;          // Move to the next node in the original list.
            tailCopy = tailCopy->next;  // Move to the next node in the cloned list.
        }

        // Step 5: Assign the random pointers in the cloned list.
        tailCopy = headCopy;            // Reset tailCopy to start of the cloned list.
        temp = head;                    // Reset temp to start of the original list.

        while(temp) {
            // Use the map to set the random pointer in the cloned list.
            // map[temp->random] gives the corresponding node in the cloned list for the random pointer.
            tailCopy->random = map[temp->random];
            tailCopy = tailCopy->next;  // Move to the next node in the cloned list.
            temp = temp->next;          // Move to the next node in the original list.
        }

        // Step 6: Return the head of the cloned list.
        return headCopy;
    }
};

Time Complexity = O(n)
Space Complexity = O(n)
```

## Solution 3

```Cpp
In-place:
class Solution {
public:
    // Function to copy a linked list with next and random pointers.
    Node* copyList(Node *head) {
        // Step 1: Create a dummy head node for the cloned list.
        Node* headCopy = new Node(0);
        Node* tailCopy = headCopy;      // tailCopy will help in building the new list.
        Node* temp = head;              // temp is used to traverse the original list.

        // Step 2: Create a shallow copy of the list (i.e., clone the list without random pointers).
        while(temp) {
            // Create a new node with the same data as the current node in the original list.
            tailCopy->next = new Node(temp->data);

            tailCopy = tailCopy->next;  // Move the tail pointer of the cloned list.
            temp = temp->next;          // Move to the next node in the original list.
        }

        // Step 3: Remove the dummy head node and set headCopy to the actual head of the cloned list.
        tailCopy = headCopy;            // tailCopy temporarily points to the dummy node.
        headCopy = headCopy->next;      // headCopy now points to the actual first node of the cloned list.
        delete tailCopy;                // Delete the dummy node.

        // Step 4: Interweave the original and cloned lists.
        // The idea here is to insert each cloned node directly after its corresponding original node.
        // This will make it easier to set the random pointers in the cloned list.
        Node* curr1 = head;             // curr1 will traverse the original list.
        Node* curr2 = headCopy;         // curr2 will traverse the cloned list.
        Node* next1 = NULL;             // next1 will store the next node in the original list.
        Node* next2 = NULL;             // next2 will store the next node in the cloned list.

        while(curr1) {
            next1 = curr1->next;        // Store the next node of the original list.
            next2 = curr2->next;        // Store the next node of the cloned list.

            // Insert the cloned node directly after the corresponding original node.
            curr1->next = curr2;        // Link the current original node to the current cloned node.
            curr2->next = next1;        // Link the current cloned node to the next original node.

            // Move to the next pair of nodes in the original and cloned lists.
            curr1 = next1;              // Move curr1 to the next node in the original list.
            curr2 = next2;              // Move curr2 to the next node in the cloned list.
        }

        // Step 5: Set the random pointers in the cloned list.
        // Now that the cloned nodes are interleaved with the original nodes,
        // we can easily set the random pointers in the cloned list.
        curr1 = head;                   // Reset curr1 to the start of the original list.

        while(curr1) {
            curr2 = curr1->next;        // curr2 is the corresponding cloned node (now directly after curr1).

            // If the current original node has a random pointer, set the cloned node's random pointer.
            // Since curr1->random is an original node, curr1->random->next will be the corresponding cloned node.
            if(curr1->random) {
                curr2->random = curr1->random->next; // Set the random pointer of the cloned node.
            }

            curr1 = curr2->next;        // Move to the next original node (skipping the interleaved cloned node).
        }

        // Step 6: Separate the cloned list from the original list.
        // After the random pointers are set, we need to restore the original list to its original form
        // and extract the cloned list as a separate list.
        curr1 = head;                   // Reset curr1 to the start of the original list.

        while(curr1->next) {
            next1 = curr1->next;        // Store the next node, which is currently a cloned node.
            curr1->next = next1->next;  // Link the original node to the next original node, skipping the cloned node.
            curr1 = next1;              // Move to the next node, which is now an original node.
        }

        // Step 7: // Return the head of the cloned list.
        // The cloned list is now fully separated from the original list, with both the next and random pointers correctly set.
        return headCopy;
    }
};

Time Complexity = O(n)
Space Complexity = O(1)
```
