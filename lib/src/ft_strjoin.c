/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:51:07 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 12:51:08 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char **str, char *buffer, size_t n)
{
	char	*str_join;
	size_t	str_len;
	size_t	i;	

	if (!(*str) && !buffer)
		return (NULL);
	str_len = ft_strlen(*str);
	str_join = malloc(str_len + n + 1);
	if (!str_join)
		return (NULL);
	i = 0;
	while (i < str_len)
	{
		str_join[i] = (*str)[i];
		i++;
	}
	while (i < (str_len + n) && buffer[i - str_len])
	{
		str_join[i] = buffer[i - str_len];
		i++;
	}
	str_join[i] = '\0';
	free_resources(str);
	return (str_join);
}
