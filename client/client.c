/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:17:46 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/09/07 17:44:29 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
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

void	returnsignal(int pid, char c)
{
	int	i;
	int s;
	
	i = 7;
	while( i >= 0)
	{
		s = (c & (1 << i));
		if(s == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(120);
		i--;
	}
}

int main(int argc, char **argv)
{
	int pid;
	char *str;
	
    pid = atoi(argv[1]);
	str = argv[2];
	while(argv[2] != '\0')
	{
		returnsignal(pid, *str++);
	}
	return(0);
}