#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix) {
	// Write your code here.
    bool firstRow = true;
    bool firstCol = true;

    if (matrix[0][0]==0) {
        firstRow = false;
        firstCol = false;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

	for (int i=0; i<cols; i++) if (matrix[0][i]==0) firstRow = false;
    for (int i=0; i<rows; i++) if (matrix[i][0]==0) firstCol = false;

    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (i==0 || j==0) continue;
            if (matrix[i][j]==0) {
                matrix [i][0] = 0;
                matrix [0][j] = 0;
            }
        }
    }

    for (int i=1; i<rows; i++) if (matrix[i][0]==0) for (int j=0; j<cols; j++) matrix [i][j] = 0;
    for (int i=1; i<cols; i++) if (matrix[0][i]==0) for (int j=0; j<rows; j++) matrix [j][i] = 0;

    if (!firstRow) for (int i=0; i<cols; i++) matrix [0][i] = 0;
    if (!firstCol) for (int i=0; i<rows; i++) matrix [i][0] = 0;
  }
