int lengthOfLongestSubstring(char* s) {
    int char_map[128];
    for(int i = 0; i<128;i++)
    {
        char_map[i] = -1;
    }
    int left = 0;
    int max_len = 0;
    for(int right = 0; s[right] != '\0'; right++)
    {
        char c = s[right];
        if(char_map[(unsigned char)c] >= left)
        {
            left = char_map[(unsigned char)c] + 1;
        }
        char_map[(unsigned char)c] = right;
        int current_len = right - left + 1;
        if(current_len > max_len)
        {
            max_len = current_len;
        }
}
        return max_len;
    }
    