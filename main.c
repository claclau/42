#include <stdio.h>
#include "libft.h"

int	main(void)
{
	char s[] = "tripouille"; 
	//char s2[] = "ltripouiel"; 
	printf("s : %p\n", s);
	printf("res : %p", ft_strrchr(s, 't'));
	return (0);
}
