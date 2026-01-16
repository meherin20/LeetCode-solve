class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0, lower = 0;
        
        for (char c : word) {
            if (isupper(c)) upper++;
            else lower++;
        }

       
        if (upper == word.length()) return true;

        
        if (lower == word.length()) return true;

       
        if (isupper(word[0]) && lower == word.length() - 1)
            return true;

        return false;
    }
};
