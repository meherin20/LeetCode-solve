#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maskPII(string s) {
       
        if (s.find('@') != string::npos) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
            
            int atPos = s.find('@');
            string name = s.substr(0, atPos);
            string domain = s.substr(atPos);
            
            return string(1, name[0]) + "*****" + name.back() + domain;
        }
        
      
        string digits = "";
        for (char c : s) {
            if (isdigit(c)) digits += c;
        }
        
        int country = digits.size() - 10;
        string last4 = digits.substr(digits.size() - 4);
        
        string result = "";
        if (country > 0) {
            result += "+";
            result += string(country, '*');
            result += "-";
        }
        
        result += "***-***-" + last4;
        return result;
    }
};
