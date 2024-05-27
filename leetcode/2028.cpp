#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

/*
    no：2028
    title：找出缺失的观测数据
    label：水题
    difcl: 中等
    variable：
        None
    题解：
        rolls.size() = m。mean * (m + n) 为总和，减去 rolls.sum() 就是确实的数字的和SM。
        剩下的任务就是将SM分配到n个骰子上。
        最简单的想法是每次能分配6就分配6，直到剩余骰子数量和剩余点数相同时，将剩余骰子全部设为1。
        为了避免剩余点数小于剩余骰子数量，在剩余点数减去6后的点数小于剩余骰子数量减1后的数量时，不减6，而是减x < 6使得 减去后骰子数量和剩余点数相同。

*/

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum_m = accumulate(rolls.begin(), rolls.end(), 0);
        int sum = mean * (rolls.size() + n);
        int sum_n = sum - sum_m;

        vector<int> res;
        if (!(sum_n > n * 6 || sum_n < n)) {
            int rest_rolls = n;
            int rest_num = sum_n;
            while (rest_rolls != rest_num) {
                int roll = min(rest_num - rest_rolls + 1, 6);
                res.push_back(roll);
                rest_num -= roll;
                --rest_rolls;
            }
            for (int i = 0; i < rest_rolls; i++) {
                res.push_back(1);
            }
        }
        
        return res;
    }
};