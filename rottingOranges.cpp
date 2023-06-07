#include<bits/stdc++.h>

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    // Write your code here. 
    int totalRows = n;
    int totalCols = m;
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    queue <pair<pair<int, int>, int>> q;
    vector <vector <int>> visited (totalRows, vector <int> (totalCols, 0));

    for (int i=0; i<totalRows; i++) {
        for (int j=0; j<totalCols; j++) {
            if (grid [i][j]==2) {
                visited [i][j] = 2;
                q.push ({{i,j}, 0});
            }
            else {
                visited [i][j] = 0;
            }
        }
    }

    int times = 0;

    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;

        q.pop();
        times = max (times, time);


        for (int i=0; i<4; i++) {
            int dr = row+delRow[i];
            int dc = col+delCol[i];

            if (dr>=0 && dr<totalRows && dc>=0 && dc<totalCols && grid[dr][dc]==1 && !visited[dr][dc]) {
                grid [dr][dc] = 2;
                visited [dr][dc]=2;
                q.push({{dr, dc}, time + 1});
            }
        }
    }

    for (int i=0; i<totalRows; i++) {
        for (int j=0; j<totalCols; j++) {
            if (visited[i][j]!=2 && grid[i][j]==1) return -1;
        }
    }
    return times;

    

}
