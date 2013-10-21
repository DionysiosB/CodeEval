#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

void cashRegister(char* inputName) {
	string line,first,second,outputString;
	vector<string> outputVector;
	int colonPos, number,whole, partial;
	float price,cash;
	int billArray[]={100,50,20,10,5,2,1};string billNames[]={"ONE HUNDRED","FIFTY","TWENTY","TEN","FIVE","TWO","ONE"};
	int coinArray[]={50,25,10,5,1};string coinNames[]={"HALF DOLLAR","QUARTER","DIME","NICKEL","PENNY"};
		
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){	
			outputString="";outputVector.clear();		
			colonPos=line.find(";");
				first=line.substr(0,colonPos);second=line.substr(colonPos+1);
				price=atof(first.c_str());cash=atof(second.c_str());
				if(cash<price){cout << "ERROR"<<endl;}
				else if (cash==price){cout << "ZERO"<<endl;}
				else {					
					whole=int(cash-price);partial=round(100*(cash-price-whole));
															
					for(int k=0;k<7;++k){
							number=(whole/billArray[k]);
							whole -=number*billArray[k];
							for(int m=0;m<number;++m){outputVector.push_back(billNames[k]);}
					}				
										
					for(int k=0;k<5;++k){
						number=(partial/coinArray[k]);
						partial -=number*coinArray[k];
						for(int m=0;m<number;++m){outputVector.push_back(coinNames[k]);}
					}
										
					for(vector<string>::iterator myIter=outputVector.begin();myIter != outputVector.end();++myIter){outputString+=(*myIter);outputString+=",";}
					outputString=outputString.substr(0,outputString.size()-1);
					cout <<outputString<<endl;
			}
		}
	}
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	cashRegister(argv[1]);
	return 0;
}