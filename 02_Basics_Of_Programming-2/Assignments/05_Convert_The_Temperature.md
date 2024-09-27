# Question : [Convert the Temperature - (LeetCode : 2469)](https://leetcode.com/problems/convert-the-temperature/description/)

You are given a non-negative floating point number rounded to two decimal places `celsius`, that denotes the **temperature in Celsius**.

You should convert Celsius into **Kelvin** and **Fahrenheit** and return it as an array `ans = [kelvin, fahrenheit]`.

Return _the array `ans`_. Answers within `10^-5` of the actual answer will be accepted.

**Note that**:

-   `Kelvin = Celsius + 273.15`
-   `Fahrenheit = Celsius * 1.80 + 32.00`

### Example 1

```
Input: celsius = 36.50
Output: [309.65000,97.70000]
Explanation: Temperature at 36.50 Celsius converted in Kelvin is 309.65
and converted in Fahrenheit is 97.70.
```

### Example 2

```
Input: celsius = 122.11
Output: [395.26000,251.79800]
Explanation: Temperature at 122.11 Celsius converted in Kelvin is 395.26
and converted in Fahrenheit is 251.798.
```

### Constraints

-   `0 <= celsius <= 1000`

## Solution

```Cpp
class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        // Step 1: Convert Celsius to Kelvin.
        double kelvin = celsius + 273.15;

        // Step 2: Convert Celsius to Fahrenheit.
        double fahrenheit = celsius * 1.80 + 32.00;

        // Step 3: Create a vector to store the converted temperatures.
        vector<double> temperature;

        // Step 4: Add the converted Kelvin temperature to the vector.
        temperature.push_back(kelvin);

        // Step 5: Add the converted Fahrenheit temperature to the vector.
        temperature.push_back(fahrenheit);

        // Step 6: Return the vector containing both converted temperatures.
        return temperature;
    }
};

Time Complexity = O(1)
Space Complexity = O(1)
```
