#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

void morseCode(char * inputName) {

    std::map<std::string,char> morseToText;
    morseToText.insert(std::pair<std::string,char>(".-",'A'));
    morseToText.insert(std::pair<std::string,char>("-...",'B'));
    morseToText.insert(std::pair<std::string,char>("-.-.",'C'));
    morseToText.insert(std::pair<std::string,char>("-..",'D'));
    morseToText.insert(std::pair<std::string,char>(".",'E'));
    morseToText.insert(std::pair<std::string,char>("..-.",'F'));
    morseToText.insert(std::pair<std::string,char>("--.",'G'));
    morseToText.insert(std::pair<std::string,char>("....",'H'));
    morseToText.insert(std::pair<std::string,char>("..",'I'));
    morseToText.insert(std::pair<std::string,char>(".---",'J'));
    morseToText.insert(std::pair<std::string,char>("-.-",'K'));
    morseToText.insert(std::pair<std::string,char>(".-..",'L'));
    morseToText.insert(std::pair<std::string,char>("--",'M'));
    morseToText.insert(std::pair<std::string,char>("-.",'N'));
    morseToText.insert(std::pair<std::string,char>("---",'O'));
    morseToText.insert(std::pair<std::string,char>(".--.",'P'));
    morseToText.insert(std::pair<std::string,char>("--.-",'Q'));
    morseToText.insert(std::pair<std::string,char>(".-.",'R'));
    morseToText.insert(std::pair<std::string,char>("...",'S'));
    morseToText.insert(std::pair<std::string,char>("-",'T'));
    morseToText.insert(std::pair<std::string,char>("..-",'U'));
    morseToText.insert(std::pair<std::string,char>("...-",'V'));
    morseToText.insert(std::pair<std::string,char>(".--",'W'));
    morseToText.insert(std::pair<std::string,char>("-..-",'X'));
    morseToText.insert(std::pair<std::string,char>("-.--",'Y'));
    morseToText.insert(std::pair<std::string,char>("--..",'Z'));
    morseToText.insert(std::pair<std::string,char>(".----",'1'));
    morseToText.insert(std::pair<std::string,char>("..---",'2'));
    morseToText.insert(std::pair<std::string,char>("...--",'3'));
    morseToText.insert(std::pair<std::string,char>("....-",'4'));
    morseToText.insert(std::pair<std::string,char>(".....",'5'));
    morseToText.insert(std::pair<std::string,char>("-....",'6'));
    morseToText.insert(std::pair<std::string,char>("--...",'7'));
    morseToText.insert(std::pair<std::string,char>("---..",'8'));
    morseToText.insert(std::pair<std::string,char>("----.",'9'));
    morseToText.insert(std::pair<std::string,char>("-----",'0'));

    std::string line;
    //ifstream inputFile (inputName);   
    std::ifstream inputFile ("inputFile.txt");

    if(inputFile){      

        while(getline(inputFile,line)){

            std::string currentSymbol("");
            for(unsigned k = 0; k < line.size(); k++){
                if(line[k] == ' ' && k > 0 && line[k - 1] != ' '){std::cout << morseToText[currentSymbol]; currentSymbol = "";}
                else if(line[k] == ' ' && k > 0 && line[k - 1] == ' '){std::cout << " "; currentSymbol = "";}
                else{currentSymbol += line[k];}
            }
            if(currentSymbol.size() > 0){std::cout << morseToText[currentSymbol];}
            std::cout << std::endl;
        }

        inputFile.close();
    }
}   

int main (int argc, char * const argv[]) {
    morseCode(argv[1]);
    return 0;
}



