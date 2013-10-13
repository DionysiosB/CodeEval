#include <iostream>
using namespace std;

void oddNumbers(int input){
	for(int k=0;k<=input;++k){if(k%2==1) cout<<k<<endl;}
}

int main (int argc, char * const argv[]) {
	 oddNumbers(100);
	 return 0;
}
