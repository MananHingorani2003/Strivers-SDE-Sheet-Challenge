bool searchMatrix(vector<vector<int>>& mat, int target) {
        int rows = mat.size();
        int cols = mat[0].size();

        int low = 0;
        int high = (rows*cols)-1;

        while (low <= high) {
            int mid = low+((high-low)/2);
            int rowN = mid/cols;
            int colN = mid%cols;

            if (target == mat[rowN][colN]) return true;
            else if (target > mat[rowN][colN]) low = mid+1;
            else high = mid-1;

        }
        return false;
}
