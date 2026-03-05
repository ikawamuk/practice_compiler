int	main()
{
	int i;
	i = 1;
	while (i <= 50)
	{
		if (collatz(i) == -1)
			return (i);
		i = i + 1;
	}
	return (0);
}

collatz(int n)
{
	return (collatz_recursive(n, 1));
}

collatz_recursive(int n, int steps)
{
	if (n <= 1)
		return (steps);
	if (steps > 100)
		return (-1);
	if (n % 2 == 0)
		n = n / 2;
	else
		n = n * 3 + 1;
	return (collatz_recursive(n, steps + 1));
}
