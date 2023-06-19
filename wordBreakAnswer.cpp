#include <bits/stdc++.h> 
bool wordBreak(string s, vector<string>& wordDict, unordered_map<string, bool>& memo) {
        if (s.length()==0) {
            return 1;
        }  
        if (memo.count(s)) return memo[s];
        for (int i=1; i<=s.length(); i++) {
            int f = 0;
            for (int j=0; j<wordDict.size(); j++) {
                if (s.substr(0,i).compare (wordDict[j])==0) {
                    f = 1;
                    break;
                }
            }
            if (f==1) {
                if(wordBreak (s.substr(i), wordDict, memo)) {
                    memo [s] = true;
                    return true;
                }
            }

        }
        memo [s] = false;
        return false;
    }

bool wordBreak(vector < string > & wordDict, int n, string & s) {
    // Write your code here.
    unordered_map<string, bool> memo;
    return wordBreak(s, wordDict, memo);
}
