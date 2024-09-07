#include <bits/stdc++.h>
using namespace std;

class Backtrack {
    vector<int> curr;
public:
    void backtrack(vector<int>&nums, int pos) {
        // Base case
        if (pos == nums.size() - 1)
        {
            // return current output -> curr;
            return;
        }

        //Phần đệ quy
        for (int i = 0; i < nums.size(); i++)
        {
            curr.push_back(i);
            backtrack(nums, pos + 1);
            curr.pop_back();
        }
    }
};