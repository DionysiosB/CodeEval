#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void longestWord(char * inputName) {
    std::string line;
    std::ifstream inputFile (inputName);   

    if(inputFile){      

        while(getline(inputFile,line)){

            std::string currentWord(""), maxWord("");
            for(unsigned k = 0; k < line.size(); k++){

                if(line[k] == ' '){
                    if(currentWord.size() > maxWord.size()){maxWord = currentWord;}
                    currentWord = "";
                }
                else{currentWord += line[k];}

            }

            if(currentWord.size() > maxWord.size()){maxWord = currentWord;}
            std::cout << maxWord << std::endl;

        }

        inputFile.close();
    }
}   

int main (int argc, char * const argv[]) {
    longestWord(argv[1]);
    return 0;
}
