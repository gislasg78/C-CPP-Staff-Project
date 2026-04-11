#include <iostream>

#define V_ZERO  0
#define V_TEN   10

constexpr int MAXDIM = 4;

struct strct_my_struct
{
	int idx;
	char name[V_TEN];
	float salary;
} s_my_struct[] =
	{
		{0, "Yordi", 1000.0f},
		{1, "Bryan", 2000.0f},
		{2, "Kevin", 3000.0f},
		{3, "Britany", 4000.0f}
	},
 *p_s_my_struct = s_my_struct;

int main()
{
	const int max_dim = MAXDIM;
	decltype(max_dim) dim_max = MAXDIM;

	std::cout << "Exercises on structures and its pointers." << std::endl;

	std::cout << "Pointer." << std::endl;
	for (int i = V_ZERO; i < dim_max; i++)
	{
		std::cout << "Record #: " << i << std::endl;
		std::cout << "Idx:  [" << (p_s_my_struct + i)->idx << "] = [" << (*(p_s_my_struct + i)).idx << "]." << std::endl;
		std::cout << "Name: [" << p_s_my_struct[i].name << "] = [" << (p_s_my_struct + i)->name << "]" << std::endl;
		std::cout << "Wage: [" << (p_s_my_struct + i)->salary << "] = [" << p_s_my_struct[i].salary << "]." << std::endl << std::endl;
	}

	std::cout << "Structure." << std::endl;
	for (int i = V_ZERO; i < dim_max; i++)
	{
		std::cout << "Record #: " << i << std::endl;
		std::cout << "Idx:  [" << (s_my_struct + i)->idx << "] = [" << (*(s_my_struct + i)).idx << "]." << std::endl;
		std::cout << "Name: [" << (&s_my_struct[i])->name << "] = [" << (s_my_struct + i)->name << "]." << std::endl;
		std::cout << "Wage: [" << (s_my_struct + i)->salary << "] = [" << s_my_struct[i].salary << "]." << std::endl << std::endl;
	}

	return V_ZERO;
}
