#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <stdlib.h>
using namespace std;

void URLComparison(char* inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){
		while(getline(inputFile,line)){
			string output;
			int colonPos=line.find(";");		
			string a=line.substr(0,colonPos);
			string b=line.substr(colonPos+1);
			unsigned counterA=0,counterB=0;bool match=1;
			
			while(match && counterA<a.size() && counterB <b.size()){
				
				if(tolower(a[counterA])==tolower(b[counterB])){++counterA;++counterB;}
				
				else if(a[counterA]==':' && a[counterA+1]=='8' && a[counterA+2]=='0' && b[counterB]=='/'){counterA+=3;}
				else if(a[counterA]==':' && a[counterA+1]=='/' && b[counterB]=='/'){counterA+=1;}
				else if(a[counterA]=='8' && a[counterA+1]=='0' && b[counterB]=='/'){counterA+=2;}
				
				else if(b[counterB]==':' && ((b[counterB+1]=='8' && b[counterB+2]=='0')||a[counterA+1]=='/') && a[counterA]=='/'){counterB+=3;}
				else if(b[counterB]==':' && b[counterB+1]=='/' && a[counterA]=='/'){counterB+=1;}
				else if(b[counterB]=='8' && b[counterB+1]=='0' && a[counterB]=='/'){counterB+=2;}
				
				else if(a[counterA]=='~' && (b[counterB]=='%' && b[counterB+1]=='7' && tolower(b[counterB+2])=='e')){++counterA;counterB+=3;}
				else if(b[counterB]=='~' && (a[counterA]=='%' && a[counterA+1]=='7' && tolower(a[counterA+2])=='e')){++counterB;counterA+=3;}
				else {match=0;break;}
			}
			if(match){cout<<"True"<<endl;}
			else{cout <<"False"<<endl;}
		}
		inputFile.close();
	}
}

int main (int argc, char * const argv[]) {
	URLComparison(argv[1]);
	return 0;
}