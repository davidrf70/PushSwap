#ifndef	LIBFT_H
# define LIBFT_H

# include	<stddef.h>
# include	<stdlib.h>
# include	<unistd.h>
# include	<limits.h>

int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_print_str(char *str, int fd);

#endif