import java.util.HashSet;
import java.util.Set;

class Solution {
    public int findPair(int n, int x, int[] arr) {
        // Check if the array is empty
        if(arr.length == 0) {
            System.out.println("Array is Empty");
            return -1;
        }
        
        // Create a set to store elements of the array
        Set<Integer> seen = new HashSet<>();
        
        // Iterate over each element in the array
        for (int i = 0; i < n; i++) {
            // Check if (arr[i] - x) or (arr[i] + x) exists in the set
            if (seen.contains(arr[i] - x) || seen.contains(arr[i] + x)) {
                return 1;  // Pair found
            }
            
            // Add current element to the set
            seen.add(arr[i]);
        }
        
        // If no pair is found, return -1
        return -1;
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        
        int n = 6;
        int x = 78;
        int[] arr = {5, 20, 3, 2, 5, 80};
        
        int result = sol.findPair(n, x, arr);
        System.out.println(result);  // Output: 1 (since pair (2, 80) has difference 78)
    }
}
