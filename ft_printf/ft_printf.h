/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 14:18:16 by ghahn             #+#    #+#             */
/*   Updated: 2022/08/23 14:18:16 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

//----------srcs-----------
size_t	ft_strlen(const char *str);
char	*ft_itoa(long long n);

//----------main-----------
int		print_string(va_list lst, char x);
int		print_integer(va_list lst, char x);
int		print_hex(va_list lst, char x);
int		print_address(va_list lst);
int		ft_printf(const char *s, ...);

#endif
