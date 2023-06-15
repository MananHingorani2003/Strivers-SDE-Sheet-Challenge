#include <bits/stdc++.h>
long helper (int *denominations, int n, int value, int index, vector <vector <long>> &dp) {
    if (index == n || value < 0) return 0;
    if (value == 0) return 1;

    if (dp[index][value] != -1) return dp[index][value];
    //take:
    long take = helper (denominations, n, value-denominations[index], index, dp);
    //not take:
    long notTake = helper (denominations, n, value, index+1, dp);

    return dp[index][value]=take+notTake;
}

long countWaysToMakeChange(int *denominations, int n, int value) {
    //Write your code here
    vector <vector <long>> dp = vector <vector <long>> (n+1, vector <long> (value+1, -1));
    return helper (denominations, n, value, 0, dp);

}
