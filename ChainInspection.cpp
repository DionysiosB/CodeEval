#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

void chainInspection(char * inputName) {

    std::string line;
    std::ifstream inputFile (inputName);   

    if(inputFile){      
        while(getline(inputFile,line)){

            std::map<std::string, std::string> chain;

            std::string left(""), right("");
            int index(0);
            bool state(0);
            while(index < line.size()){
                if(line[index] == ';'){
                    chain.insert(std::pair<std::string, std::string>(left,right));
                    left = right = "";
                    state = 0;
                }
                else if(line[index] == '-'){state = 1;}
                else if(state == 0){left += line[index];}
                else if(state == 1){right += line[index];}
                ++index;
            }
            chain.insert(std::pair<std::string, std::string>(left,right));

            int counter(0);
            left = "BEGIN";
            while(chain.find(left) != chain.end() && left != "END"){
                left = chain[left];
                ++counter;
                if(counter > chain.size()){break;}
            }

            if(left == "END" && counter == chain.size()){std::cout << "GOOD" << std::endl;}
            else{std::cout << "BAD" << std::endl;}

        }

        inputFile.close();
    }
}   

int main (int argc, char * const argv[]) {
    chainInspection(argv[1]);
    return 0;
}
