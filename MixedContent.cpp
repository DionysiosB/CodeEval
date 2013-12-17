#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void hiddenDigits(char * inputName) {
    std::string line;
    //ifstream inputFile (inputName);   
    std::ifstream inputFile ("inputFile");

    if(inputFile){      

        while(getline(inputFile,line)){

            std::vector<std::string> words, numbers;

            std::string temp("");
            for(unsigned k = 0; k < line.size(); k++){
                if(line[k] == ','){
                    if('0' <= temp[0] && temp[0] <= '9'){numbers.push_back(temp);}
                    else if('a' <= temp[0] && temp[0] <= 'z'){words.push_back(temp);}
                    temp = "";
                }
                else{temp += line[k];}
            }

            if(temp.size() > 0 && '0' <= temp[0] && temp[0] <= '9'){numbers.push_back(temp);}
            else if(temp.size() > 0 && 'a' <= temp[0] && temp[0] <= 'z'){words.push_back(temp);}


            for(int k = 0; k < words.size(); k++){
                std::cout << words[k];
                if(k + 1 != words.size()){std::cout << ",";}
                else if(numbers.size() > 0){std::cout << "|";}
            }
            for(int k = 0; k < numbers.size(); k++){
                std::cout << numbers[k];
                if(k + 1 != numbers.size()){std::cout << ",";}
            }
            std::cout << std::endl;
        }

        inputFile.close();
    }
}   

int main (int argc, char * const argv[]) {
    hiddenDigits(argv[1]);
    return 0;
}
