bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int i = 0;
    int j = 0;
    int k = 0;
    int p = 0;
    while(i < word1Size && j < word2Size)
    {
        if(word1[i][k] != word2[j][p])
        {
            return false;
        }
        k++;
        p++;
        if(word1[i][k] == '\0')
        {
            i++;
            k = 0;
        }
        if(word2[j][p] == '\0')
        {
            j++;
            p = 0;
        }
    }
    return (i == word1Size && j == word2Size);
}