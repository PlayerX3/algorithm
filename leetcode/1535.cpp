#include <vector>
using namespace std;

/*
    no：1535
    title：找出数组游戏的赢家
    label：分情况分析，遍历
    variable：
        arr - 数组
        k - 获胜所需回合数
    题解：
        首先，考虑 k >= arr.size 的情况：
            此时，数组中的任意非最大值，最大的连续获胜情况为：第二大的值在arr[0]，最大值在 arr[-1]
            可以知道，此情况下的最大获胜回合数为 arr.size - 1 < k
            故，非最大值均无法赢下，只有最大值肯定获胜。故此时答案为 max(arr)
        然后，考虑 k < arr.size 的情况：
            此时，获胜的数字无论是最大值，在第一次遍历时，一定会被选中。
            可以分为两种情况：
                第一次遍历获胜或第一次遍历未获胜
                获胜：此时获胜的数可以是最大值，也可以不是最大值，在第一次遍历过程中即可得到结果。时间复杂度为 O(n)。
                未获胜：此时获胜的数一定是最大值，因为第一次遍历后arr[0]的位置是最大值，无论如何也不会失败了，其他数字再也没有机会获胜。

*/


class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int ans = 0;
        if (k >= arr.size()) {
            for (int i = 0; i < arr.size(); i++) {
                if (ans < arr[i]) {
                    ans = arr[i];
                }
            }
        } else {
            int count = 0;
            int n = 2 * arr.size();
            int idx = -1;
            int next = -1;
            for (int i = 0; i < n; i++) {
                idx = i % arr.size();
                next = (i + 1) % arr.size();

                if (arr[idx] > arr[next]) {
                    count++;
                    int temp = arr[idx];
                    arr[idx] = arr[next];
                    arr[next] = temp;
                } else {
                    count = 1;
                }

                if (count == k) {
                    ans = arr[next];
                    break;
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int ans = 0;
        if (k >= arr.size()) {
            for (int i = 0; i < arr.size(); i++) {
                if (ans < arr[i]) {
                    ans = arr[i];
                }
            }
        } else {
            int count = 0;
            int max = arr[0];
            for (int i = 1; i < arr.size(); i++) {
                if (max > arr[i]) {
                    count++;
                } else {
                    count = 1;
                    max = arr[i];
                }

                if (count == k) {
                    break;
                }
            }
            ans = max;
        }
        return ans;
    }
};