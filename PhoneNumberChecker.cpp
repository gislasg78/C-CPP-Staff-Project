#include <iostream>
#include <map>

#define	V_ONE		1

#define V_AT_SIGN	'\x40'
#define V_POUND_SIGN	'\x23'
#define	V_QUESTION_MARK	'\x3f'
#define	V_UNDERSCORE	'\x5f'

bool matchingEntry(const std::string& inputStr, const std::string& modelStr)
{
	if (inputStr.length() != modelStr.length())
	{
		return false;
	};

	static const std::map<char, int (*)(int)> map_validators
	{
		{V_POUND_SIGN, std::isdigit},
		{V_UNDERSCORE, std::isspace},
		{V_AT_SIGN, std::isalpha},
		{V_QUESTION_MARK, [](int) {return V_ONE;} }
	};

	return std::equal(inputStr.cbegin(), inputStr.cend(), modelStr.cbegin(), modelStr.cend(),
			[](char chr, char mask_chr) -> bool
			{
				if (auto found{map_validators.find(mask_chr)}; found != map_validators.cend())
				{
					return (*found->second)(chr);
				}
				else
				{
					return (chr == mask_chr);
				}
			}
		);
}

int main()
{
	std::cout << "Phone number checker." << std::endl;

	const std::string strEntryFormat{"(###) ###-####"};
	std::string strPhoneNumber{};

	do
	{
		std::cout << std::endl << "Enter a Phone Number in the following format:" << std::endl;
		std::cout << strEntryFormat << std::endl;

		std::cout << "+ Phone Number: ";
		std::getline(std::cin >> std::ws, strPhoneNumber);
	}
	while (!matchingEntry(strPhoneNumber, strEntryFormat));

	std::cout << std::endl << "Telephone Number Reviewer." << std::endl;
	std::cout << "> It has been written: [" << strPhoneNumber << "]." << std::endl;

	return EXIT_SUCCESS;
}
