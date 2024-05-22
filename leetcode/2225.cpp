#include <vector>
#include <map>
using namespace std;

/*
    no：2225
    title：找出输掉零场或一场比赛的玩家
    label：字典，列表
    difcl: 中等
    variable：
        arr - 数组
        k - 获胜所需回合数
    题解：
        可知遍历matches数组即可知道每个数是否参加过比赛，输了几次。
        只需要设计一个合适的数据结构存储这些信息，然后排序即可输出结果
        可以用map记录参加比赛的玩家。
        也可以用数组记录，下标代表玩家，下标代表的内容表示玩家输的次数。

*/


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> m;
        for (int i = 0; i < matches.size(); i++) {
            auto itw = m.find(matches[i][0]);
            if (itw == m.end()) {
                m[matches[i][0]] = 0;
            }
            auto itl = m.find(matches[i][1]);
            if (itl == m.end()) {
                m[matches[i][1]] = 1;
            } else {
                m[matches[i][1]]++;
            }
        }

        vector<int> v0;
        vector<int> v1;

        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second  == 0) {
                v0.push_back(it->first);
            } else if (it->second == 1) {
                v1.push_back(it->first);
            }
        }

        vector<vector<int>> v;
        v.push_back(v0);
        v.push_back(v1);
        return v;
    }
};


class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int v[100005] = {};
        int vis[100005] = {};
        for (int i = 0; i < matches.size(); i++) {
            vis[matches[i][0]] = 1;
            vis[matches[i][1]] = 1;
            v[matches[i][1]]++;
        }

        vector<int> v0;
        vector<int> v1;

        for (int i = 0; i < 100001; i++) {
            if (v[i] == 0 && vis[i] == 1) {
                v0.push_back(i);
            } else if (v[i] == 1) {
                v1.push_back(i);
            }
        }

        vector<vector<int>> res;
        res.push_back(v0);
        res.push_back(v1);
        return res;
    }
};