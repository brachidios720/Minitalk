/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:17:46 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/09/10 22:34:15 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_atoi(char *str)
{
	int	i;
	int	count;
	int	nb;

	i = 0;
	count = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	if (count % 2)
		return (nb);
	else
		return (-nb);
}

void	ft_send_signal(int pid, char c)
{
	int	n;
	int	i;

	n = c;
	i = 0;
	while (i < 8)
	{
		if ((n & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
		n >>= 1;
		++i;
	}
	return ;
}

int main(int argc, char **argv)
{
	int pid;
	
	if (argc != 3)
	{
		write(1, "Args error", 10);
	}
	else
	{
		pid = ft_atoi(argv[1]);

		while (*argv[2] != '\0')
			ft_send_signal(pid, *argv[2]++);
		ft_send_signal(pid, '\n');
	}
	return(0);
}