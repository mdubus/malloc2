#include "./includes/malloc.h"
#include <stdio.h>

int	main(void)
{
	char	*str;
//	char	*str2;
//	char	*str3;

	str = ft_malloc(6);
//	strcpy(str, "Hello\0");
//	str2 = ft_malloc(6);
//	str2 = strdup("there\0");
//	str3 = ft_malloc(50);
//	str3 = ft_malloc(600);
//	str3 = ft_malloc(50000000);
	ft_putstr("\n----- show alloc mem : -----\n");
	show_alloc_mem();
	ft_free(str);
	ft_putstr("\n----- show alloc mem : -----\n");
	show_alloc_mem();
	return 0;
}
