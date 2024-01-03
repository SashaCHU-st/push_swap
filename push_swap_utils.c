# include <stdlib.h>
# include <unistd.h>
int	ft_atoi(const char *str)
{
	size_t	i;
	long	number;
	int		sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		sign = -1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number = number * 10 + (str[i] - 48);
		if (number < 0)
		{
			if (sign > 0)
				return (-1);
			return (0);
		}
		i++;
	}
	return (number * sign);
}
