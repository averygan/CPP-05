/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:00:55 by agan              #+#    #+#             */
/*   Updated: 2024/05/23 19:00:56 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("Nameless"), grade(150) 
{
	std::cout << this->name << " created with grade: " << this->grade 
		<< std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(150)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
	{
		this->grade = grade;
		std::cout << this->name << " created with grade: " << this->grade 
		<< std::endl;
	}
}

// Destructor
Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}


// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = copy;
}

// Copy assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	this->grade = copy.grade;
	return *this;
}

// Getters
const std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

// Increment
void Bureaucrat::increment()
{
	// if grade too high
	if (this->grade - 1 < 1)
		throw GradeTooHighException();
	else
	{
		std::cout << "grade of " << this->name << " incremented" << std::endl;;
		this->grade -= 1;
	}
}

// Decrement
void Bureaucrat::decrement()
{
	// if grade too low
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	else 
	{
		std::cout << "grade of " << this->name << " decremented" << std::endl;
		this->grade += 1;
	}
}

// Exception implementations
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "exception: grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "exception: grade too low";
}

// Output stream operator
std::ostream &operator <<(std::ostream &os, const Bureaucrat &obj)
{
	os << CYAN << "bureaucrat: " << obj.getName() << 
		" (grade: " << obj.getGrade() << ")" << RESET;
	return os;
}
