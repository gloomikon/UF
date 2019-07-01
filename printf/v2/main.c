#include "./includes/header.h"
//------------------------------------
void test_42(void)
{
   	    // ft_printf("%d\n", 2147483648);                  //-> "-2147483648"
   	    //    printf("%d\n", 2147483648);
    	// ft_printf("%d\n", -2147483648);                 //-> "-2147483648"
    	//    printf("%d\n", -2147483648);
    	// ft_printf("%d\n", -2147483649);                 //-> "2147483647"
    	//    printf("%d\n", -2147483649);
    	// ft_printf("% d\n", 42);                         //-> " 42"
    	//    printf("% d\n", 42);
    	// ft_printf("% d\n", -42);                        //-> "-42"
    	//    printf("% d\n", -42);
    	// ft_printf("%+d\n", 42);                         //-> "+42"
    	//    printf("%+d\n", 42);
    	// ft_printf("%+d\n", -42);                        //-> "-42"
    	//    printf("%+d\n", -42);
    	// ft_printf("%+d\n", 0);                          //-> "+0"
    	//    printf("%+d\n", 0);
    	// // ft_printf("%+d\n", 4242424242424242424242);     //-> "-1"
    	//    // printf("%+d\n", 4242424242424242424242);
    	// ft_printf("% +d\n", 42);                        //-> "+42"
    	//    printf("% +d\n", 42);
    	// ft_printf("% +d\n", -42);                       //-> "-42"
    	//    printf("% +d\n", -42);
    	// ft_printf("%+ d\n", 42);                        //-> "+42"
    	//    printf("%+ d\n", 42);
    	// ft_printf("%+ d\n", -42);                       //-> "-42"
    	//    printf("%+ d\n", -42);
    	// ft_printf("%  +d\n", 42);                       //-> "+42"
    	//    printf("%  +d\n", 42); 
    	// ft_printf("%  +d\n", -42);                      //-> "-42"
    	//    printf("%  +d\n", -42);
    	// ft_printf("%+  d\n", 42);                       //-> "+42"
    	//    printf("%+  d\n", 42);
    	// ft_printf("%+  d\n", -42);                      //-> "-42"
    	//    printf("%+  d\n", -42);
    	// ft_printf("% ++d\n", 42);                       //-> "+42"
    	//    printf("% ++d\n", 42);
    	// ft_printf("% ++d\n", -42);                      //-> "-42"
    	//    printf("% ++d\n", -42);
    	// ft_printf("%++ d\n", 42);                       //-> "+42"
    	//    printf("%++ d\n", 42);
    	// ft_printf("%++ d\n", -42);                      //-> "-42"
    	//    printf("%++ d\n", -42);
    	// ft_printf("%0d\n", -42);                        //-> "-42"
    	//    printf("%0d\n", -42);
    	// ft_printf("%00d\n", -42);                       //-> "-42"
    	//    printf("%00d\n", -42);
    	// ft_printf("%5d\n", 42);                         //-> "   42"
    	//    printf("%5d\n", 42);
    	// ft_printf("%05d\n", 42);                        //-> "00042"
    	//    printf("%05d\n", 42);
    	// ft_printf("%0+5d\n", 42);                       //-> "+0042"
    	//    printf("%0+5d\n", 42); 
    	// ft_printf("%5d\n", -42);                        //-> "  -42"
    	//    printf("%5d\n", -42); 
    	// ft_printf("%05d\n", -42);                       //-> "-0042"
    	//    printf("%05d\n", -42);
    	// ft_printf("%0+5d\n", -42);                      //-> "-0042"
    	//    printf("%0+5d\n", -42); 
    	// ft_printf("%-5d\n", 42);                        //-> "42   "
    	//    printf("%-5d\n", 42); 
    	// ft_printf("%-05d\n", 42);                       //-> "42   "
    	//    printf("%-05d\n", 42);
    	// ft_printf("%-5d\n", -42);                       //-> "-42  "
    	//    printf("%-5d\n", -42); 
    	// ft_printf("%-05d\n", -42);                      //-> "-42  "
    	//    printf("%-05d\n", -42);
	    // ft_printf("%hd\n", 32767);                        //-> "32767"
	    //    printf("%hd\n", 32767);


        // ft_printf("%hd\n", −32768);                       //-> "0"
        //    printf("%hd\n", −32768);


        // ft_printf("%hd\n", 32768);                        //-> "-32768" 
        //    printf("%hd\n", 32768);


        // ft_printf("%hd\n", −32769);                       //-> "0"
        //    printf("%hd\n", −32769);


        // ft_printf("%hhd\n", 127);                         //-> "127"
        //    printf("%hhd\n", 127);
        // ft_printf("%hhd\n", 128);                         //-> "-128" 
        //    printf("%hhd\n", 128);
        // ft_printf("%hhd\n", -128);                        //-> "-128"
        //    printf("%hhd\n", -128);
        // ft_printf("%hhd\n", -129);                        //-> "127"   
        //    printf("%hhd\n", -129);
        // ft_printf("%ld\n", 2147483647);                   //-> "2147483647"
        //    printf("%ld\n", 2147483647);
        // ft_printf("%ld\n", -2147483648);                  //-> "-2147483648"
        //    printf("%ld\n", -2147483648);
        // ft_printf("%ld\n", 2147483648);                   //-> "2147483648"
        //    printf("%ld\n", 2147483648);
        // ft_printf("%ld\n", -2147483649);                  //-> "-2147483649"
        //    printf("%ld\n", -2147483649);
        // ft_printf("%lld\n", 9223372036854775807);         //-> "9223372036854775807"
        //    printf("%lld\n", 9223372036854775807);
        // ft_printf("%lld\n", -9223372036854775808);        //-> "-9223372036854775808"
        //    printf("%lld\n", -9223372036854775808);
        // ft_printf("%jd\n", 9223372036854775807);          //-> "9223372036854775807"
        //    printf("%jd\n", 9223372036854775807);
        // ft_printf("%jd\n", -9223372036854775808);         //-> "-9223372036854775808"
        //    printf("%jd\n", -9223372036854775808);



        // ft_printf("%zd\n", 4294967295);                   //-> "4294967295"
        //    printf("%zd\n", 4294967295);
        // ft_printf("%zd\n", 4294967296);                   //-> "4294967296"
        //    printf("%zd\n", 4294967296);
        // ft_printf("%zd\n", -0);                           //-> "0"
        //    printf("%zd\n", -0);
        // ft_printf("%zd\n", -1);                           //-> "4294967295"
        //    printf("%zd\n", -1);

		
        // ft_printf("%d\n", 1);                             //-> "1"
        //    printf("%d\n", 1);
        // ft_printf("%d %d\n", 1, -2);                      //-> "1 -2"
        //    printf("%d %d\n", 1, -2);
        // ft_printf("%d %d %d\n", 1, -2, 33);               //-> "1 -2 33"
        //    printf("%d %d %d\n", 1, -2, 33);
        // ft_printf("%d %d %d %d\n", 1, -2, 33, 42);        //-> "1 -2 33 42"
        //    printf("%d %d %d %d\n", 1, -2, 33, 42);
        // ft_printf("%d %d %d %d gg!\n", 1, -2, 33, 42, 0); //-> "1 -2 33 42 gg!"
        //    printf("%d %d %d %d gg!\n", 1, -2, 33, 42, 0);
        // ft_printf("%4.15d\n", 42);                        //-> "000000000000042"
        //    printf("%4.15d\n", 42);
        // ft_printf("%.2d\n", 4242);                        //-> "4242"
        //    printf("%.2d\n", 4242); 
        // ft_printf("%.10d\n", 4242);                       //-> "0000004242"
        //    printf("%.10d\n", 4242);
        // ft_printf("%10.5d\n", 4242);                      //-> "     04242"
        //    printf("%10.5d\n", 4242);
        // ft_printf("%-10.5d\n", 4242);                     //-> "04242     "
        //    printf("%-10.5d\n", 4242);
        // ft_printf("% 10.5d\n", 4242);                     //-> "     04242"
        //    printf("% 10.5d\n", 4242);
        // ft_printf("%+10.5d\n", 4242);                     //-> "    +04242"
        //    printf("%+10.5d\n", 4242);
        // ft_printf("%-+10.5d\n", 4242);                    //-> "+04242    "
        //    printf("%-+10.5d\n", 4242); 
        // ft_printf("%03.2d\n", 0);                         //-> " 00"
        //    printf("%03.2d\n", 0);
        // ft_printf("%03.2d\n", 1);                         //-> " 01"
        //    printf("%03.2d\n", 1);
        // ft_printf("%03.2d\n", -1);                        //-> "-01"
        //    printf("%03.2d\n", -1);
        // ft_printf("@moulitest: %.10d\n", -42);            //-> "@moulitest: -0000000042"
        //    printf("@moulitest: %.10d\n", -42);
        // ft_printf("@moulitest: %.d %.0d\n", 42, 43);      //-> "@moulitest: 42 43"
        //    printf("@moulitest: %.d %.0d\n", 42, 43);
        // ft_printf("@moulitest: %.d %.0d\n", 0, 0);        //-> "@moulitest:  "
        //    printf("@moulitest: %.d %.0d\n", 0, 0);
        // ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);      //-> "@moulitest:            "
        //    printf("@moulitest: %5.d %5.0d\n", 0, 0);
}

