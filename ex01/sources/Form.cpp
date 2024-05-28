/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:25:18 by agan              #+#    #+#             */
/*   Updated: 2024/05/24 22:25:19 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Constructor
Form::Form() : name("No-name"), is_signed(false), grade_sign(150), grade_exec(150) 
{
	std::cout << "Form " << this->name << " created with grade_sign " << \
	this->grade_sign << ", grade_exec " << this->grade_exec << std::endl;
}

// Parameterized constructor
Form::Form(std::string name, int g_sign, int g_exec) : name(name), is_signed(false), \
	grade_sign(g_sign), grade_exec(g_exec)
{
	if (this->grade_sign < HIGHEST_GRADE || this->grade_exec < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (this->grade_sign > LOWEST_GRADE || this->grade_exec > LOWEST_GRADE)
		throw GradeTooLowException();
	else
	{
		std::cout << "Form " << this->name << " created with grade_sign " << \
		this->grade_sign << ", grade_exec " << this->grade_exec << std::endl;
	}
}

Form::Form(const Form &copy) : name(copy.name), \
	grade_sign(copy.grade_sign), grade_exec(copy.grade_exec)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = copy;
}

// Overload operator
Form &Form::operator=(const Form &copy)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	this->is_signed = copy.is_signed;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;	
}

// Getters
const std::string	Form::getName() const
{
	return this->name;
}

bool	Form::getSigned() const
{
	return this->is_signed;
}

int	Form::getGradeSign() const
{
	return this->grade_sign;
}

int	Form::getGradeExec() const
{
	return this->grade_exec;
}

// Member function
void	Form::beSigned(Bureaucrat const &obj)
{
	if (obj.getGrade() <= this->grade_sign)
	{
		this->is_signed = true;
		std::cout << GREEN << this->name << " has been signed by " << obj.getName() 
			<< RESET << std::endl;
	}
	else
	{
		// std::cout << RED << this->name << " unable to sign " << obj.getName() 
		// 	<< RESET << std::endl;
		throw GradeTooLowException();
	}

}

const char *Form::GradeTooHighException::what() const throw()
{
	return "exception: grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "exception: grade too low";	
}

std::ostream &operator <<(std::ostream &os, const Form &obj)
{
	os << CYAN << "Form " << obj.getName() << \
		" (sign grade: " << obj.getGradeSign() << \
		", exec grade: " << obj.getGradeExec() << ")";
	os << (obj.getSigned() ? " is signed." : " has not been signed.") << RESET;
	return os;
}
