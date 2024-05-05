
#include "ft_printf.h"

static int	num_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;

	len = num_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len -= 1;
	while (n != 0)
	{
		str[len] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (str);
}

int	ft_putnbr_u(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
	{
		num = ft_uitoa(n);
		len = ft_putstr(num);
		free (num);
	}
	return (len);
}
