class FreqStack {
    private:
    unordered_map<int, int> freq;        // Frequency of each element
    unordered_map<int, stack<int>> group; // Stacks of elements grouped by frequency
    int maxFreq;                         // Maximum frequency in stack

public:
    FreqStack() {
         maxFreq = 0;
    }
    
    void push(int val) {  
        freq[val]++; // Increase frequency
        int f = freq[val];

        // Update max frequency
        maxFreq = max(maxFreq, f);

        // Push the element into the corresponding frequency stack
        group[f].push(val);
        
    }
    
    int pop() {
        
         // Get the most frequent element
        int val = group[maxFreq].top();
        group[maxFreq].pop();

        // Decrease frequency
        freq[val]--;

        // If the stack for maxFreq is empty, reduce maxFreq
        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */