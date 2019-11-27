#include <stdio.h>
#include "ft_printf.h"

int main()
{
	printf("%05s\n",NULL);
	ft_printf("%05s",NULL);
	return(1);
}