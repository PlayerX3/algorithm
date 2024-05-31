#include <vector>
#include <cmath>
#include <numeric>
#include <string>
#include <algorithm>
using namespace std;

/*
    no：2965
    title：找出缺失和重复的数字
    label：水题
    difcl: 简单
    variable：
        None
    题解：
       最简单且最快的做法就是用一个 n * n + 1 数组存每个下标出现的次数。不过这需要较大的空间。
       空间较少的方法就是将每个数字与他对应下标处的位置对调，这样就可以不额外的空间了，代价是破坏了原数组。

*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> res(2, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; ) {
                int ii = (grid[i][j] - 1) / n;
                int jj = (grid[i][j] - 1) % n;
                if (i == ii && j == jj || (res[0] == grid[i][j])) {
                    j++;
                } else if (grid[i][j] == grid[ii][jj]) {
                    res[0] = grid[i][j];
                    j++;
                } else {
                    int temp = grid[i][j];
                    grid[i][j] = grid[ii][jj];
                    grid[ii][jj] = temp;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ++count;
                if (grid[i][j] != count) {
                    res[1] = count;
                    break;
                }
            }
            if (res[1] != -1) {
                break;
            }
        }
        return res;
    }
};