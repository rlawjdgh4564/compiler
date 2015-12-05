int main ()
{
	float a;
	int c;
	a = 1.0;
	c = 1;

	if (a < 0.0)
	{
		c = (c + 1) * a;
	}
	else
	{
		c = c * (a + 1);
	}

	return 0;
}
