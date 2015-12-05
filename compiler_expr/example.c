
int val1, val2[10];			
int val3, val4;
int val5[10], val6[10];			
float val7, val8;
float val9, val10[10];
float val11[10], val12[10];



int Val_Decl1 () {
	int val1, val2[10];			
	int val3, val4;
	int val5[10], val6[10];			
	float val7, val8;
	float val9, val10[10];
	float val11[10], val12[10];
	val1 = 10;
	return val1;
}


float Func_Decl1 (int a, int b, int c[10], float d) {
	return d;
}
int Func_Decl2 (float a, int b, float c[11], int d[10]) {
	return b;
}
float Func_Decl3 () {
	float a;
	a = 10;
	return a;
}



int Iterative_STMT(){
	int a, b;
	int index;
	index = 100;

	while(a == b){					
		a = b;
	}

	do {						
		a = b;
		a = a/b;
	} while(a < b);

	for(a=0; a<b; a=a+1){				
		a = a+2;
	}
	

	while(a==b){					
		a = b;
		for(a=0; a<10; a=a+1){
			b = a;
			for(c=0;c<10;c=c+1){
				d = a;
			}
			while(val1 == 10){
				val1=1;
				if(val1 == 1)
					val1 = 2;
				else 
					val1 = -10;
			}
		}
	}
	
		
	for(a=0; a<index; a=a+1){
		int d;
		d = 10;
		if(d >= 10){
			d = 20;
			while(index != 200){
				index = index + 1;
			}
		}
		else 
			d = 30;
		
	}
	

}


int IF_STMT() {
	int a, b;
	a=10;
	b=10;

	if(a >= b){}    				
	
	if(a == b)
		a = 1;			


							
	if(a<b){											
		a = b;
	}							
	else
		a = a+1;

	
	if(a<b)							
		a=b;
	else
		a=a+1;


	if(a<b)							
		a=b;
	else{
		a=a+1;
	}
	
	if(a<b){}						
	else{ a=a+1; }	
	
}


int Return_Func (int a){
	int b;

	return a;
	return a/b;
	return a-b;
	return -a;
	return (-a);
	return (a-b)+a;
	return a*b;
	return;
}

int Func_Call(int a, int b){
	
	function1(a, b);
	function1();

	return a;
}





int UnnopBinop (int a, int b){
	a = a + b;
	a = a - b;
	a = a / b;
	a = a * b;
	a = (a + b);
	a = (a - b);
	a = -a;
	a = -b;
	a = -a + b;
	a = -a / b;
	a = (-a) / b;
	a = (-a / b);
	a = (a / -b);
	a = -a - -b;
	a = (-a) - (-b);
	a = -a - (-b);
	a = ((-a + b));
	a = ((-a)) / (-b);
	a = (-a * -a) / b;
	a = a + b - b;
	a = a + b / b;
	a = a + (b * a) / a;
	a = (a + ((b * -a) / a) + -b);
	a = (b + (b - -a) * a + -a);

	return a;
}

