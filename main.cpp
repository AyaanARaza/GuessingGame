#include <iostream>
#include <cmath>

int main() {
  srand(time(NULL));
  std::cout << "Welcome to Guess the number\n";
  std::cout << "Easy, Medium, Hard (e, m, h)\n";
  std::string diff;
  std::cin >> diff;
  std::string diffs[3] = {"h", "m", "e"};
  int attmps = 0;
  for (int i = 0; i < 3; i++) {
    if (diff == diffs[i]) {
      attmps = i + 3;
      break;
    }
  }
  if (attmps != 0) {
    std::cout << std::to_string(attmps) + " attempts\n";
    std::cout << "Picking a random number from 1-10\n";
    int number = (rand() % 10) + 1;
    std::cout << "Got it!\n";
    bool correctly = false;
    for (int i = 0; i < attmps; i++) {
      std::cout << "Pick a number\n";
      int choice = 0;
      try {
        std::string choice_str;
        std::cin >> choice_str;
        choice = std::stoi(choice_str);
      } catch (const std::exception E) {
        std::cout << "Invalid Input | You lost your turn\n";
      }
      if (number == choice) {
        std::cout << "Guessed Correctly\n";
        std::cout << "The number was ";
        std::cout << number;
        std::cout << "\n";
        correctly = true;
        break;
      } else if (choice > 10 or choice < 1){
        std::cout << "The number should be from 1-10\n";
      } 
      else{
        std::cout << "Incorrect!\n";
        int difference = abs(number-choice);
        if (difference == 1){
          std::cout << "Very Hot\n";
        } else if (difference == 2 or difference == 3){
          std::cout << "Hot\n";
        } else if (difference == 4) {
          std::cout << "Lukewarm\n";
        } else if (difference == 9){
          std::cout << "Colder than the Arctic\n";
        } else {
          std::cout << "Cold\n";
        }
      }
    }
    if (not(correctly)) {
      std::cout << "The number was ";
      std::cout << number;
      std::cout << "\n";
    }
  } else {
    std::cout << "Invalid Input | Try Again\n";
  }
}