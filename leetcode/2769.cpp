#include <vector>
using namespace std;

/*
    no：2769
    title：找出最大的可达成数字
    label：水题
    difcl: 简单
    variable：
        num - 目标值
        t - 次数
        x - 值
    题解：
        因为要找最大的那个值，则说明应该每次都是减去 1，且尽量要减 t 次。每次 x 减去 1，都可以令 num 加或减 1。
        故如果 num 每次加 1 则属于双向奔赴，x的值可以设置的更大。
        故每次操作要求 x 减 1，num 加 1，攻击t次操作。操作结束后，num 应该等于 x。故操作前两者的差距应为 2 * t。
        所以x应该为 num + 2 * t

*/

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + 2 * t;
    }
};