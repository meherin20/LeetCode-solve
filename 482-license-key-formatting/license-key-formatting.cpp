class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string clean = "";
        
        
        for (char c : s) {
            if (c != '-') {
                clean += toupper(c);
            }
        }

        string result = "";
        int count = 0;

        
        for (int i = clean.length() - 1; i >= 0; i--) {
            result += clean[i];
            count++;

            if (count == k && i != 0) {
                result += '-';
                count = 0;
            }
        }

       
        reverse(result.begin(), result.end());
        return result;
    }
};
