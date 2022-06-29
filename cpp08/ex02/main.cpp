#include "MutantStack.hpp"
#include <iostream>
#include <stack>

int main()
{
	MutantStack<int> s;

	s.push(0);
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(42);

	std::cout << "top: " << s.top() << std::endl;
	std::cout << "size: " << s.size() << std::endl;
	std::cout << std::endl;

	std::cout << "test pop" << std::endl;
	{
		s.pop();

		std::cout << "top: " << s.top() << std::endl;
		std::cout << "size: " << s.size() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "test copy" << std::endl;
	{
		MutantStack<int> copy(s);

		copy.pop();
		std::cout << "copy.pop() after copy" << std::endl;
		std::cout << "origin: top(" << s.top() << "), size(" << s.size() << ")" << std::endl;
		std::cout << "copy: top(" << copy.top() << "), size(" << copy.size() << ")" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "test iterator" << std::endl;
	{
		MutantStack<int>::iterator iter, end;

		iter = s.begin();
		end = s.end();
		while (iter != end)
		{
			std::cout << *iter << " ";
			iter++;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "test reverse iterator" << std::endl;
	{
		MutantStack<int>::reverse_iterator iter, end;

		iter = s.rbegin();
		end = s.rend();
		while (iter != end)
		{
			std::cout << *iter << " ";
			iter++;
		}
		std::cout << std::endl;
	}

	return (0);
}
