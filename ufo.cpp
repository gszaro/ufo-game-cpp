#include <iostream>
#include "ufo_functions.hpp"

int main() {
  greet();
  std::string codeword = "boston";
  std::string answer = "______";
  int misses = 0;
  std::vector<char> incorrect;
  bool guess = false;
  char letter;

  while(answer != codeword && misses < 7){
    display_misses(misses);
    display_status(incorrect, answer);
    std::cout << "\n\nPlease enter your guess: ";
    std::cin >> letter;
    for (int i = 0; i < codeword.length(); i++) {
      if (letter == codeword[i]) {
      answer[i] = letter;
      guess = false;

      }
    }
    if (guess) {

      std::cout << "\nCorrect! You're closer to cracking the codeword.\n";

    } else {

      std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
      incorrect.push_back(letter);
      misses++;
        }

  }


  if(answer == codeword){
    std::cout <<"Hooray! You saved the person and earned a medal of honor!\n";
  }else {
    std::cout << "Oh no! The UFO just flew away with another person!\n";
  }

end_game(answer, codeword);
}
