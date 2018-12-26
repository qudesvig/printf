#include "includes/ft_printf.h"
#include <limits.h>
int		main(void)
{
	//printf("\nreal %d\n", printf("% "));
	printf("\n%d\n", ft_printf("str =  %.100f", 150.10));
	return (0);
}
