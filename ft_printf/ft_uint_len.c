unsigned int    ft_uint_len(unsigned int n)
{
        unsigned int    len;

        if (n == 0)
                return (1);
        len = 0;
        while (n > 0)
        {
                n /= 10;
                len++;
        }
        return (len);
}
