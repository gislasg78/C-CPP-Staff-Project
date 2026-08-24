#include <algorithm>
#include <iostream>
#include <list>
#include <memory>

class A {};

int main()
{
	std::list<std::unique_ptr<A>> my_List;
	std::unique_ptr u_ptr_a {std::make_unique<A>()};
	std::unique_ptr u_ptr_b {std::make_unique<A>()};

	A* p_target = u_ptr_b.get();

	my_List.push_back(std::move(u_ptr_a));
	my_List.push_back(std::move(u_ptr_b));

	std::cout << "List & Smart Pointers Example." << std::endl;
	std::cout << "+ Size: [" << my_List.size() << "]." << std::endl;

	std::list<std::unique_ptr<A>>::const_iterator itc_list = std::find_if(my_List.cbegin(), my_List.cend(),
		[p_target](const std::unique_ptr<A>& u_ptr)
			{return u_ptr.get() == p_target;}
		);

	if (itc_list != my_List.cend()) itc_list = my_List.erase(itc_list);

	std::cout << "+ Size: [" << my_List.size() << "]." << std::endl;

	return EXIT_SUCCESS;
}
