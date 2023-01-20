/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:40:38 by ghahn             #+#    #+#             */
/*   Updated: 2023/01/20 21:58:14 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_signal(int pid, char *m)
{
   int   b;
   int   i;
   int   j;

   j = -1;
   while (++j < (int)ft_strlen(m))
   {
      b = (unsigned int)m[j];
      
      i = 0;
      while (i < 8)
      {
         if (b < 128 && ft_printf("%d\n", b))
            kill(pid, SIGUSR1);
         else if (ft_printf("%d\n", b))
            kill(pid, SIGUSR2);
         b = b << 1 > 255 ? (b << 1) - 256 : b << 1;
         i++;
      }
   }
}

int main(int argc, char *argv[])
{
   if (argc != 3)
		return (ft_printf("Not 3 Parameter!!\n") && 0);
   
   send_signal(ft_atoi(argv[1]), argv[2]);
}

// 78
// 64 8 4 2

// 01001110