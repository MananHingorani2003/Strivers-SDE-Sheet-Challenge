int currProduct = 1;
        int maxProduct = INT_MIN;

        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (currProduct == 0) {
                currProduct = 1;
            }
            currProduct = currProduct * nums[i];
            maxProduct = max (maxProduct, currProduct);
        }

        currProduct = 1;
        
        for (int i=n-1; i>=0; i--) {
            if (currProduct == 0) {
                currProduct = 1;
            }
            currProduct = currProduct * nums[i];
            maxProduct = max (maxProduct, currProduct);
        }

        return maxProduct;
