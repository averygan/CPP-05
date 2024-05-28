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

#include "Bureaucrat.hpp"
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

int main(void)
{
	// create test forms and bureaucrats
	print_test("CREATING FORMS");
	PresidentialPardonForm presidentialPardonForm("Arthur");
	RobotomyRequestForm RobotomyRequestForm("Marvin");
	ShrubberyCreationForm ShrubberyCreationForm("yard");

	print_test("CREATING BUREAUCRATS");
	Bureaucrat secret_agent("secret_agent", 1);
	Bureaucrat mid_agent("mid_agent", 46);
	Bureaucrat average_joe("average_joe", 146);

	/* Presidential 25, 5
	Robotomy 72, 45
	Shrubbery 145, 137 */
	print_test("TESTING FAILED SIGNS");
	mid_agent.signForm(presidentialPardonForm);
	average_joe.signForm(RobotomyRequestForm);
	average_joe.signForm(ShrubberyCreationForm);

	print_test("TESTING FAILED EXECS DUE TO UNSIGNED");
	secret_agent.executeForm(presidentialPardonForm);
	mid_agent.executeForm(RobotomyRequestForm);
	secret_agent.executeForm(ShrubberyCreationForm);

	print_test("TESTING SUCCESSFUL SIGNS");
	secret_agent.signForm(presidentialPardonForm);
	mid_agent.signForm(RobotomyRequestForm);
	mid_agent.signForm(ShrubberyCreationForm);

	print_test("TESTING FAILED EXECS DUE TO GRADE");
	mid_agent.executeForm(RobotomyRequestForm);
	average_joe.executeForm(ShrubberyCreationForm);
	mid_agent.executeForm(presidentialPardonForm);

	print_test("TESTING SUCCESSFUL EXECS");
	secret_agent.executeForm(presidentialPardonForm);
	secret_agent.executeForm(RobotomyRequestForm);
	mid_agent.executeForm(ShrubberyCreationForm);

	print_test("END OF TESTS");
}
