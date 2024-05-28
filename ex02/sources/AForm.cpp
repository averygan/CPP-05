/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:25:18 by agan              #+#    #+#             */
/*   Updated: 2024/05/28 15:19:31 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// Constructor
AForm::AForm() : name("No-name"), is_signed(false), grade_sign(150), grade_exec(150) 
{
	std::cout << "AForm " << this->getName() << \
		" created (grade_sign " << this->getGradeSign() << \
		", grade_exec " << this->getGradeExec() << ")" << std::endl;
}

// Parameterized constructor
AForm::AForm(std::string name, int g_sign, int g_exec) : name(name), is_signed(false), \
	grade_sign(g_sign), grade_exec(g_exec)
{
	if (this->grade_sign < HIGHEST_GRADE || this->grade_exec < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (this->grade_sign > LOWEST_GRADE || this->grade_exec > LOWEST_GRADE)
		throw GradeTooLowException();
	else
	{
		std::cout << "AForm " << this->getName() << \
			" created (grade_sign " << this->getGradeSign() << \
			", grade_exec " << this->getGradeExec() << ")" << std::endl;
	}
}

AForm::AForm(const AForm &copy) : name(copy.name), \
	grade_sign(copy.grade_sign), grade_exec(copy.grade_exec)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = copy;
}

// Overload operator
AForm &AForm::operator=(const AForm &copy)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	this->is_signed = copy.is_signed;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;	
}

// Getters
const std::string	AForm::getName() const
{
	return this->name;
}

bool	AForm::getSigned() const
{
	return this->is_signed;
}

int	AForm::getGradeSign() const
{
	return this->grade_sign;
}

int	AForm::getGradeExec() const
{
	return this->grade_exec;
}

// Member function
void	AForm::beSigned(Bureaucrat const &obj)
{
	if (obj.getGrade() <= this->grade_sign)
	{
		this->is_signed = true;
		std::cout << GREEN << this->name << " has been signed by " << obj.getName() 
			<< RESET << std::endl;
	}
	else
	{
		throw GradeTooLowException();
	}

}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";	
}

const char *AForm::ExecutionUnsignedException::what() const throw()
{
	return "form has not been signed";
}

std::ostream &operator <<(std::ostream &os, const AForm &obj)
{
	os << CYAN << "AForm " << obj.getName() << \
		" (sign grade: " << obj.getGradeSign() << \
		", exec grade: " << obj.getGradeExec() << ")";
	os << (obj.getSigned() ? " is signed." : " has not been signed.") << RESET;
	return os;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->is_signed == false)
		throw ExecutionUnsignedException();
	else if (executor.getGrade() > this->grade_exec)
		throw GradeTooLowException();
	else
	{
		std::cout << GREEN << this->name << " has been executed by " 
			<< executor.getName() << RESET << std::endl;
		this->beExecuted();
	}
}
