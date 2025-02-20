class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            return s.substr(left + 1, right - left - 1);
        };

        string longest = "";
        for (int i = 0; i < s.length(); i++) {
            string oddPalindrome = expandAroundCenter(i, i);
            if (oddPalindrome.length() > longest.length()) longest = oddPalindrome;

            string evenPalindrome = expandAroundCenter(i, i + 1);
            if (evenPalindrome.length() > longest.length()) longest = evenPalindrome;
        }
        return longest;
    }
};
