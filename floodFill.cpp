
#include<bits/stdc++.h>
void bfs (vector<vector<int>> &image, int x, int y, int newColor, int initialColor, 
vector <vector <int>> &ans, int *delRow, int *delCol, vector <vector <bool>> &visited) {

    queue <pair <int, int>> mahi;
    mahi.push ({x, y});
    visited [x][y] = 1;
    int rows = image.size();
    int cols = image[0].size();
    ans [x][y] = newColor;

    while (!mahi.empty()) {
        int row = mahi.front().first;
        int col = mahi.front().second;
        mahi.pop();

        for (int i=0; i<4; i++) {
            int dr = row+delRow [i];
            int dc = col+delCol [i];

            if (dr>=0 && dr<rows && dc >=0 && dc<cols && image[dr][dc]==initialColor && !visited[dr][dc]) {
                ans[dr][dc] = newColor;
                mahi.push ({dr,dc});
                visited [dr][dc] = true;
            }
        }
    }

}


vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    vector <vector <int>> ans = image;
    int row = image.size();
    int col = image[0].size();
    vector <vector <bool>> visited (row, vector <bool> (col, 0));
    int initialColor = image [x][y];

    int delRow [4] = {-1, 0, +1, 0};
    int delCol [4] = {0, +1, 0, -1};

    bfs (image, x, y, newColor, initialColor, ans, delRow, delCol, visited);

    return ans;
}
