/* Libraries Standards of Work. */
#include <iostream>
#include <map>

/* Symbolic Working Constants. */
#define	V_ONE		1

#define V_AT_SIGN	'\x40'
#define V_POUND_SIGN	'\x23'
#define	V_QUESTION_MARK	'\x3f'
#define	V_UNDERSCORE	'\x5f'

/* Function that validates that a string of characters matches in format with another string of characters. */
bool matchingEntry(const std::string& inputStr, const std::string& modelStr)
{
	if (inputStr.length() == modelStr.length())
	{
		/* Key-value structure that receives a character and has a function pointer as its value. */
		static const std::map<char, int(*)(int)> map_validators
		{
			{V_AT_SIGN,		std::isalpha},
			{V_POUND_SIGN,		std::isdigit},
			{V_UNDERSCORE,		std::isspace},
			{V_QUESTION_MARK,	[](int) {return V_ONE;} }
		};

		return std::equal(inputStr.cbegin(), inputStr.cend(), modelStr.cbegin(), modelStr.cend(),
				[](const char& inputChr, const char& modelChr) -> bool
				{
					if (const std::map<char, int(*)(int)>::const_iterator itc_map_found{map_validators.find(modelChr)}; itc_map_found != map_validators.cend())
					{
						return (*itc_map_found->second)(inputChr);
					}
					else
					{
						return (inputChr == modelChr);
					}
				}
			);
	}

	return false;
}

//Main function.
int main()
{
	std::cout << "Phone number checker." << std::endl;

	const std::string strEntryFormat{"(###) ###-####"};
	std::string strPhoneNumber{};

	std::cout << std::endl << "Enter a Phone Number in the following format:" << std::endl;
	std::cout << strEntryFormat << std::endl;

	std::cout << "+ Phone Number: ";
	std::getline(std::cin >> std::ws, strPhoneNumber);

	if (matchingEntry(strPhoneNumber, strEntryFormat))
		std::cout << std::endl << "+ Number: " << strPhoneNumber << " OK!" << std::endl;
	else
		std::cerr << std::endl << "- Number: " << strPhoneNumber << " FAIL!" << std::endl;

	std::cout << std::endl << "Telephone Number Reviewer." << std::endl;
	std::cout << "> It has been written: " << strPhoneNumber << std::endl;

	return EXIT_SUCCESS;
}
