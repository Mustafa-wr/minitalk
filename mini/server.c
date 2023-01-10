/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mradwan <mradwan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:48:14 by mradwan           #+#    #+#             */
/*   Updated: 2022/10/20 14:33:48 by mradwan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, recieve_sig);
	signal(SIGUSR2, recieve_sig);
	while (1)
		pause();
}
