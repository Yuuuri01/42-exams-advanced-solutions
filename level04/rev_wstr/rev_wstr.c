# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>



// int main(int ac, char **av)
// {
//     if(ac == 2)
//     {
//         char *s;
//         int i = 0;
//         while(*av[1] && *(av[1] + 1))
//         {
//             i++;
//             av[1]++;
//         }
//         while(*av[1] && i >= 0)
//         {
//             while(*av[1] && *av[1] != 32 && *av[1] != 9)
//             {
//                 av[1]--;
//                 i--;
//             }
//             s = av[1] + 1;
//             while(*s && *s != 32 && *s != 9)
//                 write(1, &(*s++), 1);
//             if(i != -1 && (!*s || *s == 32 || *s == 9))
//                 write(1, " ", 1);
//             av[1]--;
//             i--;

//         }
//         write(1, "\n", 1);
//     }
// }
int main(int ac, char **av)
{
    if(ac == 2)
    {
        int i = 0;
        int j = 0;
        while(av[1][i] && av[1][i + 1])
            i++;
        while(i >= 0)
        {
            while(av[1][i] && (av[1][i] != 32 && av[1][i] != 9))
                i--;
            j = i + 1;
            while(av[1][j] && av[1][j] != ' ' && av[1][j] != '\t')
                write(1, &av[1][j++], 1);
            if(i != -1 && (av[1][j] == '\0' || av[1][j] == 32 || av[1][j] == 9))
                write(1, " ", 1);   
            i--;
        }
    }
    write(1, "\n", 1);
}
//"le temps du mepris precede celui de l'indifference"