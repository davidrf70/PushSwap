/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:50:21 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 12:50:21 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	hf_skip_spaces(const char *nptr)
{
	size_t	i;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\f' || nptr[i] == '\n'
		|| nptr[i] == '\r' || nptr[i] == '\t' || nptr[i] == '\v')
		i++;
	return (i);
}

static int	hf_get_sign(const char *nptr, size_t *i)
{
	if (nptr[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	else if (nptr[*i] == '+')
	{
		(*i)++;
		return (1);
	}
	return (1);
}

static int	hf_get_mod(const char *nptr, size_t i)
{
	int	mod;

	mod = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		mod = 10 * mod + nptr[i] - '0';
		i++;
	}
	return (mod);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		mod;

	i = hf_skip_spaces(nptr);
	sign = 1;
	sign = hf_get_sign(nptr, &i);
	if (nptr[i] == '-' || nptr[i] == '+')
		return (0);
	mod = hf_get_mod(nptr, i);
	if (sign > 0 && mod < 0)
		return (-1);
	else if (sign < 0 && mod < 0 && mod != INT_MIN)
		return (0);
	else if (mod == INT_MIN)
		return (mod);
	return (sign * mod);
}
