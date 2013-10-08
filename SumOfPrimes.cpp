#include <iostream>
#include <cmath>
using namespace std;

int primeSum(int input){
	
	unsigned n=10*input;
	unsigned long long totalSum=0;
	bool primesList[n+1];
	for (unsigned k=0; k<n; k++) primesList[k]=true;
	primesList[0]=false;primesList[1]=false;primesList[2]=true;primesList[3]=true;
	
	for (unsigned k=2; k<=n; k++) {if (primesList[k]==true) {for (unsigned m=2; m<=n/k; m++) {primesList[m*k]=false;}}}
	
	int numPrimes=0;
	for (unsigned k=0; k<=n; k++) {
		if(primesList[k]){totalSum+=k;numPrimes++;}
		if(numPrimes>=input) break;
	}
		
	 return totalSum;
}


int main (int argc, char * const argv[]) {
	 cout << endl<< primeSum(1000)<< endl;
	 return 0;
}
