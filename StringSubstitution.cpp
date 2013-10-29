#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

void replaceSubstrings(char * inputName) {
	string line;
	//ifstream inputFile (inputName);	
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			unsigned int firstPos=line.find(';'),secondPos=line.find(',');
			string output=line.substr(0,firstPos);
			vector<string> findStrings,replaceStrings;
			
			while(firstPos<line.size()-1){
				findStrings.push_back(line.substr(firstPos+1,secondPos-firstPos-1));
				firstPos=secondPos;secondPos=line.find(',',secondPos+1);
				replaceStrings.push_back(line.substr(firstPos+1,secondPos-firstPos-1));
				firstPos=secondPos;secondPos=line.find(',',secondPos+1);
			}
			
			unsigned currentPos,outputLength=output.size();bool found;
			string modified=string(output.size(),'0');
			
			for(unsigned currentPattern=0;currentPattern<findStrings.size();currentPattern++){
				cout << endl <<endl<<"==========="<<endl<<endl;
				currentPos=0;
				unsigned subLength=findStrings[currentPattern].size();
				while(currentPos<=outputLength-subLength){
					found=0;
					cout << "CurrentPos:"<<currentPos<<endl;
					string comparisonString=output.substr(currentPos,subLength);
					string checkString=modified.substr(currentPos,subLength);
					if(comparisonString==findStrings[currentPattern] && checkString==string(subLength,'0')){
						cout<<"*****"<<findStrings[currentPattern]<<"====>"<<replaceStrings[currentPattern]<<endl;
						cout <<"-----PreviousString:"<< output.substr(0,currentPos)<<endl;
						output=output.substr(0,currentPos)+replaceStrings[currentPattern]+output.substr(currentPos+findStrings[currentPattern].size(),outputLength);
						modified=modified.substr(0,currentPos)+string(replaceStrings[currentPattern].size(),'1')+modified.substr(currentPos+findStrings[currentPattern].size(),outputLength);
						outputLength=output.size();currentPos+=replaceStrings[currentPattern].size();
						found=1;
					}
					if(found){cout << output<<endl<<modified<<endl;}
					else{currentPos++;}
				}
			}
			cout << output<<endl;
		}
		inputFile.close();
	}
}	

int main (int argc, char * const argv[]) {
	replaceSubstrings(argv[1]);
	return 0;
}