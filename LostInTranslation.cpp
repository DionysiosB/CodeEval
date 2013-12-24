#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

void lostInTranslation(char * inputName) {

    std::map<char,char> decode;
    decode.insert(std::pair<char,char>('a','y'));
    decode.insert(std::pair<char,char>('b','h'));
    decode.insert(std::pair<char,char>('c','e'));
    decode.insert(std::pair<char,char>('d','s'));
    decode.insert(std::pair<char,char>('e','o'));
    decode.insert(std::pair<char,char>('f','c'));
    decode.insert(std::pair<char,char>('g','v'));
    decode.insert(std::pair<char,char>('h','x'));
    decode.insert(std::pair<char,char>('i','d'));
    decode.insert(std::pair<char,char>('j','u'));
    decode.insert(std::pair<char,char>('k','i'));
    decode.insert(std::pair<char,char>('l','g'));
    decode.insert(std::pair<char,char>('m','l'));
    decode.insert(std::pair<char,char>('n','b'));
    decode.insert(std::pair<char,char>('o','k'));
    decode.insert(std::pair<char,char>('p','r'));
    decode.insert(std::pair<char,char>('q','z'));
    decode.insert(std::pair<char,char>('r','t'));
    decode.insert(std::pair<char,char>('s','n'));
    decode.insert(std::pair<char,char>('t','w'));
    decode.insert(std::pair<char,char>('u','j'));
    decode.insert(std::pair<char,char>('v','p'));
    decode.insert(std::pair<char,char>('w','f'));
    decode.insert(std::pair<char,char>('x','m'));
    decode.insert(std::pair<char,char>('y','a'));
    decode.insert(std::pair<char,char>('z','q'));
    decode.insert(std::pair<char,char>(' ',' '));

    std::string line;
    std::ifstream inputFile (inputName);   

    if(inputFile){      

        while(getline(inputFile,line)){
            for(unsigned k = 0; k < line.size(); k++){std::cout << decode[line[k]];}
            std::cout << std::endl;
        }

        inputFile.close();
    }
}   

int main (int argc, char * const argv[]) {
    lostInTranslation(argv[1]);
    return 0;
}
