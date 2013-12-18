#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

int gcd (int a, int b){return (b == 0) ? a : gcd (b, a%b);}

void shortestRepetition(char * inputName) {
    std::string line;
    std::ifstream inputFile (inputName);   

    if(inputFile){      

        while(getline(inputFile,line)){

            std::map<char,int> occurences;
            for(unsigned k = 0; k < line.size(); k++){
                if(occurences.find(line[k]) != occurences.end()){++occurences[line[k]];}
                else{occurences.insert(std::pair<char,int>(line[k],1));}
            }

            std::map<char,int>::iterator myIter;
            std::vector<int> counts;
            for(myIter = occurences.begin(); myIter != occurences.end(); myIter++){counts.push_back(myIter->second);}

            int totalGcd(0), minPeriod(0);
            for(int k = 0; k < counts.size(); k++){totalGcd = gcd(totalGcd,counts[k]);}
            for(int k = 0; k < counts.size(); k++){minPeriod += counts[k] / totalGcd;}

            std::cout << minPeriod << std::endl;

        }

        inputFile.close();
    }
}   

int main (int argc, char * const argv[]) {
    shortestRepetition(argv[1]);
    return 0;
}
