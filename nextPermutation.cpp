vector<int> nextPermutation(vector<int> &nums, int n)
{
    //  Write your code here.
        int index = -1;
        for (int i=n-1; i>=1; i--) {
            if (nums[i-1]<nums[i]) {
                index=i-1;
                break;
            }
        }
        if (index==-1) {
            reverse (nums.begin(), nums.end());
            return nums;
        }
        int j=n-1;
        for (int m=j; m>=index+1; m--) {
            if (nums[m]>nums[index]) {
                swap (nums[m], nums[index]);
                break;
            }
        }
        reverse (nums.begin()+index+1, nums.end());
        return nums;
}
