// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
//     }
// };
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0; // Pointer for popped array

        for (int num : pushed) {
            st.push(num); // Push elements into the stack
            
            // Keep popping while the top of stack matches `popped[j]`
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++; // Move to next element in `popped`
            }
        }
        
        return st.empty(); // If stack is empty, the sequence is valid
    }
};

// int main() {
//     Solution sol;
//     vector<int> pushed = {1, 2, 3, 4, 5};
//     vector<int> popped = {4, 5, 3, 2, 1}; // Valid pop sequence

//     if (sol.validateStackSequences(pushed, popped)) {
//         cout << "true" << endl;
//     } else {
//         cout << "false" << endl;
//     }

//     return 0;
// }
