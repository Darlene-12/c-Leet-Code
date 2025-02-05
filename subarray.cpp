#include <vector>
#include <algorithm> // For std::max
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0;  // To store the maximum sum
        int currentSum = nums[0];  // Start with the first element
        
        // Traverse the array starting from the second element
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                // If ascending, add to the current sum
                currentSum += nums[i];
            } else {
                // If not ascending, update maxSum and reset currentSum
                maxSum = max(maxSum, currentSum);
                currentSum = nums[i];
            }
        }
        
        // Final check for the last ascending subarray
        maxSum = max(maxSum, currentSum);
        
        return maxSum;
    }
};

// Example Test Cases
#include <iostream>
int main() {
    Solution solution;

    vector<int> nums1 = {10, 20, 30, 5, 10, 50};
    cout << solution.maxAscendingSum(nums1) << endl; // Output: 65

    vector<int> nums2 = {10, 20, 30, 40, 50};
    cout << solution.maxAscendingSum(nums2) << endl; // Output: 150

    vector<int> nums3 = {12, 17, 15, 13, 10, 11, 12};
    cout << solution.maxAscendingSum(nums3) << endl; // Output: 33

    return 0;
}
