/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 21:52:09 by mradwan           #+#    #+#             */
/*   Updated: 2022/11/14 05:58:43 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	value;
	int					d;

	i = 0;
	sign = 1;
	d = 0;
	value = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
			i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = sign * -1;
	while (str[i] == '0')
			i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i++] - 48);
		d++;
	}
	if (d > 19 || value >= 9223372036854775808ULL)
		return (-(sign == 1));
	return (value * sign);
}

// in the sending.. we must convert each char to binary by this function
// so if (char & 1) after shift is = 1 it will send to SIGUSR 1

void	sending(char *message, int pid)
{
	int		i;
	char	x;
	char	bit;
	int		shift;
	int		check;

	i = 0;
	while (message[i] != '\0')
	{
		x = message[i];
		shift = 7;
		while (shift >= 0)
		{
			bit = (x >> shift) & 1;
			if (bit == 1)
				check = kill(pid, SIGUSR1);
			else
				check = kill(pid, SIGUSR2);
			shift--;
			usleep(1000);
		}
		i++;
	}
	if (check == -1)
		ft_printf("wrong pid");
}

// we here create static char and its = 0 in "8" bits 0000 0000
// after that if the recieved signal is = SIGUSR1  we shift it to
// the left and | 1 because the resieved signal is 1 ..
// char will plus its "1 or 0" value of bits after shifting

void	recieve_sig(int sig)
{
	static int	i;
	static char	c;

	if (sig == SIGUSR1)
		c = c << 1 | 1;
	if (sig == SIGUSR2)
		c = c << 1 | 0;
	i++;
	if (i == 8)
	{
		i = 0;
		ft_printf("%c", c);
		c = 0;
	}
}
