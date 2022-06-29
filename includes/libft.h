/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:35:02 by David RF          #+#    #+#             */
/*   Updated: 2022/06/28 14:02:01 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define BUFFER_SIZE 1024

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_print_str(char *str, int fd);
char	*ft_strjoin(char **str, char *buffer, size_t n);
char	*ft_get_next_line(int fd);

void	free_resources(char **str);

#endif