/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: David RF <davidrod@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:44:19 by David RF          #+#    #+#             */
/*   Updated: 2022/06/22 00:40:53 by David RF         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define	BUFFER_SIZE		1024

//# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

void	free_resources(char **str);
char	*get_next_line(int fd);
char	*ft_strjoin(char **str, char *buffer, size_t n);

#endif