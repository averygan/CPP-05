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

void print_test(std::string string)
{
	std::cout << std::endl << string << std::endl;
	for (int i = 0; i < 30; i++)
		std::cout << "-";
	std::cout << std::endl;
}

void try_catch_tester(Bureaucrat &bureaucrat, int increment)
{
	if (increment)
	{
		try
		{
			bureaucrat.increment();
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;			
		}
	}
	else
	{
		try
		{
			bureaucrat.decrement();
		}
		catch (std::exception &e)
		{
			std::cout << RED << e.what() << RESET << std::endl;			
		}
	}
	std::cout << bureaucrat << std::endl;
}

int main(void)
{
	print_test("TESTING EXCEPTIONS");
	// catching grade too low
	try
	{
		Bureaucrat bureaucrat("regular bureaucrat", 151);
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	// catching grade too high
	try
	{
		Bureaucrat bureaucrat("regular bureaucrat", -2);
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	print_test("CREATING BUREAUCRATS FOR TESTING");
	Bureaucrat bureaucrat1("bureaucrat1", 120);
	Bureaucrat bureaucrat2("bureaucrat2", 1);
	Bureaucrat bureaucrat3("bureaucrat3", 150);

	std::cout << bureaucrat1 << std::endl;
	std::cout << bureaucrat2 << std::endl;
	std::cout << bureaucrat3 << std::endl;

	print_test("INCREMENTING EACH BUREAUCRAT");
	try_catch_tester(bureaucrat1, 1);
	try_catch_tester(bureaucrat2, 1);
	try_catch_tester(bureaucrat3, 1);

	print_test("DECREMENTING EACH BUREAUCRAT");
	try_catch_tester(bureaucrat1, 0);
	try_catch_tester(bureaucrat2, 0);
	try_catch_tester(bureaucrat3, 0);
	try_catch_tester(bureaucrat3, 0);

	print_test("END OF TESTS");
}