#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string card;
	
    while(1) {

		int turn = 0;
		vector< list<int> > players(2);

		for(int i = 0; i < 52; ++i, turn = !turn) {

			cin >> card;
        	if(card[0] == '#')
				return 0;
		
			switch(card[1]) {
				case 'J':
					players[turn].push_front(1);
					break;
				case 'Q':
					players[turn].push_front(2);
					break;
				case 'K':
					players[turn].push_front(3);
					break;
				case 'A':
					players[turn].push_front(4);
					break;
				default:
					players[turn].push_front(0);
			}
		}
		list<int> game;
		bool cycle = false;
		while(!players[turn].empty()) {
			int currentCard = players[turn].front();
			players[turn].pop_front();
			game.push_back(currentCard);
			turn = !turn;
			while(currentCard) {
				if(players[turn].empty())
				{
					cycle = false;
					break;
				}
				else
					cycle = true;
				int card = players[turn].front();
				players[turn].pop_front();
				game.push_back(card);
				if(card)
				{			
					turn = !turn;
					currentCard = card;
				}
				else
					--currentCard;
			}
			if(cycle)
			{
				cycle = false;
				turn = !turn;
				while(!game.empty())
				{
					players[turn].push_back(game.front());
					game.pop_front();
				}
			}
		}
		if(players[0].empty())
			cout << "1 " << setw(2) << players[1].size() << "\n"; 
		else
			cout << "2 " << setw(2) << players[0].size() << "\n";
	}
	return  0;
}