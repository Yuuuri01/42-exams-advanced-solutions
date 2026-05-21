# include <unistd.h>


// void	print_bits(unsigned char octet) //octet 2
// {
//     int i = 128;
//     while(octet >= 0 && i)//0000 0011
//     {
//         if(octet / i)
//         {
//             write(1, "1", 1);
//             octet -= i;
//         }
//         else
//             write(1, "0", 1);
//         i /= 2;
//     }
// }
void	print_bits(unsigned char octet)
{
    int i = 128;
    while(i > 0)
    {
        if(i & octet)        
            write(1, "1", 1);
        else
            write(1, "0", 1);
        i /= 2;
    }
}
int main()
{
    print_bits(5);
    write(1, "\n", 1);
}