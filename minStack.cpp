class minStack {
public:
    vector <pair <int, int>> mahi;
    minStack() {
    }
    
    void push(int val) {
        if (mahi.size()==0) mahi.push_back ({val,val});
        else {
            mahi.push_back ({val, min (val, mahi.back().second)});
        }
        
    }
    
    int pop() {
        if (mahi.size()==0) return -1;
		int val = mahi.back().first;
        mahi.pop_back();   
		return val;
    }
    
    int top() {
        if (mahi.size()==0) return -1;
        return mahi.back().first;
    }
    
    int getMin() {
        if(mahi.size() == 0) return -1;
        return mahi.back().second;
        
        
    }
};
