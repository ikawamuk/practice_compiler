main()
{
	putchar(65);
	putchar(10);
}

putchar(c)
{
	syscall(1, 1, &c, 1);
}
