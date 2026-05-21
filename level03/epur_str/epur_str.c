# include <unistd.h>


int main(int ac, char **av)
{
    if(ac == 2)
    {
        while(*av[1] && (*av[1] == 32 || *av[1] == 9))
            av[1]++;
        while(*av[1])
        {
            if(*av[1] == 32 || *av[1] == 9)
            {
                if(*(av[1] + 1) && *(av[1] + 1) != 32 && *(av[1] + 1) != 9)
                    write(1, " ", 1);
                
            }
            else
                write(1, &(*av[1]), 1);
            av[1]++;
        }
    }
    write(1, "\n", 1);
}
// int main(int ac, char **av)
// {
//     if(ac == 2)
//     {
//         int sp = 0;
//         int print = 0;
//         int i = 0;
//         while(av[1][i])
//         {
//             if(av[1][i] != 32)
//             {
//                 if(i == 0 || av[1][i - 1] == 32)
//                     sp++;
//             }
//             i++;
//         }
//         while(*av[1])
//         {
//             if(*av[1] == 32)
//             {
//                 if(print && sp > 1)
//                 {
//                     write(1, " ", 1);
//                     sp--;
//                     print = 0;
//                 }
//             }
//             else if(*av[1] != 32)
//             {
//                 write(1, &(*av[1]), 1);
//                 print = 1;
//             }
//             av[1]++;
//         }
//     }
//     write(1, "\n", 1);
// }