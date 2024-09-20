# Question : [Gas Station - (LeetCode : 134)](https://leetcode.com/problems/gas-station/description/)

There are `n` gas stations along a circular route, where the amount of gas at the `ith` station is `gas[i]`.

You have a car with an unlimited gas tank and it costs `cost[i]` of gas to travel from the `ith` station to its next `(i + 1)th` station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays `gas` and `cost`, return *the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return `-1`*. If there exists a solution, it is **guaranteed** to be **unique**.

### Example 1

```
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 4. Your tank = 4 - 1 + 5 = 8
Travel to station 0. Your tank = 8 - 2 + 1 = 7
Travel to station 1. Your tank = 7 - 3 + 2 = 6
Travel to station 2. Your tank = 6 - 4 + 3 = 5
Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
Therefore, return 3 as the starting index.
```

### Example 2
```
Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation:
You can't start at station 0 or 1, as there is not enough gas to travel to the next station.
Let's start at station 2 and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
Travel to station 0. Your tank = 4 - 3 + 2 = 3
Travel to station 1. Your tank = 3 - 3 + 3 = 3
You cannot travel back to station 2, as it requires 4 unit of gas but you only have 3.
Therefore, you can't travel around the circuit once no matter where you start.
```

### Constraints

-   `n == gas.length == cost.length`
-   `1 <= n <= 10^5`
-   `0 <= gas[i], cost[i] <= 10^4`

## Solution 1

```Cpp
class MinStack {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficitGas = 0;  // Keeps track of the total gas deficit encountered if a station fails to be a valid start.
        int balanceGas = 0;  // Keeps track of the current gas balance at each station.
        int startPoint = 0;  // Marks the potential starting point for the circular tour.

        // Loop through each station to check if a valid start point exists
        for (int i = 0; i < gas.size(); i++) {
            // Check if the gas balance at this station plus the gas available is less than the cost to go to the next station.
            if (balanceGas + gas[i] < cost[i]) {
                // If not enough gas to move to the next station, update the deficit to reflect the shortage.
                deficitGas += balanceGas + gas[i] - cost[i];

                // Move the starting point to the next station, as we can't start from any station before this.
                startPoint = i + 1;

                // Reset the balance gas to 0 as we are starting afresh from the new start point.
                balanceGas = 0;
            }
            else {
                // If enough gas is available, update the balance gas by adding the gas at the current station minus the cost to reach the next.
                balanceGas += gas[i] - cost[i];
            }
        }

        // After iterating through all stations, check if the total gas (balance + deficit) is non-negative.
        // If it's non-negative, we can complete the circuit starting from startPoint, otherwise return -1.
        return balanceGas + deficitGas >= 0 ? startPoint : -1;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```

## Solution 2

```Cpp
class MinStack {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int deficitGas = 0;  // Keeps track of the total gas deficit encountered if a station fails to be a valid start.
        int balanceGas = 0;  // Keeps track of the current gas balance at each station.
        int startPoint = 0;  // Marks the potential starting point for the circular tour.

        // Loop through each station to check if a valid start point exists
        for (int i = 0; i < gas.size(); i++) {
            // Calculate the current gas balance after refueling at station i and traveling to station i+1
            balanceGas += gas[i] - cost[i];

            // If balanceGas is negative, it means we can't proceed to the next station.
            if (balanceGas < 0) {
                // Record the deficit encountered by adding the absolute value of the negative balance.
                deficitGas += abs(balanceGas);

                // Move the start point to the next station, since we can't start from here.
                startPoint = i + 1;

                // Reset the balance as we are starting fresh from the next station.
                balanceGas = 0;
            }
        }

        // After completing the loop, check if the total available gas (balanceGas) can cover the deficit.
        // If the balance is greater than or equal to the deficit, return the start point, otherwise return -1.
        return balanceGas - deficitGas >= 0 ? startPoint : -1;
    }
};

Time Complexity = O(N)
Space Complexity = O(1)
```
