int edit (string str1, string str2, int len1, int len2, int i, int j, vector <vector <int>> &dp) {
    if (i==len1) return str2.substr(j).length();
    if (j==len2) return str1.substr(i).length();

    if (dp[i][j]!=-1) return dp[i][j];

    if (str1[i]==str2[j]) return dp[i][j]=edit (str1, str2, len1, len2, i+1, j+1, dp);
    else return dp[i][j]=1+min (edit(str1, str2, len1, len2, i+1, j+1, dp), min (edit(str1, str2, len1, len2, i, j+1, dp), edit(str1, str2, len1, len2, i+1, j, dp)));

}

int editDistance(string str1, string str2)
{
    //write you code here
    int len1 = str1.length();
    int len2 = str2.length();

    vector <vector <int>> dp (len1, vector <int> (len2, -1));

    return edit (str1, str2, len1, len2, 0, 0, dp);

}
