#include "./includes/malloc.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*str2;

	str = ft_malloc(6);
	str = strdup("Hello\0");
	str2 = ft_malloc(6);
	str2 = strdup("there\0");
	printf("%s %s\n", str, str2);
	return 0;
}
