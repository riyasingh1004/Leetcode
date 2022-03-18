// Timee Complexity O(n)

class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1)
            return s;
        
        vector<string> rows(numRows);
        int goingDown = 0;
        int currRow = 0;
        
        for (char c : s) {
            
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows-1)
                goingDown = !goingDown;
            currRow += goingDown ? 1 : -1;
        }
        
        string res = "";
        for (string row : rows)
            res += row;
        
        return res;
        
    }
};