#include <vector>
#include <cmath>
using namespace std;

/*
    no：2903
    title：找出满足差值的下标 Ⅰ
    label：水题，遍历
    difcl: 简单
    variable：
        None
    题解：
        需要下标和内容均具有差值，可以指导，下标的差值是整数连续的，故搜索内容时可以跳过临近的下标。

*/

class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> res = {-1, -1};
        for (int i = 0; i < (int)nums.size() - indexDifference; i++) {
            for (int j = i + indexDifference; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) >= valueDifference) {
                    res[0] = i;
                    res[1] = j;
                }
            }
        }
        return res;
    }
};