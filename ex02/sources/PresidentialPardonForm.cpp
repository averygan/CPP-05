/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:23:59 by agan              #+#    #+#             */
/*   Updated: 2024/05/28 15:24:00 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// Constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), \
	target("unknown target")
{
	std::cout << this->getName() << \
		" created with grade_sign " << this->getGradeSign() << \
		", grade_exec " << this->getGradeExec() << \
		", target " << this->target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), \
	target(target)
{
	std::cout << this->getName() << \
		" created (grade_sign " << this->getGradeSign() << \
		", grade_exec " << this->getGradeExec() << \
		", target " << this->target << ")" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : \
	AForm(copy), target(copy.target)
{
	std::cout << "Copy constructor: " << this->getName() << \
		" created (grade_sign " << this->getGradeSign() << \
		", grade_exec " << this->getGradeExec() << \
		", target " << this->target << ")" << std::endl;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

// Overload operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	if (this != &copy)
	{
		this->AForm::operator=(copy);
	}
	return *this;
}

// Member functions
void PresidentialPardonForm::beExecuted() const
{
	std::cout << CYAN << \
		"Execution: " << this->target \
		<< " has been pardoned by Zaphod Beeblebrox" \
		<< RESET << std::endl;
}

