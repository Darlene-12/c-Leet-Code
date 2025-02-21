#include <iostream>
#include <vector>

using namespace std;

/**
 * Converts a string into a zigzag pattern and reads it row-by-row.
 * 
 * @param s - The input string.
 * @param numRows - The number of rows for the zigzag pattern.
 * @return - The transformed string read row-by-row.
 */
string convert(string s, int numRows) {
    // Edge case: If numRows is 1 or string length is less than numRows, return the original string.
    if (numRows == 1 || numRows >= s.length()) {
        return s;
    }

    // Create a vector of strings to store each row separately
    vector<string> rows(min(numRows, int(s.length())));

    int curRow = 0; // Tracks the current row we are writing to
    bool goingDown = false; // Determines if we are moving downward or upward

    // Loop through each character in the string
    for (char c : s) {
        rows[curRow] += c; // Append the character to the current row

        // If we reach the top or bottom row, change direction
        if (curRow == 0 || curRow == numRows - 1) {
            goingDown = !goingDown; // Toggle direction
        }

        // Move to the next row: either down (+1) or up (-1)
        curRow += goingDown ? 1 : -1;
    }

    // Concatenate all rows to form the final zigzag converted string
    string result;
    for (string row : rows) {
        result += row;
    }

    return result;
}

// Driver function to test the convert function
int main() {
    // Test cases
    cout << convert("PAYPALISHIRING", 3) << endl;  // Output: "PAHNAPLSIIGYIR"
    cout << convert("PAYPALISHIRING", 4) << endl;  // Output: "PINALSIGYAHRPI"
    cout << convert("A", 1) << endl;               // Output: "A"
    cout << convert("HELLO", 2) << endl;           // Output: "HLOEL"
    cout << convert("JAVASCRIPT", 5) << endl;      // Output: "JCTVSRAIPA"

    return 0;
}
