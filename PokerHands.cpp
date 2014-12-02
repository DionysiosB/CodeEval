#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;
void Tokenize(const string& str,vector<string>& tokens,const string& delimiters = " ") {
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    string::size_type pos = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos){
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = str.find_first_not_of(delimiters, pos);
        pos = str.find_first_of(delimiters, lastPos);
    }
}

class card{
    public:
        int number;
        char suit;
        string CardString();
        bool operator> (card &card1);
};

bool card::operator> (card &card1){
    if(number > card1.number)
        return(true);
    return(false);
}

string card::CardString(){
    stringstream card_ss;
    card_ss << number;
    card_ss << suit;
    return(card_ss.str());
}

class PokerHand{
    public:
        card hand[5] ;
        bool allSameSuit;
        bool threeOfKind;
        bool fourOfKind;
        int numPairs;
        int threeOfKindVal, fourOfKindVal;
        int pairValues[2];
        int bestHand;

        PokerHand() {};
        PokerHand(bool first_hand, vector<string> &hand_definition);
        void printPokerHand();
        int convert_facecard_to_num(char facevalue);
        int AnalyzeHand();
        int CompareHands(PokerHand hand_opp);
        bool is_royal_flush();
        bool is_straight_flush();
        bool is_four_of_a_kind();
        bool is_full_house();
        bool is_flush();
        bool is_straight();
        bool is_three_of_a_kind();
        bool is_two_pair();
        bool is_pair();
        bool is_high_card();
};

bool PokerHand::is_royal_flush(){
    if(hand[4].number == 14 && allSameSuit){
        for(int i=3; i>=0; i--){
            if(hand[i].number != i+10)
                return(false);
        }
        return(true);
    }
    else
        return(false);
}

bool PokerHand::is_straight_flush(){
    int num;

    if(allSameSuit){
        num = hand[0].number;
        num++;
        for(int i=1; i<5; i++){
            if(hand[i].number != num)
                return(false);
            num++;
        }
    }
    else
        return(false);
}

bool PokerHand::is_four_of_a_kind(){
    if(fourOfKind)
        return true;
    return(false);
}

bool PokerHand::is_full_house(){
    if(numPairs == 1 && threeOfKind)
        return(true);
    return(false);
}

bool PokerHand::is_flush(){
    if(allSameSuit)
        return(true);
    return(false);
}

bool PokerHand::is_straight(){
    int num;
    num = hand[0].number;
    num++;
    for(int i=1; i<5; i++){
        if(hand[i].number != num)
            return(false);
        num++;
    }	
    return(true);
}

bool PokerHand::is_three_of_a_kind(){
    if(threeOfKind)
        return(true);
    return(false);
}

bool PokerHand::is_two_pair(){
    if(numPairs == 2)
        return(true);
    return(false);
}

bool PokerHand::is_pair(){
    if(numPairs == 1)
        return(true);
    return(false);
}

PokerHand::PokerHand(bool first_hand, vector<string> &hand_definition){
    int start_loop, end_loop, idx, pair_idx;
    char current_suite;
    map<int,int> card_count;
    map<int,int>::iterator card_count_it;

    if(first_hand){
        start_loop = 0;
        end_loop = 5;
    }
    else{
        start_loop =5;
        end_loop = 10;
    }

    idx = 0;
    for(int i=start_loop; i<end_loop;i++){
        card new_card;
        new_card.number = convert_facecard_to_num(hand_definition[i][0]);
        new_card.suit = hand_definition[i][1];
        hand[idx] = new_card;
        idx++;
    }

    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(hand[j] > hand[j+1]){
                card temp_card = hand[j+1];
                hand[j+1] = hand[j];
                hand[j]  = temp_card;
            }
        }
    }

    allSameSuit = true;
    current_suite = hand[0].suit;
    for(int i=1; i<5; i++){
        if(hand[i].suit != current_suite)
            allSameSuit = false;
    }

    for(int i=0; i<5; i++){
        card_count_it = card_count.find(hand[i].number);
        if(card_count_it == card_count.end())
            card_count.insert(pair<int,int>(hand[i].number,1));
        else
            (*card_count_it).second++;
    }

    numPairs = 0;
    threeOfKind = false;
    fourOfKind = false;
    bestHand = 1;
    pair_idx = 0;
    for (card_count_it = card_count.begin(); card_count_it != card_count.end(); ++card_count_it){
        if(card_count_it->second == 4){
            fourOfKindVal = card_count_it->first;
            fourOfKind = true;
        }
        else if(card_count_it->second == 3){
            threeOfKindVal = card_count_it->first;
            threeOfKind = true;
        }
        else if(card_count_it->second == 2){
            pairValues[pair_idx] = card_count_it->first;
            numPairs++;
            pair_idx++;
        }
    }

    if(numPairs == 2){
        if(pairValues[0] < pairValues[1]){
            int temp_int  = pairValues[0];
            pairValues[0] = pairValues[1];
            pairValues[1] = temp_int;
        }
    }
    AnalyzeHand();
}

