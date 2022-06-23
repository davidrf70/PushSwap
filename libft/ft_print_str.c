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