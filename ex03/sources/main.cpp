/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:00:43 by agan              #+#    #+#             */
/*   Updated: 2024/05/28 15:19:43 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void print_test(std::string string)
{
	std::cout << std::endl << string << std::endl;
	for (int i = 0; i < 30; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void createForm(Intern &intern, std::string name, std::string target)
{
	AForm *form_ptr;

	form_ptr = NULL;
	try
	{
		form_ptr = intern.makeForm(name, target);
		delete (form_ptr);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Intern unable to create form due to invalid form name" << \
			RESET << std::endl;
	}
	return (NULL);
}

int main(void)
{
	// Create Intern
	print_test("CREATE INTERN");
	Intern eadaz;

	print_test("MAKING VALID FORMS");
	createForm(eadaz, "PresidentialPardonForm", "Loth");
	createForm(eadaz, "RobotomyRequestForm", "Kalyba");
	createForm(eadaz, "ShrubberyCreationForm", "Sabran");

	print_test("MAKING INVALID FORMS");
	createForm(eadaz, "Pres Form", "Loth");
	createForm(eadaz, "Robo Form", "Kalyba");
	createForm(eadaz, "Shrub Form", "Sabran");

	print_test("END OF TESTS");
}
