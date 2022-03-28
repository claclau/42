#include <stdio.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	int	d = 17;
	printf("should be : %x\n",  d);




	// give a char to %c : prints a char
	// give an int to %c : int = ascii value, prints the corresponding char. But still does something if outside ascii table
	return (0);	
}
