#include "libft.h"
#include <stdarg.h>
#define FLAGS "#0-+ "
#define CONVERSIONS "cspdiuxX%"

typedef	struct s_flags 
{
	int alt_form;
	int zero_padded;
	int	left_adjusted;
	int	space_flag;
	int	force_sign;
	int	precision_value;
	int precision_flag;
	int width;
	int coversion;
	int printed;
	int total;
} t_flags;
int	ft_printf(const char *fmt, ...); //change to elipsis later
int handle_char(t_flags *f, int c);
int handle_str(char *str, t_flags *f);
int handle_ptr(unsigned long long addr, t_flags *f);
int handle_nbr(int n, t_flags *f);
int handle_hex(unsigned int x, t_flags *f, char c);
int handle_unsigned(unsigned int u, t_flags *f); 
int check_valid(const char *fmt);
int print_width(t_flags *f, int n);
int get_num_len(unsigned long long n, unsigned base);
