#include <bits/stdc++.h>

int lcs2 (string s, string t, int len1, int len2, int i, int j, vector <vector <int>> &dp) {
	if (i==len1 || j==len2) return 0;
	if (dp[i][j]!=-1) return dp[i][j];
	if (s[i]==t[j]) return dp[i][j] = 1+lcs2(s, t, len1, len2, i+1, j+1, dp);
	else return dp[i][j]=max (lcs2(s, t, len1, len2, i+1, j, dp), lcs2(s, t, len1, len2, i, j+1, dp));
}

int lcs(string s, string t)
{
	//Write your code here
	int len1 = s.length();
	int len2 = t.length();

	vector <vector <int>> dp (len1, vector <int> (len2, -1));
	return lcs2 (s, t, len1, len2, 0, 0, dp);
}
