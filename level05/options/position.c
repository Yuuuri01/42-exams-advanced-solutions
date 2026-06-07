int get_position(char c)
{
    char s[] = "abcdefghijklmnopqrstuvwxyz";

    int i = 0;
    while(s[i])
    {
        if(s[i] == c)
            return i;
        i++;
    }
    return -1;
}