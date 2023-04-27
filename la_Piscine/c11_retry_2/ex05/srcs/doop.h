/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 03:08:10 by ghahn             #+#    #+#             */
/*   Updated: 2022/06/07 01:06:49 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOP_H
# define DOOP_H

# include<unistd.h>

int		ft_atoi(char *s);
int		ft_add(int x, int y);
int		ft_sub(int x, int y);
int		ft_mul(int x, int y);
int		ft_div(int x, int y);
int		ft_mod(int x, int y);
void	ft_putnbr(int x);
void	ft_putchar(char x);

#endif