void test_x_s_o(void)
{
	// ft_printf("");                                                               //-> ""
	//    printf("");
	// ft_printf("\n");                                                             //-> "$\n"
	//    printf("\n");
	// ft_printf("test\n");                                                           //-> "test\n"
	//    printf("test\n");
	// ft_printf("test\n");                                                         //-> "test$\n"
	//    printf("test\n");
	// ft_printf("1234\n");                                                           //-> "1234"\n
	//    printf("1234\n");
	// ft_printf("%%\n");                                                             //-> "%"
	//    printf("%%\n");


	// ft_printf("%5%\n");                                                            //-> "    %"
	//    printf("%5%\n");
	
	// ft_printf("%-5%\n");                                                           //-> "%    "
	//    printf("%-5%\n");
	// ft_printf("%.0%\n");                                                           //-> "%"
	//    printf("%.0%\n");
	// ft_printf("%%\n", "test");                                                     //-> "%"
	//    printf("%%\n", "test");
	// ft_printf("%   %\n", "test");                                                  //-> "%"
	//    printf("%   %\n", "test");



	// ft_printf("%x\n", 42);                                                         //-> "2a"
	//    printf("%x\n", 42);
	// ft_printf("%X\n", 42);                                                         //-> "2A"
	//    printf("%X\n", 42);
	// ft_printf("%x\n", 0);                                                          //-> "0"
	//    printf("%x\n", 0);
	// ft_printf("%X\n", 0);                                                          //-> "0"
	//    printf("%X\n", 0);
	// ft_printf("%x\n", -42);                                                        //-> "ffffffd6"
	//    printf("%x\n", -42);
	// ft_printf("%X\n", -42);                                                        //-> "FFFFFFD6"
	//    printf("%X\n", -42);
	// ft_printf("%x\n", 4294967296);                                                 //-> "0"
	//    printf("%x\n", 4294967296);
	// ft_printf("%X\n", 4294967296);                                                 //-> "0"
	//    printf("%X\n", 4294967296);
	// ft_printf("%10x\n", 42);                                                       //-> "        2a"
	//    printf("%10x\n", 42);
	// ft_printf("%-10x\n", 42);                                                      //-> "2a        "
	//    printf("%-10x\n", 42);
	// ft_printf("%lx\n", 4294967296);                                                //-> "100000000"
	//    printf("%lx\n", 4294967296);
	// ft_printf("%llX\n", 4294967296);                                               //-> "100000000"
	//    printf("%llX\n", 4294967296);
	// ft_printf("%hx\n", 4294967296);                                                //-> "0"
	//    printf("%hx\n", 4294967296);
	// ft_printf("%hhX\n", 4294967296);                                               //-> "0"
	//    printf("%hhX\n", 4294967296);
	// ft_printf("%jx\n", 4294967295);                                                //-> "ffffffff"
	//    printf("%jx\n", 4294967295);
	// ft_printf("%jx\n", 4294967296);                                                //-> "100000000"
	//    printf("%jx\n", 4294967296);
	// ft_printf("%jx\n", -4294967296);                                               //-> "ffffffff00000000"
	//    printf("%jx\n", -4294967296);
	// ft_printf("%jx\n", -4294967297);                                               //-> "fffffffeffffffff"
	//    printf("%jx\n", -4294967297);
	// ft_printf("%llx\n", 9223372036854775807);                                      //-> "7fffffffffffffff"
	//    printf("%llx\n", 9223372036854775807);
	// ft_printf("%llx\n", 9223372036854775808);                                      //-> "7fffffffffffffff"
	//    printf("%llx\n", 9223372036854775808);
	// ft_printf("%010x\n", 542);                                                     //-> "000000021e"
	//    printf("%010x\n", 542);
	// ft_printf("%-15x\n", 542);                                                     //-> "21e            "
	//    printf("%-15x\n", 542);
	// ft_printf("%2x\n", 542);                                                       //-> "21e"
	//    printf("%2x\n", 542);
	// ft_printf("%.2x\n", 5427);                                                     //-> "1533"
	//    printf("%.2x\n", 5427);
	// ft_printf("%5.2x\n", 5427);                                                    //-> " 1533"
	//    printf("%5.2x\n", 5427);
	// ft_printf("%#x\n", 42);                                                        //-> "0x2a"
	//    printf("%#x\n", 42);
	// ft_printf("%#llx\n", 9223372036854775807);                                     //-> "0x7fffffffffffffff"
	//    printf("%#llx\n", 9223372036854775807); 
	// ft_printf("%#x\n", 0);                                                         //-> "0"
	//    printf("%#x\n", 0);
	// ft_printf("%#x\n", 42);                                                        //-> "0x2a"
	//    printf("%#x\n", 42);
	// ft_printf("%#X\n", 42);                                                        //-> "0X2A"
	//    printf("%#X\n", 42);
	// ft_printf("%#8x\n", 42);                                                       //-> "    0x2a"
	//    printf("%#8x\n", 42);
	// ft_printf("%#08x\n", 42);                                                      //-> "0x00002a"
	//    printf("%#08x\n", 42);
	// ft_printf("%#-08x\n", 42);                                                     //-> "0x2a    "
	//    printf("%#-08x\n", 42);
	// ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);                                   //-> "@moulitest:  "
	//    printf("@moulitest: %#.x %#.0x\n", 0, 0);
	// ft_printf("@moulitest: %.x %.0x\n", 0, 0);                                     //-> "@moulitest:  "
	//    printf("@moulitest: %.x %.0x\n", 0, 0);
	// ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);                                   //-> "@moulitest:            "
	//    printf("@moulitest: %5.x %5.0x\n", 0, 0);



	// ft_printf("%s\n", "abc");                                                      //-> "abc"
	//    printf("%s\n", "abc");
	// ft_printf("%s\n", "this is a string");                                         //-> "this is a string"
	//    printf("%s\n", "this is a string");
	// ft_printf("%s\n", "this is a string");                                        //-> "this is a string "
	//    printf("%s\n", "this is a string");
	// ft_printf("%s  \n", "this is a string");                                       //-> "this is a string  "
	//    printf("%s  \n", "this is a string");
	// ft_printf("this is a %s\n", "string");                                         //-> "this is a string"
	//    printf("this is a %s\n", "string");
	// ft_printf("%s is a string\n", "this");                                         //-> "this is a string"
	//    printf("%s is a string\n", "this");
	// ft_printf("Line Feed %s\n", "\n");                                             //-> "Line Feed $\n"
	//    printf("Line Feed %s\n", "\n");
	// ft_printf("%10s is a string\n", "this");                                       //-> "      this is a string"
	//    printf("%10s is a string\n", "this");
	// ft_printf("%.2s is a string\n", "this");                                       //-> "th is a string"
	//    printf("%.2s is a string\n", "this");
	// ft_printf("%5.2s is a string\n", "this");                                      //-> "   th is a string"
	//    printf("%5.2s is a string\n", "this");
	// ft_printf("%10s is a string\n", "");                                           //-> "           is a string"
	//    printf("%10s is a string\n", "");
	// ft_printf("%.2s is a string\n", "");                                           //-> " is a string"
	//    printf("%.2s is a string\n", "");
	// ft_printf("%5.2s is a string\n", "");                                          //-> "      is a string"
	//    printf("%5.2s is a string\n", "");
	// ft_printf("%-10s is a string\n", "this");                                      //-> "this       is a string"
	//    printf("%-10s is a string\n", "this");


	// ft_printf("%-.2s is a string\n", "this");                                      //-> "th is a string"
	//    printf("%-.2s is a string\n", "this");


	// ft_printf("%-5.2s is a string\n", "this");                                     //-> "th    is a string"
	//    printf("%-5.2s is a string\n", "this");
	// ft_printf("%-10s is a string\n", "");                                          //-> "           is a string"
	//    printf("%-10s is a string\n", "");
	// ft_printf("%-.2s is a string\n", "");                                          //-> " is a string"
	//    printf("%-.2s is a string\n", "");
	// ft_printf("%-5.2s is a string\n", "");                                         //-> "      is a string"
	//    printf("%-5.2s is a string\n", "");
	// ft_printf("%s %s\n", "this", "is");                                            //-> "this is"
	//    printf("%s %s\n", "this", "is");
	// ft_printf("%s %s %s\n", "this", "is", "a");                                    //-> "this is a"
	//    printf("%s %s %s\n", "this", "is", "a");
	// ft_printf("%s %s %s %s\n", "this", "is", "a", "multi");                        //-> "this is a multi"
	//    printf("%s %s %s %s\n", "this", "is", "a", "multi"); 
	// ft_printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string");  //-> "this is a multi string. gg!"
	//    printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string");
	// ft_printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");               //-> "thisisamultistring"
	//    printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");
	// ft_printf("@moulitest: %s\n", NULL);                                           //-> "@moulitest: (null)"
	//    printf("@moulitest: %s\n", NULL);
	// ft_printf("%.2c\n", NULL);                                                     //-> "^@"
	//    printf("%.2c\n", NULL);
	// ft_printf("%c\n", 42);                                                         //-> "*"
	//    printf("%c\n", 42);
	// ft_printf("%5c\n", 42);                                                        //-> "    *"
	//    printf("%5c\n", 42);
	// ft_printf("%-5c\n", 42);                                                       //-> "*    "
	//    printf("%-5c\n", 42);
	// ft_printf("@moulitest: %c\n", 0);                                              //-> "@moulitest: ^@"
	//    printf("@moulitest: %c\n", 0);
	// ft_printf("%2c\n", 0);                                                         //-> " ^@"
	//    printf("%2c\n", 0);
	// ft_printf("null %c and text\n", 0);                                            //-> "null ^@ and text"
	//    printf("null %c and text\n", 0); 
	// ft_printf("% c\n", 0);                                                         //-> "^@"
	//    printf("% c\n", 0);



	// ft_printf("%o\n", 40);                                                         //-> "50"
	//    printf("%o\n", 40);
	// ft_printf("%5o\n", 41);                                                        //-> "   51"
	//    printf("%5o\n", 41);
	// ft_printf("%05o\n", 42);                                                       //-> "00052"
	//    printf("%05o\n", 42);
	// ft_printf("%-5o\n", 2500);                                                     //-> "4704 "
	//    printf("%-5o\n", 2500);
	// ft_printf("%#6o\n", 2500);                                                     //-> " 04704"
	//    printf("%#6o\n", 2500);
	// ft_printf("%-#6o\n", 2500);                                                    //-> "04704 "
	//    printf("%-#6o\n", 2500);
	// ft_printf("%-05o\n", 2500);                                                    //-> "4704 "
	//    printf("%-05o\n", 2500);
	// ft_printf("%-5.10o\n", 2500);                                                  //-> "0000004704"
	//    printf("%-5.10o\n", 2500);
	// ft_printf("%-10.5o\n", 2500);                                                  //-> "04704     "
	//    printf("%-10.5o\n", 2500);
	// ft_printf("@moulitest: %o\n", 0);                                              //-> "@moulitest: 0"
	//    printf("@moulitest: %o\n", 0);
	// ft_printf("@moulitest: %.o %.0o\n", 0, 0);                                     //-> "@moulitest:  "
	//    printf("@moulitest: %.o %.0o\n", 0, 0);
	// ft_printf("@moulitest: %5.o %5.0o\n", 0, 0);                                   //-> "@moulitest:            "
	//    printf("@moulitest: %5.o %5.0o\n", 0, 0);
	// ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);                                   //-> "@moulitest: 0 0"
	//    printf("@moulitest: %#.o %#.0o\n", 0, 0);
	// ft_printf("@moulitest: %.10o\n", 42);                                          //-> "@moulitest: 0000000052"
	//    printf("@moulitest: %.10o\n", 42);
}

