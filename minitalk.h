/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:06:40 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/09/07 17:45:18 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void    recup(int c);
// void    stringtobenary(const char* str);
// void    send_character(char c);
// void    ft_putchar(char c);
int	ft_atoi(const char *str);
void	returnsignal(int pid, char c);

#endif