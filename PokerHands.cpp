#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;
void Tokenize(const string& str,vector<string>& tokens,const string& delimiters );

class card{
	public:
		int number;
		char suit;
		string CardString();
		bool operator> (card &card1);
};

bool
card::operator> (card &card1){
	if(number > card1.number)
		return(true);
	return(false);
}

string 
card::CardString(){
	stringstream card_ss;
	card_ss << number;
	card_ss << suit;
	return(card_ss.str());
}

class PokerHand{
	public:
		card hand[5] ;
		bool all_same_suite;
		bool three_of_kind;
		bool four_of_kind;
		int num_pairs;
		int three_of_kind_val, four_of_kind_val;
		int pair_values[2];
		int best_hand;

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

bool
PokerHand::is_royal_flush(){
	if(hand[4].number == 14 && all_same_suite){
		for(int i=3; i>=0; i--){
			if(hand[i].number != i+10)
				return(false);
		}
		return(true);
	}
	else
		return(false);
}

bool
PokerHand::is_straight_flush(){
	int num;

	if(all_same_suite){
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

bool 
PokerHand::is_four_of_a_kind(){
	if(four_of_kind)
		return true;
	return(false);
}

bool 
PokerHand::is_full_house(){
	if(num_pairs == 1 && three_of_kind)
		return(true);
	return(false);
}

bool 
PokerHand::is_flush(){
	if(all_same_suite)
		return(true);
	return(false);
}

bool 
PokerHand::is_straight(){
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

bool 
PokerHand::is_three_of_a_kind(){
	if(three_of_kind)
		return(true);
	return(false);
}

bool
PokerHand::is_two_pair(){
	if(num_pairs == 2)
		return(true);
	return(false);
}

bool
PokerHand::is_pair(){
	if(num_pairs == 1)
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

	//bubble sort hand
	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){
			if(hand[j] > hand[j+1]){
				card temp_card = hand[j+1];
				hand[j+1] = hand[j];
				hand[j]  = temp_card;
			}
		}
	}

	//check if all cards are same suite;
	all_same_suite = true;
	current_suite = hand[0].suit;
	for(int i=1; i<5; i++){
		if(hand[i].suit != current_suite)
			all_same_suite = false;
	}

	for(int i=0; i<5; i++){
		card_count_it = card_count.find(hand[i].number);
		if(card_count_it == card_count.end())
			card_count.insert(pair<int,int>(hand[i].number,1));
		else
			(*card_count_it).second++;
	}

	//count pairs, three of a kinds, four of a kinds etc
	num_pairs = 0;
	three_of_kind = false;
	four_of_kind = false;
	best_hand = 1;
	pair_idx = 0;
	for (card_count_it = card_count.begin(); card_count_it != card_count.end(); ++card_count_it){
		if(card_count_it->second == 4){
			four_of_kind_val = card_count_it->first;
			four_of_kind = true;
		}
		else if(card_count_it->second == 3){
			three_of_kind_val = card_count_it->first;
			three_of_kind = true;
		}
		else if(card_count_it->second == 2){
			pair_values[pair_idx] = card_count_it->first;
			num_pairs++;
			pair_idx++;
		}
	}

	//sort pair values;
	if(num_pairs == 2){
		if(pair_values[0] < pair_values[1]){
			int temp_int  = pair_values[0];
			pair_values[0] = pair_values[1];
			pair_values[1] = temp_int;
		}
	}
	AnalyzeHand();
}

//return value of best hand in 
int 
PokerHand::AnalyzeHand(){
	if(is_royal_flush())
		best_hand = 10;
	else if(is_straight_flush())
		best_hand = 9;
	else if(is_four_of_a_kind())
		best_hand = 8;
	else if(is_full_house())
		best_hand = 7;
	else if(is_flush())
		best_hand = 6;
	else if(is_straight())
		best_hand = 5;
	else if(is_three_of_a_kind())
		best_hand = 4;
	else if(is_two_pair())
		best_hand = 3;
	else if(is_pair())
		best_hand = 2;
	else 
		best_hand = 1;
}

int
PokerHand::CompareHands(PokerHand hand_opp){
	if(best_hand > hand_opp.best_hand)
		return(1);

	else if(hand_opp.best_hand > best_hand)
		return(-1);

	else if(best_hand == 10) //all royal flushes are ties
		return(0);

	else if(best_hand == 9 || best_hand == 6 || best_hand == 5){ //check highest card for straight flush, flush and straight
		if(hand[0] > hand_opp.hand[0])
			return(1);
		else if(hand_opp.hand[0] > hand[0])
			return(-1);
		else
			return(0);
	}

	else if(best_hand ==8){ //check highest card for four of  kind value
		if(four_of_kind_val > hand_opp.four_of_kind_val)
			return(1);
		else
			return(-1);
	}

	else if(best_hand == 7){ //check highest three of a kind for full house
		if(three_of_kind_val > hand_opp.three_of_kind_val)
			return(1);
		else
			return(-1);
	}

	else if(best_hand == 4){ //check highest three of a kind
		if(three_of_kind_val > hand_opp.three_of_kind_val)
			return(1);
		else if(hand_opp.three_of_kind_val > three_of_kind_val)
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

	else if(best_hand == 3){ //check pairs then compare rest of the items
		if(pair_values[0] > hand_opp.pair_values[0])
			return(1);
		else if(pair_values[0] < hand_opp.pair_values[0])
			return(-1);
		else{
			if(pair_values[1] > hand_opp.pair_values[1])
				return(1);
			else if(pair_values[1] < hand_opp.pair_values[1])
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

	else if(best_hand == 2){ //check highest pair then compare rest of the items
		if(pair_values[0] > hand_opp.pair_values[0])
			return(1);
		else if(pair_values[0] < hand_opp.pair_values[0])
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

	else if(best_hand == 1){ //compare high cards
		for(int i = 4; i>=0; i--){
			if(hand[i]>hand_opp.hand[i])
				return(1);
			else if(hand_opp.hand[i] > hand[i])
				return(-1);
		}
		return(0);
	}
}

void
PokerHand::printPokerHand(){
	for(int i=0; i<5; i++)
		cout << hand[i].CardString() << " ";
	cout << "Best hand: " << best_hand << endl;
}

int 
PokerHand::convert_facecard_to_num(char facevalue){
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

void Tokenize(const string& str,vector<string>& tokens,const string& delimiters = " ") {
	// Skip delimiters at beginning.
	string::size_type lastPos = str.find_first_not_of(delimiters, 0);

	// Find first "non-delimiter".
	string::size_type pos = str.find_first_of(delimiters, lastPos);

	while (string::npos != pos || string::npos != lastPos){
		// Found a token, add it to the vector.
		tokens.push_back(str.substr(lastPos, pos - lastPos));

		// Skip delimiters.  Note the "not_of"
		lastPos = str.find_first_not_of(delimiters, pos);

		// Find next "non-delimiter"
		pos = str.find_first_of(delimiters, lastPos);
	}
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
			continue; //ignore all empty lines
		else{
			tokens.clear();
			Tokenize(lineBuffer, tokens, "\r\n ");
			if(tokens.size()==10){
				PokerHand first = PokerHand(true, tokens);
				PokerHand second = PokerHand(false, tokens);
				//first.printPokerHand();
				//second.printPokerHand();
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