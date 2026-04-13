bool judgeCircle(char* moves) {
    int x = 0;
    int y = 0;
    for (int i = 0; moves[i] != '\0'; i++)
    {
        char c = moves[i];
        if(c == 'R')
        {
            x++;
        }
        else if(c == 'L')
        {
            x--;
        }
        else if(c == 'U')
        {   
            y++;
        }
        else if(c == 'D')
        {
            y--;
        }
    }
    return (x== 0 && y == 0);
}