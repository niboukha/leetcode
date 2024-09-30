class CustomStack {
public:
    vector<int> st;
    int maxS;
    CustomStack(int maxSize)
    {
        maxS = maxSize;
    }
    
    void push(int x)
    {
        if (st.size() == maxS) return;
        st.push_back(x);
    }
    
    int pop()
    {
        if (st.empty()) return -1;
        int x = st.back();
        st.pop_back();
        return x;
    }
    
    void increment(int k, int val)
    {
        for(int i=0; i < k && i < st.size(); i++)
            st[i]+=val;

    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */