#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<long long> pq;

        for (int num : target) {
            sum += num;
            pq.push(num);
        }

        while (true) {
            long long maxVal = pq.top();
            pq.pop();

            long long restSum = sum - maxVal;

           
            if (maxVal == 1 || restSum == 1)
                return true;

          
            if (restSum == 0 || maxVal <= restSum)
                return false;

            long long prev = maxVal % restSum;
            if (prev == 0)
                return false;

          
            sum = restSum + prev;
            pq.push(prev);
        }
    }
};
