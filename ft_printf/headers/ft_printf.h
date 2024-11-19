#include "libft.h"
#include <stdarg.h>
#define FLAGS "#0-+ "
#define CONVERSIONS "cspdiuxX"

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
} t_flags;
int print_char(int c, t_flags *f);
int print_str(char *str, t_flags *f);
int print_ptr(unsigned long long addr, t_flags *f);
int print_nbr(int n, t_flags *f);
int print_hex(unsigned int n, t_flags *f, char c);
int check_valid(const char *fmt);
int print_width(t_flags *f, int c);
