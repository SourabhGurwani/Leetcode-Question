class Solution {
public:
    int reverse(int x) {
       long long reversed = 0; // Use long long for intermediate result
    bool negative = false;

    if (x < 0) {
        negative = true;
        long long temp_x = x; // To avoid undefined behavior
        x = -temp_x;
    }

    while (x > 0) {
        int digit = x % 10;

        if (reversed > numeric_limits<int>::max() / 10 ||
            (reversed == numeric_limits<int>::max() / 10 && digit > 7)) {
            return 0; // Overflow
        }
        if (reversed < numeric_limits<int>::min() / 10 ||
            (reversed == numeric_limits<int>::min() / 10 && digit < -8)) {
            return 0; // Underflow
        }

        reversed = reversed * 10 + digit;
        x /= 10;
    }

    return negative ? -reversed : reversed;  
    }
};