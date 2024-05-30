#include <vector>
#include <cmath>
#include <numeric>
#include <string>
#include <algorithm>
using namespace std;

/*
    no：2982
    title：找出出现至少三次的最长特殊子字符串 Ⅱ
    label：水题，二分
    difcl: 中等
    variable：
        None
    题解：
        首先，可以通过遍历计算出数组v，使得v的值v[i]为从s[i]开始向右的相同字符组成字符串的长度。可以通过从后向前遍历得到。
        可以得到，当v[i] = 4 时，其实他也可以代表比他小的数字，即比他短的字符串。如，由4个a组成的字符串必定包含由前三个a组成的字符串。需要注意，由后三个a组成的字符串被v[i+1]表示了。
        由此可知，我们只需要对每个字母对应的全部特殊字符串长度进行排序，那么第三长的长度就是该字母所对应的特殊字符串的结果。
        
        本题跟2981的区别是输入的范围更大。这导致了对v排序这一过程虽然节省代码复杂度，但存在大量冗余操作。故，虽然能通过，但速度下降很大。

*/

class Solution {
public:

    struct CI{
        char c;
        int i;

        CI(char cc, int ii) {
            c = cc;
            i = ii;
        }
    };

    static bool cmp(CI a, CI b) {
        return a.i > b.i;
    }

    int maximumLength(string s) {
        
        vector<CI> v(s.length());
        
        int count = 0;
        char last = '#';
        for (int i = s.length() - 1; i >= 0 ; i--) {
            if (s[i] == last) {
                ++count;
            } else {
                count = 1;
                last = s[i];
            }
            v[i] = CI(s[i], count);
        }

        sort(v.begin(), v.end(), cmp);

        int dict[26] = {};
        int max = 0;
        for (int i = 0; i < v.size(); i++) {
            int idx = v[i].c - 'a';
            if (dict[idx] == 0 || dict[idx] == -1) {
                --dict[idx];
            } else if (dict[idx] == -2) {
                dict[idx] = v[i].i;
                if (max < v[i].i) {
                    max = v[i].i;
                }
            }
        }

        return max > 0 ? max : -1;
    }
};