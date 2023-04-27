/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghahn <ghahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:25:53 by ghahn             #+#    #+#             */
/*   Updated: 2022/05/28 21:25:27 by ghahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	str_len05(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len_d;

	j = 0;
	i = str_len05(dest);
	len_d = i;
	while (src[j] && i + 1 < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (len_d >= size)
		return (str_len05(src) + size);
	return (len_d + str_len05(src));
}
/*
int main(void)
{
	char a[20] = "123";
	char b[20] = "456789";
	printf("%d", ft_strlcat(a, b, 7));
}*/