int PokerHand::AnalyzeHand(){
    if(is_royal_flush())
        bestHand = 10;
    else if(is_straight_flush())
        bestHand = 9;
    else if(is_four_of_a_kind())
        bestHand = 8;
    else if(is_full_house())
        bestHand = 7;
    else if(is_flush())
        bestHand = 6;
    else if(is_straight())
        bestHand = 5;
    else if(is_three_of_a_kind())
        bestHand = 4;
    else if(is_two_pair())
        bestHand = 3;
    else if(is_pair())
        bestHand = 2;
    else 
        bestHand = 1;
}

int PokerHand::CompareHands(PokerHand hand_opp){
    if(bestHand > hand_opp.bestHand)
        return(1);

    else if(hand_opp.bestHand > bestHand)
        return(-1);

    else if(bestHand == 10)
        return(0);

    else if(bestHand == 9 || bestHand == 6 || bestHand == 5){ 
        if(hand[0] > hand_opp.hand[0])
            return(1);
        else if(hand_opp.hand[0] > hand[0])
            return(-1);
        else
            return(0);
    }

    else if(bestHand ==8){
        if(fourOfKindVal > hand_opp.fourOfKindVal)
            return(1);
        else
            return(-1);
    }

    else if(bestHand == 7){
        if(threeOfKindVal > hand_opp.threeOfKindVal)
            return(1);
        else
            return(-1);
    }

    else if(bestHand == 4){
        if(threeOfKindVal > hand_opp.threeOfKindVal)
            return(1);
        else if(hand_opp.threeOfKindVal > threeOfKindVal)
            return(-1);
        else{
            for(int i = 4; i>=0; i--){
                if(hand[i]>hand_opp.hand[i])
                    return(1);
                else if(hand_opp.hand[i] > hand[i])
                    return(-1);
            }
            return(0);
        }
    }

    else if(bestHand == 3){
        if(pairValues[0] > hand_opp.pairValues[0])
            return(1);
        else if(pairValues[0] < hand_opp.pairValues[0])
            return(-1);
        else{
            if(pairValues[1] > hand_opp.pairValues[1])
                return(1);
            else if(pairValues[1] < hand_opp.pairValues[1])
                return(-1);
            else{
                for(int i = 4; i>=0; i--){
                    if(hand[i]>hand_opp.hand[i])
                        return(1);
                    else if(hand_opp.hand[i] > hand[i])
                        return(-1);
                }
                return(0);
            }
        }
    }

    else if(bestHand == 2){
        if(pairValues[0] > hand_opp.pairValues[0])
            return(1);
        else if(pairValues[0] < hand_opp.pairValues[0])
            return(-1);
        else{
            for(int i = 4; i>=0; i--){
                if(hand[i]>hand_opp.hand[i])
                    return(1);
                else if(hand_opp.hand[i] > hand[i])
                    return(-1);
            }
            return(0);
        }
    }

    else if(bestHand == 1){
        for(int i = 4; i>=0; i--){
            if(hand[i]>hand_opp.hand[i])
                return(1);
            else if(hand_opp.hand[i] > hand[i])
                return(-1);
        }
        return(0);
    }
}

void PokerHand::printPokerHand(){
    for(int i=0; i<5; i++)
        cout << hand[i].CardString() << " ";
    cout << "Best hand: " << bestHand << endl;
}

int PokerHand::convert_facecard_to_num(char facevalue){
    if(facevalue == 'T')
        return(10);
    else if(facevalue == 'J')
        return(11);
    else if(facevalue == 'Q')
        return(12);
    else if(facevalue == 'K')
        return(13);
    else if(facevalue == 'A')
        return(14);
    else
        return(atoi(&facevalue));
}


int main(int argc, char* argv[]){
    int comp_result;
    vector<string> tokens;
    ifstream file;
    string lineBuffer;

    file.open(argv[1]);

    while (!file.eof()){
        getline(file, lineBuffer);
        if (lineBuffer.length() == 0)
            continue;
        else{
            tokens.clear();
            Tokenize(lineBuffer, tokens, "\r\n ");
            if(tokens.size()==10){
                PokerHand first = PokerHand(true, tokens);
                PokerHand second = PokerHand(false, tokens);
                comp_result = first.CompareHands(second);
                if(comp_result == 1)
                    cout << "left" << endl;
                else if(comp_result == -1)
                    cout << "right" << endl;
                else if(comp_result == 0)
                    cout << "none" << endl;
            }
        }
    }
}
