#include <bits/stdc++.h> 

bool isPalindrome(int start, int end, string s) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }
        return true;
    }

    void helper (vector<vector<string>> &final, vector <string> &temp, string s, int index) {
        if (index == s.length()) {
            final.push_back (temp);
            return;
        }
        for (int j=index; j<s.length(); j++) {
            if (isPalindrome (index, j, s)) {
                temp.push_back (s.substr (index, j-index+1));
                helper (final, temp, s, j+1);
                temp.pop_back();
            }
        }

    }
vector<vector<string>> partition(string &s) 
{
    // Write your code here.
    vector <vector <string>> final;
        vector <string> temp;

        helper (final, temp, s, 0);
        return final;
}
