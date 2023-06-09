int findCelebrity(int n) {
 	// Approach Using Stack.
	stack<int> stack;
	// Put all the peoples into the stack.
	for(int i = 0; i < n; i++){
		stack.push(i);
	}
	// pop two elements check if any of them know each other
	while(stack.size() != 1){
		int a = stack.top();
		stack.pop();
		int b = stack.top();
		stack.pop();
		if(knows(a, b)) stack.push(b);
		else stack.push(a);
	}
	// Stack have the potential candidate
	int maybe = stack.top();
	// Check that he knows no one
	for(int i = 0; i < n; i++){
		if(i != maybe){
			if(knows(maybe, i)) return -1;
		}
	}
	// Check if all knows him
	for(int i = 0; i < n; i++){
		if(i != maybe){
			if(!knows(i, maybe)) return -1;
		}
	}

	return maybe;
}
