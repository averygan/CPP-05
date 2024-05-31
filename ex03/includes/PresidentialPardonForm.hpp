/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:23:53 by agan              #+#    #+#             */
/*   Updated: 2024/05/28 15:23:54 by agan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_HPP__
#define __PRESIDENTIALPARDONFORM_HPP__

#include "AForm.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public AForm
{
private:
	const std::string target;

public:
	// Constructor
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);

	// Destructor
	~PresidentialPardonForm();

	// Overload operator
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

	// Member functions
	void beExecuted() const;
};

#endif
