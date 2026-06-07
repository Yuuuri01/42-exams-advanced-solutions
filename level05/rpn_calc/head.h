# ifndef RPN_CALC
# define RPN_CALC


# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int ft_atoi(char *s);
void rpn_calc(char *s);
char **ft_split(char *s);
void ft_putnbr(int nb);
void do_op(int *stack, int *index, char op, int *sign);

#endif