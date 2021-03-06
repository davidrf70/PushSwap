/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:50:46 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 13:07:20 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	hf_digit_number(int n)
{
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*hf_get_str(char *str, int n, int len)
{
	int	i;
	int	lim;
	int	digit;

	lim = 0;
	if (n < 0)
	{
		str[0] = '-';
		lim = 1;
	}
	i = len - 1;
	while (i >= lim)
	{
		digit = n % 10;
		if (n < 0)
			digit *= -1;
		str[i] = '0' + digit;
		n = n / 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = hf_digit_number(n);
	if (n < 0)
		len++;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = hf_get_str(str, n, len);
	return (str);
}
