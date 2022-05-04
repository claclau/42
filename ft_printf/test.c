#include <limits.h>
#include <stdio.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	printf("%p\n", (void *)-1);
	ft_printf("%p\n", (void *)-1);

	printf("%p\n", (void *)18446744073709551615);
	ft_printf("%p\n", (void *)18446744073709551615);

	ft_printf("%s\n", "pls");
	ft_printf("%d\n", 42);
	ft_printf("%u\n", 42);
	ft_printf("%x\n", 42);

	return (0);
}
