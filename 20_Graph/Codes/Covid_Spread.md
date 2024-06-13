# Question : [Covid Spread - GFG](https://www.geeksforgeeks.org/problems/covid-spread--141631/1)

Aterp is the head nurse at a city hospital. City hospital contains R*C number of wards and the structure of a hospital is in the form of a 2-D matrix.
Given a matrix of dimension R*C where each cell in the matrix can have values 0, 1, or 2 which has the following meaning:
0: Empty ward
1: Cells have uninfected patients
2: Cells have infected patients

An infected patient at ward [i,j] can infect other uninfected patient at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. Help Aterp determine the minimum units of time after which there won't remain any uninfected patient i.e all patients would be infected. If all patients are not infected after infinite units of time then simply return -1.

### Example 1
```plaintext
Input:
3 5
2 1 0 2 1
1 0 1 2 1
1 0 0 2 1 
Output:
2
Explanation:
Patients at positions {0,0}, {0, 3}, {1, 3}
and {2, 3} will infect patient at {0, 1}, 
{1, 0},{0, 4}, {1, 2}, {1, 4}, {2, 4} during 1st 
unit time. And, during 2nd unit time, patient at 
{1, 0} will get infected and will infect patient 
at {2, 0}. Hence, total 2 unit of time is
required to infect all patients.
```

### Example 2
```plaintext
Input:
3 5
2 1 0 2 1
0 0 1 2 1
1 0 0 2 1
Output:
-1
Explanation:
All patients will not be infected.
```

### Your task
You don't need to read input or print anything. Your task is to complete the function helpaterp() which takes a 2-D Matrix hospital as input parameter and returns the minimum units of time in which all patients will be infected or -1 if it is impossible.

### Constraints
`1 ≤ R,C ≤ 1000`
`0 ≤ mat[i][j] ≤ 2`

## Solution

```Cpp
Using BFS Traversal :

class Solution {
public:

    int helpaterp(vector<vector<int>> hospital) {

    int row = hospital.size();          // Number of rows in the hospital grid
    int col = hospital[0].size();       // Number of columns in the hospital grid
    
    queue<pair<int, int>> q;            // Queue to store the positions of infected patients
    
    // Push all initially infected patients (cells with value 2) into the queue
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (hospital[i][j] == 2) {
                q.push({i, j});
            }
        }
    }
    
    int timer = 0;  // Timer initialized to 0

    // Directions for moving to adjacent cells (up, down, left, right)
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // BFS traversal to simulate the spread of the infection
    while (!q.empty()) {
        timer++;                                // Increment timer for each level of BFS (each minute)
        int currPatientCount = q.size();        // Number of currently infected patients
        
        // Process each infected patient at the current level
        while (currPatientCount--) {
            int rowIndex = q.front().first;     // Current patient's row index
            int colIndex = q.front().second;    // Current patient's column index
            q.pop();                            // Remove the patient from the queue
            
            // Check all 4 adjacent cells (up, down, left, right)
            for (auto dir : directions) {
                int newRow = rowIndex + dir[0];     // New row index
                int newCol = colIndex + dir[1];     // New column index
                
                // Check if the new cell is within bounds and is a healthy patient (value 1)
                if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col && hospital[newRow][newCol] == 1) {
                    hospital[newRow][newCol] = 2;   // Infect the healthy patient
                    q.push({newRow, newCol});       // Add the newly infected patient to the queue
                }
            }
        }
    }
    
    // Check if any healthy patient remains after the BFS traversal
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (hospital[i][j] == 1) {
                return -1;      // Return -1 if any healthy patient is found
            }
        }
    }
    
    return timer - 1;           // Return the total time taken to infect all patients
}
};

Time Complexity = O(row * col)
Space Complexity = O(row * col)
```