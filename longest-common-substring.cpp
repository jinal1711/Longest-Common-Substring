#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 

using namespace std;

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    int n = s1.size();
    int m = s2.size();

    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxLen = 0;        
    int endIndex = 0;      

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndex = i - 1; 
                }
            } else {
                dp[i][j] = 0;
            }
        }
    }

    
    cout << "\nLookup Table:\n   ";
    for (int j = 0; j < m; j++) {
        cout << setw(3) << s2[j];
    }
    cout << "\n";

    for (int i = 0; i <= n; i++) {
        if (i > 0) cout << s1[i - 1] << " ";
        else cout << "  ";
        for (int j = 0; j <= m; j++) {
            cout << setw(3) << dp[i][j];
        }
        cout << "\n";
    }

    
    string longestSubstring = s1.substr(endIndex - maxLen + 1, maxLen);

    cout << "\nThe Longest Common Substring: " << longestSubstring << "\n";
    cout << "Length: " << maxLen << endl;

    return 0;
}
