/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:23:38 by agan              #+#    #+#             */
/*   Updated: 2024/05/28 15:23:39 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	const std::string target;

public:
	// Constructor
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);

	// Destructor
	~ShrubberyCreationForm();

	// Overload operator
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

	// Member functions
	void beExecuted() const;
};

#endif