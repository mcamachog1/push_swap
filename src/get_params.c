#include <stdlib.h>
#include "../../push_swap/libft/libft.h"

int	*get_params(char **argv, int *size)
{
	int		i;
	int		j;
	int		*numbers;
	char	**cnumbers;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		cnumbers = ft_split(argv[i], ' ');
		while (*cnumbers != NULL)
		{
			j++;
			cnumbers++;
		}
		i++;
	}
	*size = j;
	numbers = malloc(j * sizeof(int));
	if (!numbers)
		return (NULL);
	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		cnumbers = ft_split(argv[i], ' ');
		while (*cnumbers != NULL)
		{
			numbers[j] = atoi(*cnumbers);
			cnumbers++;
			j++;
		}
		i++;
	}
	return (numbers);
}
