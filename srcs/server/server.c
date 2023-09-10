/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 17:52:08 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/09/10 22:09:54 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void    recup(int c)
{
    static char i = 0;
    static int bit = 0;

    if(c == SIGUSR1)
        i |= (0x01 << bit);
    bit++;
    if(bit == 8) 
    {
        printf("%c", i);
        bit = 0;
        i = 0;
    }
}

int main()
{
    int pid;
    
    pid = getpid();
    printf("PID :%d\n", pid);
    signal(SIGUSR1, recup);
    signal(SIGUSR2, recup);
    while (1)
    {}
    return (0);
}
