#include <vector>
using namespace std;

class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int totEven = 0, totOdd = 0;

        
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0)
                totEven += nums[i];
            else
                totOdd += nums[i];
        }

        int preEven = 0, preOdd = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            int sufEven, sufOdd;

            if (i % 2 == 0) {
                sufEven = totEven - preEven - nums[i];
                sufOdd  = totOdd  - preOdd;
            } else {
                sufEven = totEven - preEven;
                sufOdd  = totOdd  - preOdd - nums[i];
            }

            int newEven = preEven + sufOdd;
            int newOdd  = preOdd  + sufEven;

            if (newEven == newOdd)
                count++;   
            if (i % 2 == 0)
                preEven += nums[i];
            else
                preOdd += nums[i];
        }

        return count;
    }
};
