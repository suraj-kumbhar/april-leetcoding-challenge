// Group Anagrams
// Solution
// Given an array of strings, group anagrams together.

// Example:

// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output:
// [
//   ["ate","eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note:

// All inputs will be in lowercase.
// The order of your output does not matter.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> m;
        for (string s : strs)
        {
            string s2 = s;
            sort(s2.begin(), s2.end());
            m[s2].push_back(s);
        }
        vector<vector<string>> v;
        for (auto i : m)
        {
            v.push_back(i.second);
        }
        return v;
    }
};