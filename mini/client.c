/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:48:11 by mradwan           #+#    #+#             */
/*   Updated: 2022/10/20 18:21:57 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	arg_check(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 3)
	{
		ft_printf("Error: Enter 3 arguments only");
		return (0);
	}
	while (av[1][i])
	{
		if ((av[1][i] >= 'a' && av[1][i] <= 'z') \
			|| (av[1][i] >= 'A' && av[1][i] <= 'Z'))
		{
			ft_printf("don't put letters, you can't");
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		pid;

	if (!arg_check(ac, av))
		return (0);
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("your pid is wrong");
		return (0);
	}
	sending(av[2], pid);
	return (0);
}
