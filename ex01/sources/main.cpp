/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 19:00:43 by agan              #+#    #+#             */
/*   Updated: 2024/05/23 19:00:43 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void print_test(std::string string)
{
	std::cout << std::endl << string << std::endl;
	for (int i = 0; i < 30; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void try_catch_tester(int grade, int grade2)
{
	try
	{
		Form form("test_form", grade, grade2);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	print_test("TESTING FORM EXCEPTIONS");
	// create form grade too high
	try_catch_tester(-1, 120);
	try_catch_tester(10, 0);

	// create form grade too low
	try_catch_tester(120, 500);
	try_catch_tester(1, 152);

	print_test("CREATING FORMS AND BUREAUCRATS");
	// create test forms and bureaucrats
	Form secret_form("secret_form", 1, 1);
	Form mid_form("mid_form", 100, 100);
	Form regular_form("regular_form", 150, 150);
	Bureaucrat secret_agent("secret_agent", 1);
	Bureaucrat mid_agent("mid_agent", 99);
	Bureaucrat average_joe("average_joe", 149);

	print_test("TESTING INSERTION OVERLOAD OPERATOR");
	std::cout << secret_form << std::endl;
	std::cout << mid_form << std::endl;
	std::cout << regular_form << std::endl;

	print_test("TESTING SIGNS BY SECRET AGENT: excepted all to be successful");
	secret_agent.signForm(secret_form);
	secret_agent.signForm(mid_form);
	secret_agent.signForm(regular_form);

	print_test("TESTING SIGNS BY MID AGENT: secret form to be unsuccessful");
	mid_agent.signForm(secret_form);
	mid_agent.signForm(mid_form);
	mid_agent.signForm(regular_form);

	print_test("TESTING SIGNS BY AVERAGE JOE: only regular form successful");
	average_joe.signForm(secret_form);
	average_joe.signForm(mid_form);
	average_joe.signForm(regular_form);

	print_test("END OF TESTS");
}
