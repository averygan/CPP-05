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

int main(void)
{
	// catching grade too high
	try
	{
		Bureaucrat bureaucrat("regular bureaucrat", 151);
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	// catching grade too low
	try
	{
		Bureaucrat bureaucrat("regular bureaucrat", -2);
	}
	catch(std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	Bureaucrat bureaucrat2("bureaucrat2", 120);
	std::cout << bureaucrat2 << std::endl;

	// Testing increment
	bureaucrat2.increment();
	std::cout << bureaucrat2 << std::endl;

	// Testing decrement
	bureaucrat2.decrement();
	std::cout << bureaucrat2 << std::endl;

	// Testing decrement exception
	Bureaucrat bureaucrat3("bureaucrat3", 150);
	try
	{
		bureaucrat2.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}