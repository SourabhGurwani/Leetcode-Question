class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        // vector<int> result={-1,-1};
        // vector<int> res;
    
        // for(int i=left;i<=right;i++){
        //     bool check=true;
        //         for(int j=2;j<i;j++){
        //         if (i % j == 0){ 
        //           check=false  ;
        //         }
                
        //     }  
        //     if(check!=false){
        //             res.push_back(i);
        //             ;
        //         } 
    
        // }
        // if(res.size()==0 || res.size()==1){
        //     return result;
        // }
        // // return res;
        // vector<int> closePrime;
        // int mindiff=res[1]-res[0];
        // closePrime={res[0],res[1]};
        // // closePrime[1]=res[1];
        // for(int i=1;i<res.size()-1;i++){
        //     int diff=res[i+1]-res[i];
        //     if(mindiff>diff){
        //         mindiff=diff;
        //        closePrime = {res[i], res[i+1]};
                
        //     }
        // }
        // return closePrime;
    if (right < 2) return {-1, -1}; // No prime numbers below 2

    // Step 1: Sieve of Eratosthenes
    vector<bool> is_prime(right + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= right; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= right; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Step 2: Find the closest prime pair
    int prev_prime = -1, min_diff = INT_MAX;
    vector<int> result = {-1, -1};

    for (int num = left; num <= right; num++) {
        if (is_prime[num]) {
            if (prev_prime != -1 && (num - prev_prime) < min_diff) {
                min_diff = num - prev_prime;
                result = {prev_prime, num};
            }
            prev_prime = num; // Update previous prime
        }
    }

    return result;
        
    }
};