/**
note the 'b':
    "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
    */
vector<string> wordBrea_bottom_up(string s, unordered_set<string>& wordDict) {
    vector<vector<string>> mem(s.size());
    
    for(int i = 0; i < s.size(); ++i) {
        auto sub(s.substr(0, i + 1));
        if(wordDict.find(sub) != wordDict.end()) {
            mem[i].push_back(sub);
        }
    }
    
    for(int i = 1; i < s.size(); ++i) {
        for(int k = 0; k < i; ++k) {
            auto sub(s.substr(k+1, i-k));
            if(!mem[k].empty() &&
               wordDict.find(sub) != wordDict.end()) {
                for(auto p: mem[k]) {
                    mem[i].push_back(p + " " + sub);
                }
           }
        }
    }
    
    return mem[s.size() -1];
}

bool wbreak(const string& s, int start, string& path, vector<string>& res, std::vector<bool> &possible, const unordered_set<string>& wordDict)
{
    bool ret = false;
    for(int i = start; i < s.size(); ++i) {
        auto sub(s.substr(start, i + 1 - start));
        if(wordDict.find(sub) != wordDict.end()) {
            if(i + 1 == s.size()) {
                res.push_back(path + sub);
                ret = true;
            } else if (possible[i+1]) {
                path.append(sub).append(" ");
                ret |= wbreak(s, i + 1, path, res, possible, wordDict);
                path.resize(path.size() - sub.size() - 1);
            }
        } 
    }  
    possible[start] = ret;
    return ret;
}

vector<string> wordBreak_top_down(string s, const unordered_set<string>& wordDict) {
    std::string path;
    vector<string> res;
    std::vector<bool> possible(s.size(), true);
    wbreak(s, 0, path, res, possible, wordDict);

    return res;
}