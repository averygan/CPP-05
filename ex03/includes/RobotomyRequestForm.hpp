/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:23:44 by agan              #+#    #+#             */
/*   Updated: 2024/05/28 15:23:47 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include "AForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	const std::string target;

public:
	// Constructor
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);

	// Destructor
	~RobotomyRequestForm();

	// Overload operator
	RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

	// Member functions
	void beExecuted() const;
};

#endif
