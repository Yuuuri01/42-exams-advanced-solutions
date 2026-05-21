

unsigned char	reverse_bits(unsigned char octet)
{
    return ((octet << 4) | (octet >> 4));
}



// # include <stdio.h>
// # include <stdlib.h>
// int main(int ac, char **av)
// {
//     int octet = atoi(av[1]);
//     octet = reverse_bits(octet);
//     printf("%d\n", octet);
// }