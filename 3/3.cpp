#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_visit;
        int left = 0;
        int max_length = 0;
        for(int i = 0; i < s.size(); i++){
            char curr_char = s[i];
            if(last_visit.count(i) && last_visit[curr_char] >= left) {
                left = last_visit[curr_char] + 1;
            }
            last_visit[curr_char] = i;
            max_length = max(max_length, i - left + 1);
        }
        return max_length;
    }
};