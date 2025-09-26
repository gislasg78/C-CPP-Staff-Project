#include <iostream>
#include <limits>
#include <sstream>

//Symbolic Macros.
#define RANDOM_GENERATOR(s)	((V_MULTIPLIER * (s) + V_INCREMENTER) % V_MODULUS)

//Work Numeric Symbolic Constants.
#define	V_INCREMENTER		13849
#define V_MODULUS		65536
#define V_MULTIPLIER		25173
#define V_RESIDUAL_MODULUS	65535

#define CARRIAGE_RETURN		'\n'

#define	V_FOUR			4
#define	V_MINUS_ONE		-1
#define	V_ONE			1
#define	V_NINE			9
#define	V_THREE			3
#define	V_TWO			2
#define	V_ZERO			0


std::string array_str_Characters[] = {"Computer", "User"};

struct strct_choices
	{
		char chr_key_choice;
		char chr_description_choice[V_NINE];
	} array_strct_choices[V_THREE] = {{'r', "Rock"}, {'p', "Paper"}, {'s', "Scissors"}};

const int size_of_strct_choices = sizeof(array_strct_choices) / sizeof(struct strct_choices);

struct strct_outcomes
	{
		char chr_key_user_choice;
		char chr_key_computer_choice;
		char chr_description_outcome[V_NINE];
	} array_strct_outcomes[V_NINE] = {
						{'r', 'r', "Tie"}, {'r', 'p', "Lose"}, {'r', 's', "Win"},
						{'p', 'r', "Win"}, {'p', 'p', "Tie"}, {'p', 's', "Lose"},
						{'s', 'r', "Lose"}, {'s', 'p', "Win"}, {'s', 's', "Tie"},
					};

const int size_of_strct_outcomes = sizeof(array_strct_outcomes) / sizeof(struct strct_outcomes);


struct strct_choices ChooseWinner(const struct strct_choices& strct_computer_choice, const struct strct_choices& strct_user_choice);
size_t GetComputerChoice(struct strct_choices *strct_own_choice, size_t *ptr_szt_random_seed);
void GetPause(std::string str_Message);
size_t GetRandomInterval(size_t szt_begin, size_t szt_end, size_t *ptr_szt_random_seed);
double GetRandomNumber(size_t *ptr_szt_random_seed);
size_t GetUserChoice(struct strct_choices *strct_own_choice);
struct strct_choices ObtainPlayerChoice(size_t szt_option, std::string str_Current_Player);


//Main function.
int main()
	{
		size_t szt_user_option = V_ZERO;
		size_t szt_random_seed = V_ZERO;
		struct strct_choices strct_computer_choice = {}, strct_user_choice = {};
		strct_choices strct_winner_choice = {};

		std::cout << "Rock, Paper & Scissors Computer Game." << std::endl;
		std::cout << "Enter a number for the random number generator seed: ";
		std::cin >> szt_random_seed;

		while (szt_user_option != V_FOUR)
			{
				szt_user_option = GetUserChoice(&strct_user_choice);

				if (szt_user_option != V_FOUR)
					{
						GetComputerChoice(&strct_computer_choice, &szt_random_seed);
						strct_winner_choice = ChooseWinner(strct_computer_choice, strct_user_choice);
					}
			}

		return V_ZERO;
	}

struct strct_choices ChooseWinner(const struct strct_choices& strct_computer_choice, const struct strct_choices& strct_user_choice)
	{
		struct strct_choices strct_own_choice {};

		std::cout << std::endl;
		std::cout << "+===|====+===|====+" << std::endl;
		std::cout << "|  Game Results.  |" << std::endl;
		std::cout << "+===|====+===|====+" << std::endl;
		std::cout << "| + Player:\t[" << array_str_Characters[V_ZERO] << "]." << std::endl;
		std::cout << "| + Option:\t[" << strct_computer_choice.chr_key_choice << "]." << std::endl;
		std::cout << "| + Concept:\t[" << strct_computer_choice.chr_description_choice << "]." << std::endl;
		std::cout << "+---+----+---+----+" << std::endl;
		std::cout << "| * Player:\t[" << array_str_Characters[V_ONE] << "]." << std::endl;
		std::cout << "| * Option:\t[" << strct_user_choice.chr_key_choice << "]." << std::endl;
		std::cout << "| * Concept:\t[" << strct_user_choice.chr_description_choice << "]." << std::endl;
		std::cout << "+---+----+---+----+" << std::endl;

		for (int int_idx = V_ZERO; int_idx < size_of_strct_outcomes; int_idx++)
			{
				if ((array_strct_outcomes[int_idx].chr_key_computer_choice == strct_computer_choice.chr_key_choice) &&
				    (array_strct_outcomes[int_idx].chr_key_user_choice == strct_user_choice.chr_key_choice))
					{
						std::cout << "| * Size:\t[" << size_of_strct_outcomes << "]." << std::endl;
						std::cout << "| * Index:\t[" << int_idx << "]." << std::endl;
						std::cout << "+---+----+---+----+" << std::endl;
						std::cout << "| * Computer:\t[" << array_strct_outcomes[int_idx].chr_key_computer_choice << "]." << std::endl; 
						std::cout << "| * User:\t[" << array_strct_outcomes[int_idx].chr_key_user_choice << "]." << std::endl;
						std::cout << "+---+----+---+----+" << std::endl;
						std::cout << "| * User:\t[" << array_strct_outcomes[int_idx].chr_description_outcome << "]." << std::endl;

						strct_own_choice = strct_user_choice;
						break;
					}
			}

		std::cout << "+===|====+===|====+" << std::endl;
		GetPause("Press the ENTER key to continue...");

		return strct_own_choice;
	}

