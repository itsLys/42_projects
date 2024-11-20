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
int handle_char(int c, t_flags *f);
int handle_str(char *str, t_flags *f);
int handle_ptr(unsigned long long addr, t_flags *f);
int print_nbr(int n, t_flags *f);
int print_hex(unsigned int n, t_flags *f, char c);
int check_valid(const char *fmt);
int print_width(t_flags *f, int n);
int putnstr(t_flags *f, char *str, int n);
int handle_precision(t_flags *f, char *str);
int	handle_null(t_flags *f, char *str);
int check_valid(const char *fmt);
int get_num_len(unsigned long long n, int base);
