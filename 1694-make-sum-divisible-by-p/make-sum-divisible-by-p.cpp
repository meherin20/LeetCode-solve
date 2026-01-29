#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long total = 0;
        for (int x : nums) total += x;
        int need = (int)(total % p);
        if (need == 0) return 0;

        unordered_map<int,int> last;   // prefix_mod -> latest index
        last.reserve(nums.size() * 2);
        last.max_load_factor(0.7f);
        last[0] = -1;

        int pref = 0;
        int ans = (int)nums.size();

        for (int i = 0; i < (int)nums.size(); i++) {
            pref = (pref + nums[i]) % p;
            int want = (pref - need) % p;
            if (want < 0) want += p;

            auto it = last.find(want);
            if (it != last.end()) {
                ans = min(ans, i - it->second);
            }
            last[pref] = i; 
        }

        return (ans == (int)nums.size()) ? -1 : ans; 
    }
};