size_t GetComputerChoice(struct strct_choices *strct_own_choice, size_t *ptr_szt_random_seed)
	{
		size_t szt_option = V_ZERO;

		szt_option = GetRandomInterval(V_ZERO, size_of_strct_choices + V_MINUS_ONE, ptr_szt_random_seed);

		if (szt_option >= V_ZERO && szt_option < size_of_strct_choices)
			*strct_own_choice = ObtainPlayerChoice(szt_option, array_str_Characters[V_ZERO]);

		return szt_option;
	}

void GetPause(std::string str_Message)
	{
		/* Pause before continuing. */
		std::cout << str_Message;
		std::cin.get();			// Wait for the user to press Enter.
		std::cin.clear();		// Clear the error state.
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), CARRIAGE_RETURN);	// Clear the buffer.
	}

size_t GetRandomInterval(size_t szt_begin, size_t szt_end, size_t *ptr_szt_random_seed)
	{
		return ((size_t) ((szt_end - szt_begin + V_ONE) * GetRandomNumber(ptr_szt_random_seed) + szt_begin));
	}

double GetRandomNumber(size_t *ptr_szt_random_seed)
	{
		return ((double) (*ptr_szt_random_seed = RANDOM_GENERATOR(*ptr_szt_random_seed)) / (double) V_RESIDUAL_MODULUS);
	}

size_t GetUserChoice(struct strct_choices *strct_own_choice)
	{
		size_t szt_option = V_ZERO;
		std::string str_option {};

		do
			{
				std::cout << std::endl;
				std::cout << "+===|====+===|====+===|====+===|" << std::endl;
				std::cout << "|   Rock-Paper-Scissors Game.  |" << std::endl;
				std::cout << "+===|====+===|====+===|====+===|" << std::endl;
				std::cout << "| Choose one of the following: |" << std::endl;
				std::cout << "+---|----+---|----+---|----+---|" << std::endl;
				std::cout << "| [1]. For 'Rock'.             |" << std::endl;
				std::cout << "| [2]. For 'Paper'.            |" << std::endl;
				std::cout << "| [3]. For 'Scissors'.         |" << std::endl;
				std::cout << "| [4]. Exit this program.      |" << std::endl;
				std::cout << "+===|====+===|====+===|====+===|" << std::endl;
				std::cout << "Enter your choice: ";

				std::getline(std::cin >> std::ws, str_option);
				std::stringstream(str_option) >> szt_option;

				std::cout << "The selected option was: ["<< szt_option << "]." << std::endl;
			}
		while (szt_option < V_ONE || szt_option > V_FOUR);

		GetPause("Press the ENTER key to continue...");

		if (szt_option >= V_ONE && szt_option <= V_THREE)
			*strct_own_choice = ObtainPlayerChoice(szt_option + V_MINUS_ONE, array_str_Characters[V_ONE]);

		return szt_option;
	}

struct strct_choices ObtainPlayerChoice(size_t szt_option, std::string str_Current_Player)
	{
		struct strct_choices strct_own_choice {};

		if (szt_option >= V_ZERO && szt_option <= (size_of_strct_choices + V_MINUS_ONE))
			{
				strct_own_choice = array_strct_choices[szt_option];

				std::cout << std::endl;
				std::cout << "+===|====+===|====+===|" << std::endl;
				std::cout << "|   Option selected.  |" << std::endl;
				std::cout << "+===|====+===|====+===|" << std::endl;
				std::cout << "| + Player:\t[" << str_Current_Player << "]." << std::endl;
				std::cout << "| + Choice:\t[" << szt_option + V_ONE << "]." << std::endl;
				std::cout << "+---+----+---+----+---+" << std::endl;
				std::cout << "| - Size:\t[" << size_of_strct_choices << "]." << std::endl;
				std::cout << "| - Index:\t[" << szt_option << "]." << std::endl;
				std::cout << "+---+----+---+----+---+" << std::endl;
				std::cout << "| - Value:\t[" << strct_own_choice.chr_key_choice << "]." << std::endl;
				std::cout << "| - Concept:\t[" << strct_own_choice.chr_description_choice << "]." << std::endl;
				std::cout << "+===|====+===|====+===|" << std::endl;
			}
		else
			std::cout << std::endl << "The option you selected: [" << szt_option << "] is incorrect. Please correct it!" << std::endl;

		GetPause("Press the ENTER key to continue...");

		return strct_own_choice;
	}
