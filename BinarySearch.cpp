#include <bits/stdc++.h>
using namespace std;

class BinarySearch {
public:
    int binary_search(vector<int>& nums, int low, int high, int target) {
        int l = low;
        int h = high;
        while (l <= h) {
            int m = l + (h-l)/2;
            if (nums[m] == target)
                return m;
            else if (nums[m] < target)
                l = m + 1;
            else
                h = m - 1;
        }
        return -1;
    }
};