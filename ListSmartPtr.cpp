#include <algorithm>
#include <iostream>
#include <list>
#include <memory>

class A {};

int main()
{
	std::list<std::unique_ptr<A>> my_List;
	std::unique_ptr a = std::make_unique<A>();
	std::unique_ptr b = std::make_unique<A>();

	A* target = b.get();

	my_List.push_back(std::move(a));
	my_List.push_back(std::move(b));

	std::cout << "List & Smart Pointers Example." << std::endl;
	std::cout << "+ Size: [" << my_List.size() << "]." << std::endl;

	std::list<std::unique_ptr<A>>::iterator it_list = std::find_if(my_List.begin(), my_List.end(),
		[target](const std::unique_ptr<A>& ptr)
			{return ptr.get() == target;}
		);

	if (it_list != my_List.end()) my_List.erase(it_list);

	std::cout << "+ Size: [" << my_List.size() << "]." << std::endl;
}
