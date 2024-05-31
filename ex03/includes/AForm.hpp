/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 22:25:09 by agan              #+#    #+#             */
/*   Updated: 2024/05/28 15:20:29 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AForm_HPP__
#define __AForm_HPP__

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

# define FORM_COUNT 3

class Bureaucrat;

class AForm
{
private:
	const std::string	name;
	bool				is_signed;
	const int			grade_sign;
	const int			grade_exec;

public:
	// Constructor
	AForm();
	AForm(std::string name, int g_sign, int g_exec);
	AForm(const AForm &copy);

	// Destructor
	virtual ~AForm();

	// Overload operator
	AForm &operator=(const AForm &copy);

	// Exception classes
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class ExecutionUnsignedException : public std::exception
	{
		virtual const char *what() const throw();
	};

	// Getters
	const std::string	getName() const;
	bool				getSigned() const;
	int					getGradeSign() const;
	int					getGradeExec() const;

	// Member function
	void	beSigned(Bureaucrat const &obj);
	void	execute(Bureaucrat const & executor) const;

	// Pure virtual function
	virtual void	beExecuted() const = 0;
};

// Insertion stream overload
std::ostream &operator <<(std::ostream &os, const AForm &obj);

#endif
