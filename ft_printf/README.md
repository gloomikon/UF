# ft_printf
By now, you must be fed up alternating the `ft_putstr` and `ft_putnbr`  
functions when doing your printing. Are you not allowed to use `printf`? You can recode  
yours! It will be a chance for you to discover a feature of the C language – variadic  
functions – and to practice detailed management of the printing options. You will then  
be allowed to use your `ft_printf` in all your future projects.  
  
## Usage:
`ft_printf("%[flags][width][.precision][length]specifier, ...);`  
For multifile descriptor use:  
`ft_dprintf(fd, "%[flags][width][.precision][length]specifier, ...);`  
You can also use `%b` for binary output.  
Or colors like this:  
`ft_printf("{red}Hello World!{off}");`  
Available colors:
* `{red}`
* `{yellow}`
* `{blue}`
* `{white}`
* `{black}`
* `{cyan}`
* `{magenta}`
* `{green}`
