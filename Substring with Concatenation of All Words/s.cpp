class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.empty() || words.empty()) return res;
        int n = s.size(), m = words.size(), len = words[0].size();
        unordered_map<string, int> count;
        for(string word : words) count[word]++;
        for(int i = 0; i < len; i++) { // starting index
            int left = i, cnt = 0;
            unordered_map<string, int> seen;
            for(int j = i; j <= n - len; j += len) {
                string word = s.substr(j, len);
                if(count.find(word) != count.end()) { // if word is present in words
                    seen[word]++;
                    cnt++; // increasing count of words seen till now
                    while(seen[word] > count[word]) { // checking for possibility of any extra word
                        seen[s.substr(left, len)]--;
                        left += len;
                        cnt--;
                    }
                    if(cnt == m) { // if all words are present
                        res.push_back(left);
                        seen[s.substr(left, len)]--;
                        left += len;
                        cnt--;
                    }
                } else {
                    seen.clear();
                    cnt = 0;
                    left = j + len;
                }
            }
        }
        return res;
    }
};