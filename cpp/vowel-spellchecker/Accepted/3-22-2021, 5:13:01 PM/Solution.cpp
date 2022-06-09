// https://leetcode.com/problems/vowel-spellchecker

class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, string> c;
        unordered_map<string, string> v;
        unordered_set<string> s1;
        for(string word: wordlist) {
            s1.insert(word);
            string temp = tolowerAlpha(word);
            if(c.find(temp) == c.end()) c[temp] = word;
            if(v.find(removeVowels(temp)) == v.end()) v[removeVowels(temp)] = word;
        }
        vector<string> res;
        for(string s: queries) {
            string temp = tolowerAlpha(s);
            if(s1.find(s) != s1.end()) res.push_back(s);
            else if(c.find(temp) != c.end()) res.push_back(c[temp]);
            else if(v.find(removeVowels(temp)) != v.end()) res.push_back(v[removeVowels(temp)]);
            else res.push_back("");
        }
        return res;
    }
    string removeVowels(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'u' || s[i] == 'i') s[i] = '*';
        }
        return s;
    }
    string tolowerAlpha(string s) {
        string str;
        for(char c: s) str += tolower(c);
        return str;
    }
};