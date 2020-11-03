#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <string>
#include "Weapon.hpp"

class HumanA
{

public:
	HumanA(std::string name, Weapon & weapon);
	~HumanA();
	void	attack(void) const;

private:
	std::string	_name;	
	Weapon&		_weapon;
	std::string toupperString(std::string str);
};

#endif // HUMAN_A_HPP
