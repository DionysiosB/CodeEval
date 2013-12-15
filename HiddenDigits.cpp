#include <iostream>
#include <fstream>
#include <sstream>

void hiddenDigits(char * inputName) {
    std::string line;
    //ifstream inputFile (inputName);   
    std::ifstream inputFile ("inputFile.txt");

    if(inputFile){      

        while(getline(inputFile,line)){
            bool isEmpty(1);
            for(unsigned k = 0; k < line.size(); k++){
                int number(0);
                if('0' <= line[k] && line[k] <= '9'){isEmpty = 0; number = line[k] - '0'; std::cout << number;}
                else if('a' <= line[k] && line[k] <= 'j'){isEmpty = 0; number = line[k] - 'a'; std::cout << number;}
            }
            if(isEmpty){std::cout << "NONE";}
            std::cout << std::endl;
        }

        inputFile.close();
    }
}   

int main (int argc, char * const argv[]) {
    hiddenDigits(argv[1]);
    return 0;
}
