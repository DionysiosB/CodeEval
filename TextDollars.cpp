#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
using namespace std;

string dollarRepresentation(unsigned n){
	
	string output="";
	string smallArray[]={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
	string midArray[]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
	string largeArray[]={"Dollars","","Hundred","Thousand","","","Million"};

	int millions=n/1000000;
	if(millions>=100 && millions<=999) {
		output+=smallArray[(millions/100)]+largeArray[2];
		millions=(millions%100);
	}
	if(millions>=1  && millions<=19) output+=smallArray[millions]+largeArray[6];
	if(millions>=20 && millions<=99) output+=midArray[(millions/10)%10]+smallArray[millions%10]+largeArray[6];
	
	n=n-1000000*(n/1000000);
	int thousands=n/1000;
	if(thousands>=100 && thousands<=999) {
		output+=smallArray[(thousands/100)]+largeArray[2];
		thousands=(thousands%100);
	}
	if(thousands>=1  && thousands<=19) output+=smallArray[thousands]+largeArray[3];
	if(thousands>=20 && thousands<=99) output+=midArray[(thousands/10)%10]+smallArray[thousands%10]+largeArray[3];
	
	n=n-1000*(n/1000);
	if(n>=100 && n<=999) {
		output+=smallArray[(n/100)]+largeArray[2];
		n=(n%100);
	}
	if(n>=1  && n<=19) output+=smallArray[n]+largeArray[0];
	if(n>=20 && n<=99) output+=midArray[(n/10)%10]+smallArray[n%10]+largeArray[0];;

	return output;
	
}

void countingDollars(char* inputName) {
	string line;int n;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			n=atoi(line.c_str());
			cout << dollarRepresentation(n)<<endl;
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	countingDollars(argv[1]);
	return 0;
}