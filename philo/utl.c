/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouhrir <obouhrir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:48:48 by obouhrir          #+#    #+#             */
/*   Updated: 2023/06/14 19:33:38 by obouhrir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*----------------atoi----------------*/
long	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (sign * res);
}

long int	timeof(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000L) + (time.tv_usec / 1000L));
}

int	int_max(char *arg)
{
	long	nbr;

	nbr = ft_atoi(arg);
	if (nbr > 2147483647 || nbr <= 0)
		return (1);
	return (0);
}

int	invalid_nmb(char *arg)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (arg[i])
	{
		if (arg[i] == '+' || arg[i] == '-')
		{
			if (i > 0 || flag == 1)
				return (1);
			flag = 1;
		}
		else if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (1);
		i++;
	}
	if (flag == 1 && i == 1)
		return (1);
	return (0);
}

int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (int_max(av[i]) || invalid_nmb(av[i]))
		{
			printf("Wrong $ARG?\n");
			return (1);
		}
		i++;
	}
	return (0);
}
