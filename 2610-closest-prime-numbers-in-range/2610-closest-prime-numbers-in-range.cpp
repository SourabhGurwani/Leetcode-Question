class Solution {
public:
     bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}
    vector<int> closestPrimes(int left, int right) {
        vector<int>v;
        for(int i=left;i<=right;i++){
          
            if(isPrime(i)){
                v.push_back(i);
                cout<<i<<" ";
            }
        }
        int mini = INT_MAX;
        int a = -1;
        int b = -1;
        for(int i=v.size()-2; i>=0; i--){
           int diff = v[i+1] - v[i];
            if(mini >= diff){
                mini = diff;
                a = v[i];
                b = v[i+1];
            }
        }
        return {a,b};
    }
};