void my_tests()
{
	// ft_printf("%k\n", 4294967295);
	//    printf("%k\n", 4294967295);
	// ft_printf("%hU\n", 4294967295);
	//    printf("%hU\n", 4294967295);
	// ft_printf("%U\n", 4294967296);
	//    printf("%U\n", 4294967296);
	// char *str1 = "narrow";
    // char *str2 = L"wide";
	// wchar_t qq = L'\u2604';

    //    printf("1 %s \n", str1);
	// ft_printf("2 %s \n", str1);

    //    printf("3 %ls \n", str2);
	// ft_printf("4 %ls \n", str2);

	// ft_printf("%lc\n", qq);

	//    printf("%10.3.4.5.6.7d\n", 123);
	// ft_printf("%10.3.4.5.6.7d\n", 123);


	//    printf("%zd\n", -1L);
	// ft_printf("%zd\n", -1L);

	// ft_printf("%zd\n", 4294967295);  
	//    printf("%zd\n", 4294967295);  
	// ft_printf("%zd\n", 4294967296); 
	//    printf("%zd\n", 4294967296); 
	// ft_printf("%lu\n", -42);
	//    printf("%lu\n", -42);

	// ft_printf("%hho, %hho\n", 0, USHRT_MAX);
    //    printf("%hho, %hho\n", 0, USHRT_MAX);
	
	// ft_printf("%hhx, %hhx\n", 0, UCHAR_MAX + 42);
 	//    printf("%hhx, %hhx\n", 0, UCHAR_MAX + 42);

	// ft_printf("Value %#2.0e \n", 1201.0);
	//    printf("Value %#2.0e \n", 1201.0);
	
	// ft_printf("%5.2f\n", 12.32453);
	//    printf("%5.2f\n", 12.32453);

	// ft_printf("%5.0f\n", 12.32453);
	//    printf("%5.0f\n", 12.32453);

	// ft_printf("%#5.0f\n", 12.32453);
	//    printf("%#5.0f\n", 12.32453);

	
	// ft_printf("%Li\n", 42);
	//    printf("%Li\n", 42);

	// ft_printf("%hd\n", 100000);
	//    printf("%hd\n", 100000);
	// ft_printf("%zd\n", 100000);
	//    printf("%zd\n", 100000);

	// ft_printf("%hzdd  .%%\n", 100000);
	//    printf("%hzdd  .%%\n", 100000);

	// ft_printf("%.16g\n", 3122.55); 
	//    printf("%.16g\n", 3122.55); 
	// ft_printf("%.17g\n", 3122.55); 				//false
	//    printf("%.17g\n", 3122.55); 				//false

	// int *p = (int*)malloc(sizeof(int));

	// ft_printf("%-32s\n", NULL);
    //    printf("%-32s\n", NULL);
	   
	// ft_printf("%-10p\n", 0);
	//    printf("%-10p\n", 0);

	// ft_printf("%lhl\n", 9223372036854775807);
	//    printf("%lhl\n", 9223372036854775807);
	// ft_printf("%lhlz\n", 9223372036854775807);
	//    printf("%lhlz\n", 9223372036854775807);

	// ft_printf("%");
	//    printf("%");

	int i1 = ft_printf("{%f}{%lf}\n", 1.42, 1.42l);
	int i2 =    printf("{%f}{%lf}\n", 1.42, 1.42l);
	printf("%d %d", i1, i2);

}

