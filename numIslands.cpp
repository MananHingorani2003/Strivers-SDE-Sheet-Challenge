#include <bits/stdc++.h>

void bfs(int row,int col,vector<vector<int>> &vis, int **grid, int *delRow, int *delCol, int n, int m) {
        //using namespace std;
         int numrows = n;
         int numcols = m;
        vis [row][col] = 1;
        queue <pair <int, int>> mahi;
        mahi.push ({row,col});

        while (!mahi.empty()) {
            int r = mahi.front().first;
            int c = mahi.front().second;
            mahi.pop();

            for (int i=0; i<8; i++) {
                int dr = r+delRow[i];
                int dc = c+delCol[i];

                if (dr >= 0 && dr < numrows && dc >= 0 && dc < numcols && grid [dr][dc]==1 && !vis[dr][dc]) {
                    mahi.push ({dr,dc});
                    vis [dr][dc]=1;
                }
            }
        }

        
    }

int getTotalIslands(int** grid, int n, int m)
{
   // Write your code here.
   vector<vector<int>> vis(n,vector<int>(m,0));
        int delRow [8] = {-1, 0, 1, 0 ,-1,1,-1,1};
        int delCol [8] = {0, 1, 0, -1 ,1,-1,-1,1};

        int ctr=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1 )
                {
                    ctr++;
                    bfs(i,j,vis,grid, delRow, delCol, n, m);
                }
            }
        }
        return ctr;
}
