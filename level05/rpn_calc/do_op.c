
void do_op(int *stack, int *index, char op, int *sign)
{
    if(!stack)
    {
        *sign = -1;
        return;
    }
    int nb2 = stack[*index];
    int nb1 = stack[*index - 1];
    int res = 0;
    
    if(op == '+')
        res = nb1 + nb2;
    else if(op == '-')
        res = nb1 - nb2;
    else if(op == '/')
    {
        if(nb2 == 0)
        {
            *sign = -1;
            return;
        }
        else
            res = nb1 / nb2;
    }
    else if(op == '%')
    {
        if(nb2 == 0)
        {
            *sign = -1;
            return;
        }
        else
            res = nb1 % nb2;
    }
    else if(op == '*')
        res = nb1 * nb2;
    
    stack[*index - 1] = res;
    (*index)--;
}