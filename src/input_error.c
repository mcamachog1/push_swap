#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "stacks.h"

int	input_error(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (argv == NULL)
		return (1);
	return (0);
}