#include <string>
#include <map>
#include <vector>
using namespace std;

/*
    no：1953
    title：找出最长的超赞子字符串
    label：奇偶性
    difcl: 困难
    variable：
        s - 字符串
        t - 字符串的字符奇偶性字典
    题解：
        本题有两个核心概念：
        1. 超赞字符串，即经过任意次交换后可变成回文的字符串，一定包含任意偶数个相同字符和最多一个奇数个相同字符。
        2. s[i: j] = s[0: j] - s[0: i - 1]。这里的减法指的是一个字符串去掉字串。
            这里，设t[i: j] 为 s[i: j] 每个字符的奇偶性，即，t[i: j] 中的每一位表示一个字符在s[i: j]中有奇数个还是偶数个。
            概念如下：s[i: j]为超赞字串 当且仅当 t[0: j] 与 t[0: i - 1] 仅有一位不相同。
            因为，除了不相同的那一位，任一其他位只有t[0: j] 与 t[0: i - 1] 都是奇或都是偶的情况下才能相减为偶数个。
        由概念2可知，可以遍历 s[0: j] 记录其 t[0: j]。若 t[0: j] 或 改变其任意一位的变体被记录过，如下表为i，则说明s[j, i]为超赞字符串。

*/


class Solution {
public:

    int thexor(int a, int b) {
        return (a | b) & ~(a & b);
    }

    int longestAwesome(string s) {
        map<int, int> m;
        vector<int> v;
        int e = 1;
        for (int i = 0; i < 10; i++) {
            v.push_back(e);
            e *= 2;
        }

        int t = 0;
        m[t] = -1;
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            int idx = c - '0';
            t = thexor(t, v[idx]);

            auto it = m.find(t);
            int len = 0;
            if (it == m.end()) {
                m[t] = i;
                len = 1;
            } else {
                len = i - it->second;
            }
            if (len > max) {
                max = len;
            }

            for (int j = 0; j < 10; j++) {
                int temp = thexor(t, v[j]);
                auto itt = m.find(temp);
                if (itt != m.end()) {
                    len = i - itt->second;
                    if (len > max) {
                        max = len;
                    }
                }
            }
        }

        return max;
    }
};