#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        if(n < 3) return result;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n-2; ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = n-1;
            while(left < right){
                int total = nums[i] + nums[left] + nums[right];
                if(total == 0){
                    result.emplace_back(vector<int>{nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                }
                else if(total < 0){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> triplets = solution.threeSum(nums);
    
    for(auto &triplet : triplets){
        cout << "[";
        for(auto num : triplet){
            cout << num << " ";
        }
        cout << "] ";
    }
    
    return 0;
}
