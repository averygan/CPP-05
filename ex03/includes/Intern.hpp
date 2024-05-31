/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:28:32 by agan              #+#    #+#             */
/*   Updated: 2024/05/31 13:28:33 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:
	// Constructors
	Intern();
	Intern(const Intern &copy);

	// Destructor
	~Intern();

	// Overload operator
	Intern &operator=(const Intern &copy);

	// Member functions
	AForm *makeForm(std::string name, std::string target);

	// Exception 
	class invalidFormException : public std::exception
	{
		virtual const char *what() const throw();
	};
private: 	
	AForm *createPresidential(std::string target);
	AForm *createRobotomy(std::string target);
	AForm *createShrubbery(std::string target);
};

#endif
