int	input_error(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (argv == 0)
		return (1);
	return (0);
}
