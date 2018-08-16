
// 《编程珠玑》P15

// 1、写起来简洁、更通用（字符串可是任意字符）T=O(nmlog m) S=O(mn)
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        map<string, vector<string> > mp;
        vector<string> ans;
        string tmp;

        // T=O(n)*O(mlog m)
        for (int i = 0; i < strs.size(); i++) {  // O(n)
            tmp = strs[i];
            sort(tmp.begin(), tmp.end()); // O(mlog m)
            mp[tmp].push_back(strs[i]);
        }

        // T=O(n)*O(m)
        for (auto mpit : mp) {
            if (mpit.second.size() > 1) {
                for (int i = 0; i < mpit.second.size(); i++) {
                    ans.push_back(mpit.second[i]);  // 题目只要求把所有的变位词压在一起，不必分组
                }
            }
        }

        return ans;
    }
};

// 2、效率更高，但字符串必须只可能是26个小写字母 T=O(nm) S=O(nm)
class Solution {
public:

    // T=O(m)。但如果字符串中不只有小写字母，而是任意ASCII字符，则需要128位而不是26位计数器
    void contSort(string& s, string& hash){
        vector<int> cont(26,0);

        for (int i=0; i < s.length(); i++) {
            cont[s[i]-'a']++;
        }
        for (int i=0; i < cont.size(); i++) {
            if (cont[i] < 1) {
                continue;
            }
            hash += (char)('a' + i);
            if (cont[i] > 1) {
//                char buff[80];
//                sprintf(buff, "%d", cont[i]);
//                hash += buff;
                hash += to_string(cont[i]);
            }
        }
    }

    vector<string> anagrams(vector<string> &strs) {
        if (strs.size() < 2) {
            return vector<string>();
        }

        vector<string> res;
        unordered_map<string, vector<string> > mp;

        // T=O(n)*O(m)
        for (int i=0; i<strs.size(); i++) {  // O(n)
            string hs;

            contSort(strs[i], hs);  // O(m)
            if(mp.find(hs) != mp.end()) {  // 没必要这么写，当没有下标中的key时，map（包括unordered_map）有自动初始化该key的能力（注意，vector没有此能力）
                mp[hs].push_back(strs[i]);
            } else {
                mp[hs] = vector<string>(1, strs[i]);
            }
        }

        // T=O(n)*O(m)
        for (auto mpit : mp) {  // O(n)
            if (mpit.second.size() > 1) {
                res.insert(res.end(), mpit.second.begin(), mpit.second.end());  // O(m)
            }
        }

        return res;
    }
};