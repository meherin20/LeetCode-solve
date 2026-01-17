
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n=s.length();
        for(int len=1;len<=n/2;len++){
            if(n%len!=0)
            continue;
            string part = s.substr(0, len);
            string formed = "";
            for (int i = 0; i < n / len; i++) {
                formed += part;
            }
            if (formed == s)
                return true;


        }
        return false;
        
    }
};