void failed_tests()
{
	// ft_printf("%hhX\n", 4294967296);
	//    printf("%hhX\n", 4294967296);

	// ft_printf("%zd\n", -1);
	//    printf("%zd\n", -1);
	
	// int i1 = ft_printf("%llq\n", 33);
	// int i2 =   printf("%llq\n", 33);
	// printf("%d %d", i1, i2);

	// ft_printf("%\n");
	//    printf("%\n");                               						//-> ""
	// ft_printf("% \n");
	//    printf("% \n");                              						//-> ""
	// ft_printf("% h\n");
	//    printf("% h\n");                             						//-> ""


	// ft_printf("%Z\n");
	//    printf("%Z\n");                              						//-> ""
	// ft_printf("% hZ\n");
	//    printf("% hZ\n");                            						//-> "% Z"
	// ft_printf("%05%\n");
	//    printf("%05%\n");                            						//-> "%"
	// ft_printf("%-05%\n");
	//    printf("%-05%\n");                           						//-> "%"
	// ft_printf("% hZ%\n");
	//    printf("% hZ%\n");                           						//-> "% Z%"
	// ft_printf("% Z\n", "test");
	//    printf("% Z\n", "test");                     						//-> ""
	// ft_printf("% Z \n", "test");
	//    printf("% Z \n", "test");                    						//-> "%  "
	// ft_printf("% Z%s\n", "test");
	//    printf("% Z%s\n", "test");                   						//-> "%s"
	// ft_printf("%000   %\n", "test");
	//    printf("%000   %\n", "test");                						//-> "%"
	// ft_printf("%%%\n", "test");
	//    printf("%%%\n", "test");                     						//-> "%"
	// ft_printf("%%   %\n", "test");
	//    printf("%%   %\n", "test");                  						//-> "%   "
	// ft_printf("%ll#x\n", 9223372036854775807);
	//    printf("%ll#x\n", 9223372036854775807);      						//-> "%#x"
	// ft_printf("%010s is a string\n", "this");
	//    printf("%010s is a string\n", "this");       						//-> "      this is a string"
	// ft_printf("%-010s is a string\n", "this");
	//    printf("%-010s is a string\n", "this");      						//-> "this       is a string"
	// ft_printf("%05c\n", 42);
	//    printf("%05c\n", 42);                        						//-> "    *"
	// ft_printf("% Z\n", 42);
	//    printf("% Z\n", 42);                         						//-> ""
	// ft_printf("%0 d\n", 42);
	//    printf("%0 d\n", 42);                        						//-> " 42"
	// ft_printf("%0 d\n", -42);
	//    printf("%0 d\n", -42);                       						//-> "-42"
	// ft_printf("% 0d\n", 42);
	//    printf("% 0d\n", 42);                        						//-> " 42"
	// ft_printf("% 0d\n", -42);
	//    printf("% 0d\n", -42);                       						//-> "-42"
	// ft_printf("%5+d\n", 42);
	//    printf("%5+d\n", 42);                        						//-> "%5+d"
	// ft_printf("%5+d\n", -42);
	//    printf("%5+d\n", -42);                       						//-> "%5+d"
	// ft_printf("%-5+d\n", 42);
	//    printf("%-5+d\n", 42);                       						//-> "%-5+d"
	// ft_printf("%-0+5d\n", 42);
	//    printf("%-0+5d\n", 42);                      						//-> "+42  "
	// ft_printf("%-5+d\n", -42);
	//    printf("%-5+d\n", -42);                      						//-> "%-5+d"
	// ft_printf("%-0+5d\n", -42);
	//    printf("%-0+5d\n", -42);                     						//-> "-42  "
	// ft_printf("%zhd\n", 4294967296);
	//    printf("%zhd\n", 4294967296);                						//-> "%hd"
	// ft_printf("%jzd\n", 9223372036854775807);
	//    printf("%jzd\n", 9223372036854775807);       						//-> "%zd"
	// ft_printf("%jhd\n", 9223372036854775807);
	//    printf("%jhd\n", 9223372036854775807);       						//-> "%hd"
	// ft_printf("%lhl\n", 9223372036854775807);
	//    printf("%lhl\n", 9223372036854775807);       						//-> "%hl"
	// ft_printf("%lhlz\n", 9223372036854775807);
	//    printf("%lhlz\n", 9223372036854775807);      						//-> "%hlz"
	// ft_printf("%zj\n", 9223372036854775807);
	//    printf("%zj\n", 9223372036854775807);        						//-> "%j"
	// ft_printf("%lhh\n", 2147483647);
	//    printf("%lhh\n", 2147483647);                						//-> "%hh"
	// ft_printf("%hhld\n", 128);
	//    printf("%hhld\n", 128);                      						//-> "%ld"
	// ft_printf("@main_ftprintf: %####0000 33..1..#00d\\n\n", 256);
	//    printf("@main_ftprintf: %####0000 33..1..#00d\\n\n", 256);			//-> "@main_ftprintf: %# 033.0.1..#00d\\n"
	// ft_printf("@main_ftprintf: %####0000 33..1d\n", 256);
	//    printf("@main_ftprintf: %####0000 33..1d\n", 256);					//-> "@main_ftprintf: %# 033.0.1d"
	// ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d\n", 256);
	//    printf("@main_ftprintf: %###-#0000 33...12..#0+0d\n", 256); 			//->"@main_ftprintf: %# -33.0..12..#0+0d"
}
int main()
{
	// test_42();

	// test_x_s_o();

	my_tests();

	//failed_tests();

	return 0;
}