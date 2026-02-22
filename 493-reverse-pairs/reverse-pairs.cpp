#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return (int)mergeSortCount(nums, 0, (int)nums.size() - 1);
    }

private:
    long long mergeSortCount(vector<int>& a, int l, int r) {
        if (l >= r) return 0;

        int m = l + (r - l) / 2;
        long long count = 0;
        count += mergeSortCount(a, l, m);
        count += mergeSortCount(a, m + 1, r);

        // Count cross pairs: i in [l..m], j in [m+1..r]
        int j = m + 1;
        for (int i = l; i <= m; i++) {
            while (j <= r && (long long)a[i] > 2LL * (long long)a[j]) {
                j++;
            }
            count += (j - (m + 1));
        }

        // Merge step
        vector<int> temp;
        temp.reserve(r - l + 1);
        int i = l;
        j = m + 1;

        while (i <= m && j <= r) {
            if (a[i] <= a[j]) temp.push_back(a[i++]);
            else temp.push_back(a[j++]);
        }
        while (i <= m) temp.push_back(a[i++]);
        while (j <= r) temp.push_back(a[j++]);

        for (int k = 0; k < (int)temp.size(); k++) {
            a[l + k] = temp[k];
        }

        return count;
    }
};