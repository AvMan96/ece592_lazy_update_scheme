#include <cstdlib>
int main() {
	int i=0;
	volatile int b = 0;
	volatile int a[4680] = {0};
	

//Load intensive with poor spatial/temporal locality
//*****************************
	b = a[0]; //to get the start address
		
	for(i=0; i<10000; ++i) {
		int index = rand()%100;
		
		//Load intensive benchmark
		if(index < 80){
			a[(8*rand())%4096];
		}
		else{
			a[(8*rand())%4096] = 10;
		}
			
	}
	
//***************************

//Store intensive with poor spatial/temporal locality
//*****************************
	b = a[0]; //to get the start address
		
	for(i=0; i<10000; ++i) {
		int index = rand()%100;
		
		//Store intensive benchmark
		if(index >= 80){
			a[(8*rand())%4096];
		}
		else{
			a[(8*rand())%4096] = 10;
		}
			
	}
	
//***************************
	b = a[0]; //to get the start address
		
	for(i=0; i<10000; ++i) {
		int index = rand()%100;
		
		//Load intensive benchmark good spatial/temporal locality
		if(index < 80){
			a[rand()%4096];
		}
		else{
			a[rand()%4096] = 10;
		}
			
	}

	//***************************
	b = a[0]; //to get the start address
		
	for(i=0; i<10000; ++i) {
		int index = rand()%100;
		
		//Store intensive benchmark good spatial/temporal locality
		if(index < 80){
			a[rand()%4096];
		}
		else{
			a[rand()%4096] = 10;
		}
			
	}
	
	return 0;
}