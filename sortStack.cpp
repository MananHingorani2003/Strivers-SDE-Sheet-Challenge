#include <bits/stdc++.h> 
void insert (stack<int> &s, int &top) {
	if (s.empty()||s.top()<=top) {
		s.push (top);
		return;
	}
	int val = s.top();
	s.pop();
	insert (s, top);
	s.push (val);

	return;
}

void sortStack(stack<int> &s)
{
	// Write your code here
	if (s.size()<=1) return;
	int top = s.top();
	s.pop();
	sortStack(s);
	insert (s, top);	

}
