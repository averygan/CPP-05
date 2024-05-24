/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:25:09 by agan              #+#    #+#             */
/*   Updated: 2024/05/24 22:25:10 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>
#include <string>

class Form
{
private:
	const std::string	name;
	bool				signed;
	const int			grade_sign;
	const int			grade_exec;

public:
	// Constructor
	Form();
	Form(const Form &copy);

	// Destructor
	~Form();

	// Overload operator
	Form &operator=(const Form &copy);

	// Exception classes
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	}

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	}

	// Getters
	const std::string	getName();
	bool				getSigned();
	const int			getGradeSign();
	const int			getGradeExec();

	// Member function
	void	beSigned(&Bureaucrat const obj)
};

// Insertion stream overload
std::ostream &operator<<(std::ostream os, const Form &val);

#endif
