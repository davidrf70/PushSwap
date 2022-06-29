/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:50:52 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 13:39:46 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_print_str(char *str, int fd)
{
	size_t	str_len;

	if (!str)
		return (0);
	str_len = ft_strlen(str);
	write(fd, str, str_len);
	return (str_len);
}
