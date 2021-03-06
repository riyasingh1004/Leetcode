// Time Complexity O(nm)

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();
        
        int lcs[n+1][m+1];
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                
                if (i == 0 || j == 0)
                    lcs[i][j] = 0;
                else if (text1[i-1] == text2[j-1])
                    lcs[i][j] = 1 + lcs[i-1][j-1];
                else
                    lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
        
        return lcs[n][m];    
    }
};

/* Printing Longest Common Subsequence
    int i = m, j = n;
    string lcs = "";
    while(i > 0 && j > 0) {
        if (text1[i-1] == text2[j-1]) {
            lcs += text1[i-1];
            i--;
            j--;
        }
        else if (t[i][j-1] > t[i-1][j]) j--;
        else i--;
    }
    return reverse(lcs.begin(),lcs.end());
*/