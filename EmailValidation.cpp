#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex.h>
using namespace std;

static int compile_regex (regex_t * r, const char * regText){
	int status = regcomp (r, regText, REG_EXTENDED|REG_NEWLINE);
	if (status != 0) {cout <<"Regex error compiling: "<<regText;return -1;}
	return 0;
}

static int match_regex (regex_t * r, const char * to_match){
	const char * p = to_match;
	const int n_matches = 1;regmatch_t m[n_matches];
	int nomatch = regexec (r, p, n_matches, m, 0);
	if (nomatch) {cout<< "false"<<endl;}
	else {cout<< "true"<<endl;}
	return 0;
}

void emailValidation(char* inputName) {
	string line, output;
	//ifstream inputFile (inputName);
	ifstream inputFile ("inputFile.txt");
	if(inputFile){		
		while(getline(inputFile,line)){
			const char * regText;
			const char * findText;
			findText =line.c_str();
			regText = "[[:alpha:]][[:alnum:]]+@[[:alnum:]]+.[[:alnum:]]";			
			regex_t r;
			compile_regex(& r, regText);
			match_regex(&r, findText);
			regfree(&r);
		}
	}
	
	inputFile.close();
}

int main (int argc, char * const argv[]) {
	emailValidation(argv[1]);
	return 0;
}


