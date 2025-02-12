#include <iostream>
#include <vector>
#include <climits>  // For INT_MIN and INT_MAX

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);  // Swap the arrays to make nums1 the smaller one
        }

        int x = nums1.size();  // Get the size of nums1
        int y = nums2.size();  // Get the size of nums2
        int low = 0, high = x;  // Set the binary search boundaries on nums1

        // Perform binary search on nums1
        while (low <= high) {
            int partitionX = (low + high) / 2;  // Partition of nums1
            int partitionY = (x + y + 1) / 2 - partitionX;  // Partition of nums2

            // Handle the edge cases when partition is at the boundary
            int maxLeftX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];  // Left partition element of nums1
            int minRightX = (partitionX == x) ? INT_MAX : nums1[partitionX];      // Right partition element of nums1

            int maxLeftY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];  // Left partition element of nums2
            int minRightY = (partitionY == y) ? INT_MAX : nums2[partitionY];      // Right partition element of nums2

            // Check if partition is correct
            if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
                // If the total length is even, return the average of two middle elements
                if ((x + y) % 2 == 0) {
                    return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
                } else {
                    // If the total length is odd, return the max of the left partition
                    return max(maxLeftX, maxLeftY);
                }
            } else if (maxLeftX > minRightY) {
                // Move partitionX to the left if maxLeftX is too large
                high = partitionX - 1;
            } else {
                // Move partitionX to the right if maxLeftY is too large
                low = partitionX + 1;
            }
        }

        // If arrays are not sorted properly or if there's an error, throw an exception
        throw invalid_argument("Input arrays are not sorted properly.");
    }
};
