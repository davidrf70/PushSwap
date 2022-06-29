/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:51:14 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 12:51:15 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

/*
* The strlen() function calculates the length of the string s, 
* excluding the terminating null byte ('\0')
*/
size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
