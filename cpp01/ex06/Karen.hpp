#ifndef KAREN_HPP
#define KAREN_HPP

#include <string>

class Karen
{
public:
	Karen();
	~Karen();

	void	complain(std::string level);
	void	filter(std::string level);

private:
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
	
};

#endif // !KAREN_HPP
