#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<int>> mahi = vector<vector<int>>(rows, vector<int>(cols, -1));
    mahi [0][0] = grid[0][0];

    for (int i=1; i<rows; i++) mahi[i][0] = grid [i][0]+mahi[i-1][0];
    for (int i=1; i<cols; i++) mahi[0][i] = grid [0][i]+mahi[0][i-1];

    for (int i=1; i<rows; i++) {
        for (int j=1; j<cols; j++) {
            mahi [i][j] = min (mahi[i-1][j]+grid[i][j], mahi[i][j-1]+grid[i][j]);
        }
    }

    return mahi [rows-1][cols-1];

}
