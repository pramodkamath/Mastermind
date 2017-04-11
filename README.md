# Mastermind
A single player version of the mastermind game implemented in C++ on linux.
Steps to Run Game:

On Ubuntu 64-bit:
- Extract Mastermind.tar.gz
- Open Mastermind/Release in the terminal
- Run the game using ./Mastermind

To compile on other machines:
- Extract Mastermind.tar.gz
- Go to Mastermind/src
- Run the following commands

$ g++ -c -std=c++11  ./*.cpp

$ g++ -o "Mastermind"  ./*.o

$ ./Mastermind

Playing the game:

- Enter the number of guesses needed to crack the code. Officially, Mastermind allows 8 guesses to crack the code. Maximum can be 12.
- Enter the guesses as a combination of the first letters of the choices available. eg: RGYB, CYMM etc.
- Check the feedback for the guesses and try to crack the code.

Good Luck!
