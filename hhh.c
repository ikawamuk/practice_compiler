main()
{
	return (fibo(6));
}

fibo(n)
{
	a = 1;
	b = 1;
	while (n - 2 > 0)
	{
		next = a + b;
		a = b;
		b = next;
		n = n - 1;
	}
	return (b);
}
