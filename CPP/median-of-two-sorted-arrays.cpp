#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int p1 = 0;
    int p2 = 0;

    int FindMin(vector<int>& nums1, vector<int>& nums2) {
        if (p1 < nums1.size() && p2 < nums2.size()) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < nums1.size()) {
            return nums1[p1++];
        } else if (p2 < nums2.size()) {
            return nums2[p2++];
        } else {
            return -1; // This case should not be hit if used correctly
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        if ((n + m) % 2 == 0) {
            for (int i = 0; i < ((n + m) / 2) - 1; ++i) {
                int _ = FindMin(nums1, nums2);
            }
            return (double)(FindMin(nums1, nums2) + FindMin(nums1, nums2)) / 2;
        } else {
            for (int i = 0; i < ((n + m) / 2); ++i) {
                int _ = FindMin(nums1, nums2);
            }
            return FindMin(nums1, nums2);
        }
        return -1;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median of {1, 3} and {2} is: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Median of {1, 2} and {3, 4} is: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {};
    nums2 = {1};
    cout << "Median of {} and {1} is: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {2};
    nums2 = {};
    cout << "Median of {2} and {} is: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
