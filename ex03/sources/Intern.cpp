/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:28:23 by agan              #+#    #+#             */
/*   Updated: 2024/05/31 13:28:25 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

// Default constructor
Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

// Destructor
Intern::~Intern() 
{
	std::cout << "Intern destructor called" << std::endl;
}

// Copy constructor
Intern::Intern(const Intern &copy)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = copy;
}

// Copy assignment operator overload
Intern &Intern::operator=(const Intern &copy)
{
	if (this == &copy)
		return *this;
	std::cout << "Intern copy assignment operator called" << std::endl;
	return *this;
}

AForm *Intern::createPresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::createRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::createShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

const char *Intern::invalidFormException::what() const throw()
{
	return "invalid form name";
}


AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string form_names[] = {
		"PresidentialPardonForm", 
		"RobotomyRequestForm", 
		"ShrubberyCreationForm"};

	AForm *(Intern::*create_forms[])(std::string) = {
		&Intern::createPresidential,
		&Intern::createRobotomy,
		&Intern::createShrubbery
	};

	for (int i = 0; i < FORM_COUNT; i++)
	{
		if (name == form_names[i])
		{
			std::cout << GREEN << "Intern created " << name << RESET << std::endl;
            return (this->*create_forms[i])(target);
		}
	}
	throw invalidFormException();
}
