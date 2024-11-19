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
	int	precision;
	int width;
	int coversion;
} t_flags;
