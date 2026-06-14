# include <unistd.h>
# include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}
char *units(int nb, int type)
{
    if(type == 1)
    {
        if(nb == 1)
        return " second ago.";
    return " seconds ago.";
    }
    if(type == 2) 
    {
        if(nb == 1)
            return " minute ago.";
        return " minutes ago.";
    }
    if(type == 3) 
    {
        if(nb == 1)
            return " hour ago.";
        return " hours ago.";
    }
    if(type == 4)
    {
        if(nb == 1)
            return " day ago.";
        return " days ago.";
    } 
    if(type == 5)
    {
        if(nb == 1)
            return " month ago.";
        return " months ago.";
    } 
    return "";
}
int get_len(int nb)
{
    if(nb == 0)
        return 1;
    int size = 0;
    while(nb)
    {
        size++;
        nb /= 10;
    }    
    return size;
}
int get_time(unsigned int sec, int *type)
{
    if(sec < 60)//seconds
    {
        *type = 1;
        return sec;
    }
    else if(sec < 3600)//minutes
    {
        *type = 2;
        return sec / 60;
    }
    else if(sec < 86400)//hours
    {
        *type = 3;
        return sec / 3600;
    }
    else if(sec < 2592000)
    {
        *type = 4;
        return sec / 86400;
    }
    else
    {
        *type = 5;
        return sec / 2592000;
    }
}
char    *moment(unsigned int duration)
{
    int i;
    int type;
    char *time;
    int nb_time;
    int size_nb;
    int size_type;
    char *type_time;
    
    type = 0;
    nb_time = get_time(duration, &type);
    type_time = units(nb_time, type);
    size_nb = get_len(nb_time);
    size_type = ft_strlen(type_time);
    time = malloc((size_nb + size_type + 1) * sizeof(char));
    if(!time)
        return NULL;
    i = size_nb - 1;
    if(nb_time == 0)
        time[0] = '0';
    else
    {
        while(nb_time)
        {
            time[i--] = nb_time % 10 + 48;
            nb_time /= 10;
        }
    }
    i = size_nb;
    while(*type_time)
        time[i++] = *type_time++;
    time[i] = '\0';
    return time;
}
/*
# include <stdio.h>
int main()
{
    unsigned int nb = -25920000;
    char *t = moment(nb);
    printf("%s", t);
}
*/
