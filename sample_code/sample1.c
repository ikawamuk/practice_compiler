
int	main() {
	int	a = 10;
	int	*b = &a;
	int	i = 0;
	while (i < 5)
	{
		a = a + i;
		i = i + 1;
	}
	return (*b);
}