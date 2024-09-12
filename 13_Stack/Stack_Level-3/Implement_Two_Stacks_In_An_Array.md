# Question : [Implement two stacks in an array - GFG](https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1)

Your task is to implement  2 stacks in one array efficiently. You need to implement 4 methods.

`twoStacks` : Initialize the data structures and variables to be used to implement  2 stacks in one array.
`push1` : pushes element into first stack.
`push2` : pushes element into second stack.
`pop1` : pops element from first stack and returns the popped element. If first stack is empty, it should return -1.
`pop2` : pops element from second stack and returns the popped element. If second stack is empty, it should return -1.

### Example 1

```
Input:
push1(2)
push1(3)
push2(4)
pop1()
pop2()
pop2()
Output:
3 4 -1
Explanation:
push1(2) the stack1 will be {2}
push1(3) the stack1 will be {2,3}
push2(4) the stack2 will be {4}
pop1()   the poped element will be 3 from stack1 and stack1 will be {2}
pop2()   the poped element will be 4 from stack2 and now stack2 is empty
pop2()   the stack2 is now empty hence returned -1.
```

### Example 2

```
Input:
push1(1)
push2(2)
pop1()
push1(3)
pop1()
pop1()
Output:
1 3 -1
Explanation:
push1(1) the stack1 will be {1}
push2(2) the stack2 will be {2}
pop1()   the poped element will be 1 from stack1 and stack1 will be empty
push1(3) the stack1 will be {3}
pop1()   the poped element will be 3 from stack1 and stack1 will be empty
pop1()   the stack1 is now empty hence returned -1.
```

### Your Task
You don't need to read input or print anything. You are required to complete the 4 methods `push1, push2` which takes one argument an integer `'x'` to be pushed into stack one and two and `pop1, pop2` which returns the integer poped out from stack one and two. If no integer is present in the stack return `-1`.

```
Expected Time Complexity: O(1) for all the four methods.
Expected Auxiliary Space: O(1) for all the four methods.
```

### Constraints

-   `1 <= Number of queries <= 10^4`
-   `1 <= Number of elements in the stack <= 100`
-   The sum of count of elements in both the stacks < size of the given array

## Solution

```Cpp
class twoStacks {
public:
    int *arr;   // Array to store elements of both stacks
    int size;   // Total size of the array
    int top1;   // Index for the top of stack1
    int top2;   // Index for the top of stack2 (initially points to the end of the array)

    // Constructor to initialize the stack with a given size (default 100)
    twoStacks(int n = 100) {
        arr = new int[n];  // Allocate memory for the array
        size = n;          // Set the size of the array
        top1 = -1;         // Initialize top1 for stack1 (stack1 starts from index 0)
        top2 = n;          // Initialize top2 for stack2 (stack2 starts from the end of the array)
    }

    // Function to push an integer into stack1
    void push1(int x) {
        // Check if there is space available for pushing into stack1
        if (top2 - top1 == 1) 
            return;  // If no space, return without pushing
        else {
            top1++;            // Increment top1 to point to the new top of stack1
            arr[top1] = x;     // Insert the new element into stack1
        }
    }

    // Function to push an integer into stack2
    void push2(int x) {
        // Check if there is space available for pushing into stack2
        if (top2 - top1 == 1) 
            return;  // If no space, return without pushing
        else {
            top2--;            // Decrement top2 to point to the new top of stack2
            arr[top2] = x;     // Insert the new element into stack2
        }
    }

    // Function to remove an element from top of stack1
    int pop1() {
        // Check if stack1 is empty
        if (top1 == -1)
            return -1; // If empty, return -1 to indicate an error
        else {
            int popped = arr[top1]; // Get the top element of stack1
            top1--;                 // Decrement top1 to remove the element
            return popped;          // Return the removed element
        }
    }

    // Function to remove an element from top of stack2
    int pop2() {
        // Check if stack2 is empty
        if (top2 == size)
            return -1; // If empty, return -1 to indicate an error
        else {
            int popped = arr[top2]; // Get the top element of stack2
            top2++;                 // Increment top2 to remove the element
            return popped;          // Return the removed element
        }
    }

    // Destructor to free the allocated memory
    ~twoStacks() {
        // Deallocate the memory used for the array
        delete[] arr;
    }
};

Time Complexity = O(1)
Space Complexity = O(n)
```