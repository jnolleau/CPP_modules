#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{

public:
	Weapon(std::string type);
	~Weapon();
	const std::string&	getType(void) const;
	void				setType(std::string type);

private:
	std::string	_type;
	std::string toupperString(std::string str);

};

#endif // WEAPON_HPP
