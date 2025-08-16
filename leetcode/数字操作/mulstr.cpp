#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

template<class T>
void print_vector(std::vector<T>& val) {
    for (int i = 0; i < val.size(); i++) {
        std::cout << val[i];
    }
}

void print_str(std::string& s) {
    for (int i = 0; i < s.size(); i++) {
        std::cout << s[i];
    }
}

std::vector<char> str_add(std::string s1, std::string s2) {
    int len1 = s1.size(), len2 = s2.size();
    int maxlen = len1 > len2 ? len1 : len2;
    std::vector<int> sum(maxlen + 1, 0);
    std::vector<char> ret;
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    for (int i = 0; i < maxlen; i++) {
        sum[i] += (i > len1 - 1 ? 0 : s1[i] - '0') + (i > len2 - 1 ? 0 : s2[i] - '0');
    }
    for (int i = 0; i < maxlen; i++) {
        if (sum[i] > 9) {
            int tmp = sum[i] % 10;
            sum[i + 1] += 1;
            sum[i] = tmp;
        }
    }
    int idx = maxlen;
    while(idx >= 0 && !sum[idx]) idx--;
    if (idx == -1) idx += 1;
    for ( ;idx >= 0; idx--) {
        ret.emplace_back(sum[idx] + '0');
    }
    return ret;
}

std::vector<char> str_mul(std::string s1, std::string s2) {
    int len1 = s1.size(), len2 = s2.size();
    int maxlen = len1 > len2 ? len1 : len2;
    std::vector<char> ret(len1 + len2, '0');
    std::reverse(s1.begin(), s1.end());
    std::reverse(s2.begin(), s2.end());
    for (int i = 0; i < len1; i++) {
        std::vector<int> midret(len1 + len2, 0);
        std::vector<char> midstr;
        for (int j = 0; j < len2; j++) {
            midret[i + j] = (s1[i] - '0') * (s2[j] - '0');
        }
        for (int ii = 0; ii < midret.size(); ii++) {
            if (midret[ii] > 9) {
                int tmp = midret[ii] % 10;
                midret[ii+1] += midret[ii] / 10;
                midret[ii] = tmp;
            }
        }
        int idx = midret.size() - 1;
        while (idx >= 0 && !midret[idx]) idx--;
        if (idx == -1) idx += 1;
        for (; idx >= 0; idx--) midstr.emplace_back(midret[idx] + '0');
        std::string ret1(ret.begin(), ret.end());
        std::string midstr1(midstr.begin(), midstr.end());
        ret = str_add(ret1, midstr1);
    }
    return ret;
}

int main() {
    std::vector<std::string> inputs = {"9"}; //, "12345", "12", "0", "999999999999999", "9999999999999999999"}; //, "-10", "-123"};
    for (int i = 0; i < inputs.size(); i++) {
        for (int j = 0; j < inputs.size(); j++) {
            std::vector<char> sum = str_add(inputs[i], inputs[j]);
            print_str(inputs[i]);
            std::cout << " + ";
            print_str(inputs[j]);
            std::cout << " = ";
            print_vector(sum);
            std::cout << std::endl;
        }
    }
    for (int i = 0; i < inputs.size(); i++) {
        for (int j = 0; j < inputs.size(); j++) {
            std::vector<char> mul = str_mul(inputs[i], inputs[j]);
            print_str(inputs[i]);
            std::cout << " * ";
            print_str(inputs[j]);
            std::cout << " = ";
            print_vector(mul);
            std::cout << std::endl;
        }
    }
    return 0;
}
