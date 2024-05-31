/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:24:04 by agan              #+#    #+#             */
/*   Updated: 2024/05/28 15:24:05 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), \
	target("unknown target")
{
	std::cout << this->getName() << \
		" created (grade_sign " << this->getGradeSign() << \
		", grade_exec " << this->getGradeExec() << \
		", target " << this->target << ")" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), \
	target(target)
{
	std::cout << this->getName() << \
		" created (grade_sign " << this->getGradeSign() << \
		", grade_exec " << this->getGradeExec() << \
		", target " << this->target << ")" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : \
	AForm(copy), target(copy.target)
{
	std::cout << "Copy constructor: " << this->getName() << \
		" created (grade_sign " << this->getGradeSign() << \
		", grade_exec " << this->getGradeExec() << \
		", target " << this->target << ")" << std::endl;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

// Overload operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
{
	if (this != &copy)
	{
		this->AForm::operator=(copy);
	}
	return *this;
}

// Member functions
void ShrubberyCreationForm::beExecuted() const
{
	std::string file_name(this->target + "_shrubbery");
	std::ofstream outfile(file_name.c_str());

	if (!outfile.is_open())
	{
        std::cerr << "Error: Could not create or open file " \
        	<< this->target + "_shrubbery" << std::endl;
        return ;
	}

	std::cout << CYAN << \
		"Trees have been planted in " <<
		this->target << "_shrubbery"
		<< RESET << std::endl;

	outfile << \
	"               ,@@@@@@@,                    \n"
	"       ,,,.   ,@@@@@@/@@,  .oo8888o.        \n"
	"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o      \n"
	"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'   \n"
	"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'    \n"
	"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'     \n"
	"   `&%\\ ` /%&'    |.|        \\ '|8'       \n"
	"       |o|        | |         | |           \n"
	"       |.|        | |         | |           \n"
	"    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
	
	outfile.close();
}
