#include<unistd.h>

int	base_length(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	validate_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[i + 1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (base[i] != '-' && base[i] != '+' && (base[i] > 31 && base [i] < 127))
		i++;
	if (base[i] == '\0')
		return (1);
	else
		return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
    long int i;

    i = nbr;
    if(validate_base(base) == 1)
    {
        if (i < 0)
        {
            write (1, "-", 1);
            i = i * - 1;
        }
        if (i >= base_length(base))
        {
            ft_putnbr_base(i / base_length(base), base);
            i = i % base_length(base); 
        }
        write(1, &base[i], 1);
    }
}

int main(void)
{
    int n = 31;
    ft_putnbr_base(n, "0123456789ABCDEF");
}