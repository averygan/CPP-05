/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:00:51 by agan              #+#    #+#             */
/*   Updated: 2024/05/23 19:00:52 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <string>

# define BROWN "\033[1;33m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define BLUE	"\033[1;34m"
# define CYAN	"\033[1;36m"
# define RESET "\033[0m"

# define BROWN_R "\033[33m"
# define RED_R "\033[31m"
# define GREEN_R "\033[32m"
# define BLUE_R	"\033[34m"
# define CYAN_R	"\033[36m"

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	// Contructors and destructors
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &copy);

	// Overload assignment operator
	Bureaucrat &operator=(const Bureaucrat &copy);

	// Getters
	const std::string getName() const;
	int getGrade() const;

	// Increment
	void increment();

	// Decrement
	void decrement();

	// Exception classes
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	// Member functions
	void signForm();
};

// Insertion overload
std::ostream &operator<<(std::ostream &os, const Bureaucrat &val);

#endif
