#include <iostream>
#include <vector>
using namespace std;

vector<int> subarray_sum(vector<int>& a, int k) {
    vector<int> result;
    int start = 0;
    int sum = 0;
    for (int last = 0; last < a.size(); last++) {
        sum = sum + a[last];
        
        // If sum exceeds the given target 'k', remove elements from the start
        while (sum > k && start <= last) {
            sum = sum - a[start];
            start++;
        }
        
        // If the sum is equal to 'k', store the subarray indexes
        if (sum == k) {
            result.push_back(start);
            result.push_back(last);
            break; // Stop at the first found subarray. Remove this if you want all possible subarrays.
        }
    }
    return result;
}

int main() {
    vector<int> a = {1, 2, 3, 5};
    int target_sum = 5;
    
    vector<int> result = subarray_sum(a, target_sum);
    
    if (!result.empty()) {
        cout << "Subarray found from index " << result[0] << " to " << result[1] << endl;
    } else {
        cout << "No subarray with the given sum found." << endl;
    }
    
    return 0;
}
