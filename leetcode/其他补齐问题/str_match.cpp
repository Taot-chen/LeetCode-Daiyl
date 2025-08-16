#include <cstring>
#include <vector>
#include <iostream>

int brute_force(std::string& text, std::string& pattern) {
    int n = text.size();
    int m = pattern.size();
    if (n == 0 || m == 0 || n < m) return -1;
    for (int i = 0; i < n - m + 1; i++) {
        for (int j = 0; j < m; j++) {
            if (text[i+j] ==  pattern[j]) {
                if (j == m-1) return i;
            } else break;
        }
    }
    return -1;
}

void makeNext(const std::string& pattern, std::vector<int>& nxt) {
    nxt.resize(pattern.size());
    for (int i = 1; i < nxt.size(); i++) {
        if (pattern[nxt[i - 1]] == pattern[i]) {
            nxt[i] = nxt[i - 1] + 1;
        }
    }
}


int kmp(std::string& text, std::string& pattern) {
    std::vector<int> nxt;
    makeNext(pattern, nxt);
    for (int i = 0, j = 0; i + j < text.size(); ) {
        if (pattern[j] == text[i+j]) {
            if (j == pattern.size() - 1) return i;
            else j++;
        } else {
            if (j && nxt[j-1]) {
                i = i + j - nxt[j-1];
                j = nxt[j-1];
            } else i++;
        }
    }
    return -1;
}

int main() {
    std::string text = "ABCABCABFXIUDSABCABSNIK";
    std::string pattern = "ABCABS";
    int ret = brute_force(text, pattern);
    std::cout << "brute_force ret: " << ret << std::endl;

    ret = kmp(text, pattern);
    std::cout << "kmp ret: " << ret << std::endl;
    return 0;
}