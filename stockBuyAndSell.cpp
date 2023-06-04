    #include <bits/stdc++.h> 
    int maximumProfit(vector<int> &prices){
    // Write your code here.
        int n = prices.size();
        int i=0;
        int j=1;
        int maxi = 0;

        while (j<n) {
            if (prices[j]>prices[i]) maxi=max(maxi, prices[j]-prices[i]);
            else i=j;
            j++;
        }

        return maxi;
}
