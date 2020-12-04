/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:28:45 by julnolle          #+#    #+#             */
/*   Updated: 2020/12/04 19:28:21 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <sstream>

Convert::Convert(const char *value) : _value(std::string(value))
{
	this->_charVal = '*';
	this->_intVal = 0;
	this->_floatVal = 0;
	this->_doubleVal = 0;
	this->_charStr = "impossible";
	this->_intStr = "impossible";
	this->_floatStr = "nanf";
	this->_doubleStr = "nan";

}

Convert::Convert(Convert const & copy) :  _value(copy._value)
{
	*this = copy;
}

Convert::~Convert(void)
{
	return;
}

// Convert & Convert::operator=(Convert const & rhs)
// {

// }

bool	Convert::_parseString(void)
{

	return (true);
}

bool	Convert::_isInt(std::string str)
{
	int	i = 0;
	
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	Convert::_isChar(std::string str)
{
	if (str.size() == 1)
	{
		if (std::isalpha(str[0]))
			return (true);
	}
	return (false);
}

bool	Convert::_isDouble(std::string str)
{
	int	i = 0;
	int	count = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!std::isdigit(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.')
			count++;
		i++;
	}
	if (count == 1)
		return (true);
	return (false);
}

bool	Convert::_isFloat(std::string str)
{
	int	i = 0;
	int	count = 0;

	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (!std::isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			return (false);
		if (str[i] == '.')
			count++;
		i++;
	}
	if (count == 1 && str[i - 1] == 'f')
		return (true);
	return (false);
}

char	Convert::_detectType(void)
{
	// C'est moche ! Trouver un autre moyen que if/else if/else !?
	if (this->_isInt(this->_value))
	{
		this->_intVal = std::stoi(this->_value);
		return ('i');
	}
	else if (this->_isChar(this->_value))
	{
		this->_charVal = this->_value[0];
		return ('c');
	}
	else if (this->_isDouble(this->_value))
	{
		this->_intVal = std::stod(this->_value, NULL);
		return ('d');
	}
	else if (this->_isFloat(this->_value))
	{
		this->_intVal = std::stof(this->_value);
		return ('f');
	}
	else
		return ('n');
}

void	Convert::_convertFromInt(void)
{
	std::ostringstream o;
	std::ostringstream o1;
	std::ostringstream o2;
	std::ostringstream o3;

	if (!isprint(this->_intVal))
		this->_charStr = "Non displayable";
	else
	{
		this->_charVal = static_cast<char>(this->_intVal);;
		o3 << "'" << this->_charVal << "'";
		this->_charStr = o3.str();
	}

	o << this->_intVal;
	this->_intStr = o.str();

	this->_floatVal = static_cast<float>(this->_intVal);
	o1 << this->_floatVal << ".0f";
	this->_floatStr = o1.str();

	this->_doubleVal = static_cast<double>(this->_intVal);
	o2 << this->_doubleVal << ".0";
	this->_doubleStr = o2.str();
}

void	Convert::_convertFromChar(void)
{

}

void	Convert::_convertFromDouble(void)
{

}

void	Convert::_convertFromFloat(void)
{

}

void	Convert::doConversion(void)
{
	char type;
	void *res;
	static char const types[4] = {'i', 'c', 'd', 'f'};
	void (Convert::*conv[4])(void) = {&Convert::_convertFromInt, &Convert::_convertFromChar, &Convert::_convertFromDouble, &Convert::_convertFromFloat};
 
	type = this->_detectType();
	this->_convertFromInt();

	for (int i = 0; i < 4; ++i)
	{
		if (type == types[i])
			(this->*conv[i])();
	}

	std::cout << "type: " << type << std:: endl;
	std::cout << "char: " << this->_charStr << std:: endl;
	std::cout << "int: " << this->_intStr << std:: endl;
	std::cout << "float: " << this->_floatStr << std:: endl;
	std::cout << "double: " << this->_doubleStr << std:: endl;

	return;
}
