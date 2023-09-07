/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:17:41 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/09/07 16:35:52 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void    ft_putchar(char c)
// {
//     write(1, &c, 1);    
// }

// void    send_character(char c)
// {
//     // envoi de 8 bit en partant de la gauche
//     int i;

//     i = 0;
//     while(c <= 7)
//     {
//         putchar((c & (1 << i)) ? '1' : '0');
//         i++;
//     }
    
// }

// void    stringtobenary(const char* str)
// {
//     int i;
//     i = 0;
//     while(str[i])
//     {
//         send_character(str[i]);
//         i++;
//     }
// }


// void    transfert(char phrase)
// {
//     static  int i;
//     static  int bit;
//     while(phrase[i] != '\0')
//     {
//         send_character(phrase[i]);
//     }
// }

void    recup(int c)
{
    static int i;
    static int bit;
    if(c == SIGUSR1)
        i |=(0x01 >> bit);
    bit++;
    if(bit == 8) 
    {
        printf("%c", bit);
        bit = 0;
        i = 0;
    }
}

int main()
{
    int pid;
    
    pid = getpid();
    printf("PID :%d", pid);
    signal(SIGUSR1, recup);
    signal(SIGUSR2, recup);
    return (0);
}