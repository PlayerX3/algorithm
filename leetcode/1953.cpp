#include <vector>
using namespace std;

/*
    no：1953
    title：你可以工作的最大周数
    label：贪心，分配方案
    difcl: 中等
    variable：
        longest - 阶段数最长的工作的阶段数
        rest - 剩余工作的阶数总和
    题解：
        本题有一个核心概念，longest <= rest + 1 是工作能完成的充分必要条件。证明：
        必要性：工作能完成 -> longest <= rest + 1
            可以通过逆否命题证明，即：longest > rest + 1 -> 工作不能完成。
            公式可以变化成longest - rest > 1，此时longest所在工作剩余1个以上阶段工作未完成。
            如果先处理longest的工作再处理rest的工作，此时还可以再执行一次longest工作。即最终longest会乘以1个或以上的阶段未完成，切下次应执行的其他工作均已经完成。
            故此时工作不能完成，必要性得证。
        充分性：longest <= rest + 1 -> 工作能完成
            将任务视为一个分配方案，即将分配工作时间的过程转化为在[1, longest + rest]闭区间内分配整数（工作）的过程。在这个过程中，首先顺序分配奇数位置，再顺序分配偶数位置。
            可以发现，当工作按照耗时从高到低排序，按照之前的顺序分配。
            此时可以发现，longest不会超出奇数分配，后续rest工作也相同。
            此时符合不相邻，且全部工作能完成，故充分性得证。
        基于上述概念，本题可以大致分成两种情况:
            1. 工作可以全部完成，此时可以工作的周数为 longest + rest
            2. 工作无法全部完成，此时可以工作的周数为 2 * rest + 1

*/


class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {

        long long rest = 0;
        long long longest = 0;

        for (vector<int>::iterator it = milestones.begin(); it != milestones.end(); it++) {
            long long x = *it;
            rest += x;
            if (longest < x) {
                longest = x;
            }
        }
        rest -= longest;
        long long ans;
        if (longest > rest + 1) {
            ans = 2 * rest + 1;
        } else {
            ans = longest + rest;
        }

        return ans;
    }
};