int main(void)
{
	int x = 12;
	if (x == 1)
	{
		x = 11;
		if (x < 0)
			x = x + 100;
		else
			x = x - 20;
		x = x + 1;
	}
	else
		x = 999;
	return (x);
}