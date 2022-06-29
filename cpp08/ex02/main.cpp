#include "MutantStack.hpp"
#include <iostream>
#include <stack>

int main()
{
	{
		MutantStack<int> s;

		s.push(0);
		s.push(42);

		std::cout << "{ 0, 42 }" << std::endl;
		std::cout << "top: " << s.top() << std::endl;
		std::cout << "size: " << s.size() << std::endl;

		s.pop();
		std::cout << "pop" << std::endl;

		std::cout << "top: " << s.top() << std::endl;
		std::cout << "size: " << s.size() << std::endl;
		s.pop();
	}
	std::cout << std::endl;

	{
		MutantStack<int> s;
		s.push(42);

		MutantStack<int> copy(s);

		std::cout << "{ 42 }" << std::endl;
		std::cout << "origin: " << s.top() << std::endl;
		std::cout << "copy: " << copy.top() << std::endl;
	}
	std::cout << std::endl;

	{
		MutantStack<int> s;
		MutantStack<int>::iterator iter;
		MutantStack<int>::iterator end;

		s.push(42);
		s.push(1);

		std::cout << "{ 42, 1 }" << std::endl;
		iter = s.begin();
		end = s.end();
		std::cout << *iter++ << std::endl;
		std::cout << *iter++ << std::endl;
		std::cout << (iter == end ? "true" : "false") << std::endl;
	}

	return (0);
}
