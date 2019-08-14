#include "./includes/malloc.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*str2;
	char	*str3;

	str = ft_malloc(6);
	str = strdup("Hello\0");
	str2 = ft_malloc(6);
	str2 = strdup("there\0");
	str3 = ft_malloc(50);
	printf("%s %s\n", str, str2);
	show_alloc_mem();
	return 0;
}
