// 3. 无重复字符的最长子串

```cpp
int lengthOfLongestSubstring(string s) {
    int maxLength = 1;
    unordered_set<int> us;
    int left = 0;
    int right = 0;
    for (; right < s.size(); right++) {
        while(left < right && us.count(s[right]) > 0) {
            us.erase(s[left++]);
        }
        us.insert(s[right]);
        maxLength = maxLength > (right - left + 1) ? maxLength : (right - left + 1);
    }
    return maxLength;
}
```


// 14. 最长公共前缀

```cpp

```
