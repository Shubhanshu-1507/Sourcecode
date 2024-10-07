//Kadane's Algorithm in CPP
#include <iostream>
#include <vector>

using namespace std;

int maxSubarraySum(vector<int>& nums) {
    int n = nums.size();
    int current_max = nums[0];
    int global_max = nums[0];

    for (int i = 1; i < n; ++i) {
        current_max = max(nums[i], current_max + nums[i]);
        global_max = max(global_max, current_max);
    }

    return global_max;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = maxSubarraySum(nums);
    cout << "The maximum subarray sum is: " << result << endl;
    return 0;
}
