int main (){
	int i;
	i = 3;

	switch (i) {
		case 1:
			i = i + 2;
		case 2:
			i = i + 1000;
		case 3:
			i = i * 100;
			break;
		case 4:
			i = 10 / i;
	}

	return 0;
}
