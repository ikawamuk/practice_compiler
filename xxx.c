int	main()
{
	int	a = 99;
	int	*b;
	b = pointer(&a);
	return (b);
}

int	*pointer(int *x)
{
	return (x);
}
