#include <stdio.h>
#include "incl/ft_printf.h"
#include <limits.h>
#include <assert.h>




int main()
{
/* 	printf(argv[1], argv[2]);
	ft_putchar('\n');
	ft_printf(argv[1], argv[2]); */
 /*    ft_printf("%d\n", 1);
    printf("%d\n", 1); */
    int a, b;
    char *c;
    c = ft_strnew(5);
    a = ft_printf("%05d\n", -424242);
    b = printf("%05d\n", -424242);
    fflush(stdin);
    printf("a: %d\nb: %d\n", a, b);
    // fflush(stdin);
    // /* ft_printf("%-05d\n", 424242);
    // printf("%-05d\n", 424242); */
    // ft_printf("%+d\n", 9001);
    // printf("%+d\n", 9001);
    // ft_printf("%d\n", INT_MAX);
    // printf("%d\n", INT_MAX);
    // ft_printf("%ld\n", (long) INT_MAX + 1);
    // printf("%ld\n", (long) INT_MAX + 1);
    // ft_printf("%ld\n", LONG_MAX);
    // printf("%ld\n", LONG_MAX);
    // ft_printf("%d\n", -1);
    // printf("%d\n", -1);  
    // ft_printf("%d\n", -42);
    // printf("%d\n", -42);
    // ft_printf("%d\n", -9001);
    // printf("%d\n", -9001);
    // ft_printf("%d\n", INT_MIN);
    // printf("%d\n", INT_MIN);
    // ft_printf("%ld\n", (long) INT_MIN - 1);
    // printf("%ld\n", (long) INT_MIN - 1); 
    // ft_printf("%ld\n", LONG_MIN);
    // printf("%ld\n", LONG_MIN);
    // ft_printf("%i\n", 0);
    // printf("%i\n", 0);
    // ft_printf("%i\n", 1);
    // printf("%i\n", 1);
    // ft_printf("%i\n", 42);
    // printf("%i\n", 42);
    // ft_printf("%i\n", 9001);
    // printf("%i\n", 9001);
    // ft_printf("%i\n", INT_MAX);
    // printf("%i\n", INT_MAX);
    // ft_printf("%li\n", (long) INT_MAX + 1);
    // printf("%li\n", (long) INT_MAX + 1);
    // ft_printf("%li\n", LONG_MAX);
    // printf("%li\n", LONG_MAX);
    // ft_printf("%i\n", -1);
    // printf("%i\n", -1);
    // ft_printf("%i\n", -42);
    // printf("%i\n", -42);
    // ft_printf("%i\n", -9001);
    // printf("%i\n", -9001);
    // ft_printf("%i\n", INT_MIN);
    // printf("%i\n", INT_MIN);
    // ft_printf("%li\n", (long) INT_MIN - 1);
    // printf("%li\n", (long) INT_MIN - 1);
    // ft_printf("%li\n", LONG_MIN);
    // printf("%li\n", LONG_MIN);
    // ft_printf("%Lf\n",111119127890.1890L);
    // printf("\n%Lf\n",111119127890.1890L); 
    // ft_printf("\n%f",-0.8);
    // ft_printf("\n%f",0.5);
    // ft_printf("\n%f", 50.0);
    // ft_printf("\n%f",12323149.5);
    // ft_printf("%%%c%c%c%c%c%c", ' ', '4', '\13', '~', '2', '\n');
    // ft_printf("\n% s","C'est");
    // printf("\n% s","C'est");
	return(1);
}
