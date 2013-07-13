#include <iostream>
#include <string>

using namespace std;

int main() {
  int round;
  
  while ((cin >> round) && round != -1) {
    string ans, guess;
    int ansbit[26] = {0};
    int guessbit[26] = {0};
    int anscount = 0;
    int rightcount = 0;
    int wrongcount = 0;

    cout << "Round " << round << endl;
    cin >> ans >> guess;
    for (int i = 0; i < ans.size(); i++) {
      ansbit[ans[i]-'a'] = 1;
    }
    for (int i = 0; i < 26; i++)
      if (ansbit[i] == 1)
	anscount++;
    for (int i = 0; i < guess.size(); i++) {
      if (ansbit[guess[i]-'a'] == 1) {
	ansbit[guess[i]-'a'] = 2;
	rightcount++;
	if (rightcount == anscount) {
	  cout << "You win." << endl;
	  break;
	}
      }
      else if (ansbit[guess[i]-'a'] == 0) {
	ansbit[guess[i]-'a'] = 2;
	wrongcount++;
	if (wrongcount == 7) {
	  cout << "You lose." << endl;
	  break;
	}
      }
    }

    if (rightcount < anscount && wrongcount < 7) {
      cout << "You chickened out." << endl;
    }

  }
  return 0;
}
