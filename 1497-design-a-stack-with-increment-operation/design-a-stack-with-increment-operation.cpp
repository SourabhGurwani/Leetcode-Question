// class CustomStack {
// public:
//     //  vector<int> v;
  

//     CustomStack(int maxSize) {
//         int arr[maxSize+1];
//         int arr[0]=-1;
//         int i=0;
//     }
    
//     void push(int x) {
//          i++;
//         if(i>=maxSize){
            
//         }
//        else{
//         arr[i]=x;
       
//        }
//     }
    
//     int pop() {
//         int top=arr[i];
//         i--;
//         return top;
        
        
//     }
    
//     void increment(int k, int val) {
        
//         if(k>=i){
        
//             for(int j=1;j<=i;j++){
//                 arr[j]=arr[j]+val;
//             }
//         }
//         else{
//     for(int j=1;j<=k;j++){
//                 arr[j]=arr[j]+val;
//             }
//         }
        
//     }
// };

// /**
//  * Your CustomStack object will be instantiated and called as such:
//  * CustomStack* obj = new CustomStack(maxSize);
//  * obj->push(x);
//  * int param_2 = obj->pop();
//  * obj->increment(k,val);
//  */
#include <iostream>
#include <vector>

using namespace std; // Added using namespace std;

class CustomStack {
private:
    vector<int> stack;
    int maxSize;

public:
    CustomStack(int maxSize) : maxSize(maxSize) {}

    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    int pop() {
        if (stack.empty()) {
            return -1; // Or throw an exception
        }
        int top = stack.back();
        stack.pop_back();
        return top;
    }

    void increment(int k, int val) {
        int n = stack.size();
        for (int i = 0; i < min(k, n); ++i) {
            stack[i] += val;
        }
    }
};

// int main() {
//     CustomStack* obj = new CustomStack(3);
//     obj->push(1);
//     obj->push(2);
//     obj->pop();
//     obj->push(2);
//     obj->push(3);
//     obj->push(4);
//     obj->increment(5, 100);
//     obj->increment(2, 100);
//     obj->pop();
//     obj->pop();
//     obj->pop();

//     delete obj; // Important: Delete to avoid memory leaks
//     return 0;
// }