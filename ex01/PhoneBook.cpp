/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:58:47 by nefimov           #+#    #+#             */
/*   Updated: 2025/09/23 18:52:41 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define	CL_WIDTH 10

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : num(0) {
	// std::cout << "PhoneBook default constructor called" << "\n";
}

PhoneBook::~PhoneBook() {
	// std::cout << "PhoneBook destructor called" << "\n";
}

void	PhoneBook::add_contact(Contact cont) {
	contacts_list[num % MAX_CONTACTS] = cont;
	++num;
}

void	PhoneBook::display_contacts() {
	int	max;
	std::string	field;

	if (num <= MAX_CONTACTS)
		max = num;
	else
		max = MAX_CONTACTS;
		
	for (int i = 0; i < max; ++i) {
		std::cout << std::setw(CL_WIDTH) << (i + 1) << "|";
		
		field = contacts_list[i].get_first_name();
		if (field.length() > CL_WIDTH) {
			field.resize(CL_WIDTH);
			field[CL_WIDTH - 1] = '.';
		}
		std::cout << std::setw(CL_WIDTH) << field << "|";
		
		field = contacts_list[i].get_last_name();
		if (field.length() > CL_WIDTH) {
			field.resize(CL_WIDTH);
			field[CL_WIDTH - 1] = '.';
		}
		std::cout << std::setw(CL_WIDTH) << field << "|";
		
		field = contacts_list[i].get_nickname();
		if (field.length() > CL_WIDTH) {
			field.resize(CL_WIDTH);
			field[CL_WIDTH - 1] = '.';
		}
		std::cout << std::setw(CL_WIDTH) << field << "\n";
	}
}

void	PhoneBook::display_contact(int i) {
	std::cout << contacts_list[i].get_first_name() << std::endl;
	std::cout << contacts_list[i].get_last_name() << std::endl;
	std::cout << contacts_list[i].get_nickname() << std::endl;
	std::cout << contacts_list[i].get_phone_number() << std::endl;
	std::cout << contacts_list[i].get_darkest_secret() << std::endl;
}