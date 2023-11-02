#include "../include/fdf.h"

static int	to_skip(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\r')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	return (0);
}


//NOTE: Probably, we will need to replace it with
// atoi_base to be able read HEX
int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (to_skip(str[i]) && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * neg);
}


// int	main()
// {	
// 	char *str = "-1 0 -1323 -3232 ";

// 	printf("res = %d\n", ft_atoi(str));
// 	printf("res = %d\n", ft_atoi(str + 2));
// 	printf("res = %d\n", ft_atoi(str + 4));
// 	printf("res = %d\n", ft_atoi(str + 10));

// }
