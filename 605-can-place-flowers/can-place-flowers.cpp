// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
//     }
// };
#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();

        for (int i = 0; i < size; ++i) {
            // Check if the current plot is empty and its neighbors are also empty or don't exist
            if (flowerbed[i] == 0 && 
                (i == 0 || flowerbed[i - 1] == 0) && 
                (i == size - 1 || flowerbed[i + 1] == 0)) {
                // Plant a flower
                flowerbed[i] = 1;
                --n; // Decrease the number of flowers left to plant

                // If all flowers are planted, return true
                if (n == 0) return true;
            }
        }

        // If we exit the loop and still have flowers to plant, return false
        return n <= 0;
    }
};
