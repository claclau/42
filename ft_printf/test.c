#include <limits.h>
#include <stdio.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	printf("%p\n", (void *)-1);
	ft_printf("%p\n", (void *)-1);

	printf("%p\n", (void *)18446744073709551615);
	ft_printf("%p\n", (void *)18446744073709551615);

	return (0);
}
