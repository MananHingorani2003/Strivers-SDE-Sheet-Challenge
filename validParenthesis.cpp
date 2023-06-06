bool isValidParenthesis(string s) {
    // Write your code here.
    int n = s.length();
    stack <char> mahi;
    if (n%2!=0) return false;
    for (int i=0; i<n; i++) {
        if (s[i]=='{' || s[i]=='(' || s[i]=='[') {
            mahi.push (s[i]);
            continue;
        }
        if (s[i]==')' && !mahi.empty()) {
            char c = mahi.top();
            mahi.pop();
            if (c=='(') continue;
            else return false;
        }
        else if (s[i]=='}' && !mahi.empty()) {
            char c = mahi.top();
            mahi.pop();
            if (c=='{') continue;
            else return false;
        }
        else if (s[i]==']' && !mahi.empty()) {
            char c = mahi.top();
            mahi.pop();
            if (c=='[') continue;
            else return false;
        }
    }
    if (mahi.size()==0) return true;
    return false;

}
