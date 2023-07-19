#include "ft_printf_tools.h"

# ifdef __linux__
#  define NULL_PTR_STR "(nil)"
# elif __APPLE__
#  define NULL_PTR_STR "0x0"
# endif

int	ft_puthexptr(void *ptr)
{
	int		cc;

	cc = 0;
	if (!ptr && NULL_PTR_STR)
		return (ft_putstr(NULL_PTR_STR));
	cc += ft_putstr("0x");
	cc += ft_putlonghex((unsigned long) ptr, "0123456789abcdef");
	return (cc);
}
