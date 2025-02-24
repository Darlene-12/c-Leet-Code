class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;

        // Single digits are always palindromes
        if (x >= 0 && x < 10) return true;

        // Numbers ending in 0 cannot be palindromes unless they are 0
        if (x % 10 == 0 && x != 0) return false;

        int reversedNum = 0;
        int original = x;

        // Reverse only half of the number
        while (x > reversedNum) {
            int lastDigit = x % 10;  // Extract last digit
            reversedNum = reversedNum * 10 + lastDigit; // Append to reversed number
            x /= 10;  // Remove last digit
        }

        // Compare the original half with reversed half
        return x == reversedNum == reversedNum / 10;  // ⚠ Issue here
    }
};
