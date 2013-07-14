#include <iostream>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void fastPrimes(long upperLimit) {
	
	int temp;
	int primeList[upperLimit+1];
	for(int k=0;k<=upperLimit;++k) primeList[k]=0;
	
	for(int x=1;x<=sqrt(upperLimit);++x){
		for(int y=1;y<=sqrt(upperLimit);++y){
			
			temp=4*x*x+y*y;
			if(temp<=upperLimit && (temp%12==1 || temp%12==5)) primeList[temp]=1-primeList[temp];
			
			temp=3*x*x+y*y;
			if(temp<=upperLimit && temp%12==7) primeList[temp]=1-primeList[temp];
			
			temp=3*x*x-y*y;
			if( (x>y) && (temp<=upperLimit) && (temp%12==11)) primeList[temp]=1-primeList[temp];
			
		}
	}
	
	for(int k=5;k<=sqrt(upperLimit);++k)
		if(primeList[k])
			for(int m=1;m<=upperLimit/(k*k);++m)
				primeList[m*k*k]=0;
	
	
	if(upperLimit>=2) {
		primeList[2]=1;
		cout << "2";
	}
	else return;
	if(upperLimit>=3) primeList[3]=1;
	
	
	for(int k=3;k<=upperLimit;++k)
		if(primeList[k]) cout <<"," <<k;
	cout << endl;

}

int main (int argc, char * const argv[]) {
	
	char * inputName=argv[1];
	string line;long upperLimit;
	
	ifstream inputFile (inputName);	
	if(inputFile){		
		while(getline(inputFile,line)){
		    istringstream buf(line);
			buf >> upperLimit;
			fastPrimes(upperLimit);
		}
	}
	
	return 0;
}


