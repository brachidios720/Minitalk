/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 12:17:41 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/09/04 17:47:37 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    putchar(char c)
{
    write(1, &c, 1);    
}

void    send_character(char c)
{
    // envoi de 8 bit en partant de la gauche
    int i;

    i = 0;
    while(c <= 7)
    {
        putchar((c & (1 << i)) ? '1' : '0');
        i++;
    }
    
}

void    stringtobenary(const char* str)
{
    int i;
    i = 0;
    while(str[i])
    {
        send_character(str[i]);
        i++;
    }
}
// void    transfert(char phrase)
// {
//     static  int i;
//     static  int bit;
//     while(phrase[i] != '\0')
//     {
//         send_character(phrase[i]);
//     }
// }

int main()
{
    int pid;
    char string;
    
    pid = getpid();
    printf("PID:%d", pid);
    string = (char *)malloc((sizeof(* string)))
    
}