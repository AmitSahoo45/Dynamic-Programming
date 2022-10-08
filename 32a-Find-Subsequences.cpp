#include <bits/stdc++.h>
using namespace std;

// House Robber Problem on Leetcode
class Solution
{
public:
    void print(vector<int> v)
    {
        for (auto x : v)
            cout << x << " ";
        cout << endl;
    }

    void printSubseq(vector<int> nums, vector<int> v, int index, int len)
    {
        if (index >= len)
        {
            print(v);
            return;
        }
        v.push_back(nums[index]);
        printSubseq(nums, v, index + 1, len);
        v.pop_back();
        printSubseq(nums, v, index + 1, len);
    }

    void subsequences(vector<int> &nums)
    {
        vector<int> v;
        int len = nums.size();
        printSubseq(nums, v, 0, len);
    }
};

int main()
{
    vector<int> nums = {2, 3, 0, 8, 6};
    Solution s;
    s.subsequences(nums);

    return 0;
}