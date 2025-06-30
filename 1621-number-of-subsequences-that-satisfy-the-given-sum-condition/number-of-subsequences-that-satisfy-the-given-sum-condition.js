var numSubseq = function(nums, target) {
    nums.sort((a, b) => a - b);
    let mod = 1e9 + 7;
    let left = 0, right = nums.length - 1;
    let result = 0;

    // Precompute powers of 2 up to nums.length
    let power = new Array(nums.length).fill(1);
    for (let i = 1; i < nums.length; i++) {
        power[i] = (power[i - 1] * 2) % mod;
    }

    while (left <= right) {
        if (nums[left] + nums[right] <= target) {
            result = (result + power[right - left]) % mod;
            left++;
        } else {
            right--;
        }
    }

    return result;
};
