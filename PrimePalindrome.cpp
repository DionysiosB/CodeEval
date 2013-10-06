#include <iostream>
using namespace std;

void primePalindrome(unsigned upperBound){
	bool primesList[upperBound+1];
	for (unsigned k=4; k<upperBound; k++) primesList[k]=true;
	primesList[0]=false;primesList[1]=false;primesList[2]=true;primesList[3]=true;
	for (unsigned k=2; k<=upperBound; k++) {if (primesList[k]) {for (unsigned m=2; m<=upperBound/k; m++) {primesList[m*k]=false;}}}	
	for(unsigned k=upperBound;k>=2;--k){if(primesList[k] && (k%10 == (k/100)%10) || (k%100==0 && k%11==0)){cout << k<< " "; break;}}
}

int main (int argc, char * const argv[]) {
	
	primePalindrome(1000);
	return 0;
}


