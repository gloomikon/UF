#include "./includes/header.h"
//------------------------------------
#define	TEST "%3%\n"
#define	TEST1 "%03%\n"
#define	TEST2 "%*%\n", 3
#define TEST4 "%07.4d\n", 69
//------------------------------------
int main()
{
	// ft_printf(TEST);
	//    printf(TEST);

	// ft_printf(TEST1);
	//    printf(TEST1);

	// ft_printf(TEST2);
	//    printf(TEST2);

	ft_printf(TEST4);
	   printf(TEST4);

}