// 1）tolower()
class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);
        }
        return s;
    }
};


// 2) ASCII, 'a' = 'A' + 32
class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] += 32;
            }
        }
        return s;
    }
};
