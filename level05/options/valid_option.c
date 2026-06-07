int check_valid(char **s)
{
    int i = 0;
    while(s[i])
    {
        if(s[i][0] != '-')
            return 0;
        i++;
    }
    return 1;
}