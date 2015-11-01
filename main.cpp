
class Solution {
public:


    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)return 0;
    int *visited = (int *)malloc(sizeof(int)*256);
    for (int i = 0; i < 256;  i++)
        visited[i] = -1;

    visited[s[0]] = 0;
    int cur_len = 1, max_len = 1;
    int prev;
    for(int i = 1;i<s.size();i++){
        prev = visited[s[i]];
        if(prev == -1 || i - cur_len>prev)
            cur_len++;
        else{
            if(max_len<cur_len)
                max_len = cur_len;

            cur_len = i - prev;

        }
        visited[s[i]] = i;

    }
    if(max_len<cur_len)
                max_len = cur_len;
    return max_len;

    }
};
