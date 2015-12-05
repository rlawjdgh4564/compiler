int a () {
	return 1+2*3;
}

int main () {
	while (i == 1) {
		{
			x = 2;
			y = 3;
			x = x + 1;
			a ();
		}
		x = 2;
		for (i = 0; i < 10; i = i + 1) {
			if (j == 0) {
				x = 2;
				{
					j = x + 1;
					while (x == 1) {
						x = x + 3;
					}
					{
						j = x + 2;
					}
				}
			}
			{
				switch (x) {
					case 2:
						x = 2;
						break;
					case 4:
						x = 3;
					case 5:
						y = 3;
						break;
					default:
						x = 3;
						break;
				}
			}
		}
	}
}
