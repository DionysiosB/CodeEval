#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

void SplitTheNumber(char * inputName) {

    std::string line;
	//std::ifstream inputFile (inputName);	
    std::ifstream inputFile ("inputFile");
	if(inputFile){		
		while(getline(inputFile,line)){

            std::vector<int> digits;
            int index;
            for(index = 0; index < line.size(); index++){
                if(line[index] == ' '){break;}
                digits.push_back(line[index] - '0');
            }

            ++index;

            char op;
            long result(0), number(0);
            int d(0);
            for(; index < line.size(); index++){
                if(line[index] == '+' || line[index] == '-'){
                    result = number;
                    op = line[index];
                    number = 0;
                    continue;
                }

                number = 10 * number + digits[d++];
            }

            result = (op == '+') ? (result + number) : (result - number);
            std::cout << result << std::endl;


		}
	}
	inputFile.close();
}	

int main (int argc, char * const argv[]) {
	SplitTheNumber(argv[1]);
	return 0;
}
