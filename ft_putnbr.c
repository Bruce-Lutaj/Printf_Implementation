
#include "ft_printf.h"

static int	cifre(long n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nl;

	len = cifre(n);
	nl = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (nl == 0)
		str[0] = 48;
	str[len] = '\0';
	if (nl < 0)
	{
		str[0] = '-';
		nl = -nl;
	}
	len -= 1;
	while (nl != 0)
	{
		str[len] = nl % 10 + 48;
		nl = nl / 10;
		len--;
	}
	return (str);
}

int	ft_putnbr(int n)
{
	int		len;
	char	*num;

	num = ft_itoa(n);
	len = ft_putstr(num);
	free (num);
	return (len);
}
