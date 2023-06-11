#include <bits/stdc++.h>

int profit (vector<int> &values, vector<int> &weights, int n, int w, int index, vector <vector <int>> &dp) {
	if (index == n || w == 0) return 0;
	if (dp[index][w]!=-1) return dp[index][w];
	int notTake = dp[index][w]=profit (values, weights, n, w, index+1, dp);
	int take = INT_MIN;
	

	if (w >= weights[index]) {
		take = dp[index][w]=values[index]+profit (values, weights, n, w-weights[index], index+1, dp);
	}

	return dp[index][w]=max (take, notTake);
}

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w) {
	// Write your code here
	vector <vector <int>> dp (n+1, vector <int> (w+1, -1));
	return profit(values, weights, n, w, 0, dp);
}
