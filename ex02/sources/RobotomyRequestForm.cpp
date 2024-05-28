/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:24:09 by agan              #+#    #+#             */
/*   Updated: 2024/05/28 15:24:10 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), \
	target("unknown target")
{
	std::cout << this->getName() << \
		" created (grade_sign " << this->getGradeSign() << \
		", grade_exec " << this->getGradeExec() << \
		", target " << this->target << ")" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), \
	target(target)
{
	std::cout << this->getName() << \
		" created (grade_sign " << this->getGradeSign() << \
		", grade_exec " << this->getGradeExec() << \
		", target " << this->target << ")" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : \
	AForm(copy), target(copy.target)
{
	std::cout << "Copy constructor: " << this->getName() << \
		" created (grade_sign " << this->getGradeSign() << \
		", grade_exec " << this->getGradeExec() << \
		", target " << this->target << ")" << std::endl;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

// Overload operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	if (this != &copy)
	{
		this->AForm::operator=(copy);
	}
	return *this;
}

// Member functions
void RobotomyRequestForm::beExecuted() const
{
	// Seeds the random number generator with the current time
	std::srand(std::time(0));

	std::cout << CYAN << "Robotomy in progress: Bzzzzzzzzzz" << RESET << std::endl;
	// Formatting
	for (int i = 0; i < 3; i++)
		std::cout << "." << std::endl;

	// Randomize robotomy success
	if (rand() % 2)
	{
		std::cout << BROWN << this->target << " has been successfully robotomized"
			<< RESET << std::endl;
	}
	else
	{
		std::cout << RED << "Robotomy on " << this->target << " has failed"
			<< RESET << std::endl;			
	}
}

