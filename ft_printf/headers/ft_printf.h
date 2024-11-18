#include "libft.h"
#include <stdarg.h>
#define FLAGS "#0-+ "
#define CONVS "cspdiuxX"

typedef	struct s_flags 
{
	int alt_form;
	int zero_padded;
	int	left_adjusted;
	int	space_flag;
	int	force_sign;
	int	precision;
} t_flags;
