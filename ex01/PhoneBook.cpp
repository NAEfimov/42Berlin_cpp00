/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:58:47 by nefimov           #+#    #+#             */
/*   Updated: 2025/12/11 14:06:49 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() : num(0) {}

PhoneBook::~PhoneBook() {}

void PhoneBook::add_contact(Contact cont) {
	contacts_list[num % MAX_CONTACTS] = cont;
	++num;
}

void PhoneBook::display_contacts() {
	int	max;
	std::string	field;

	if (num <= MAX_CONTACTS)
		max = num;
	else
		max = MAX_CONTACTS;
	
	std::cout << std::endl;
	std::cout << std::setw(CL_WIDTH) << "Index" << "|";
	std::cout << std::setw(CL_WIDTH) << "First name" << "|";
	std::cout << std::setw(CL_WIDTH) << "Last name" << "|";
	std::cout << std::setw(CL_WIDTH) << "Nickname" << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
		
	for (int i = 0; i < max; ++i) {
		std::cout << std::setw(CL_WIDTH)
				  << (i + 1)
				  << "|";
		
		std::cout << std::setw(CL_WIDTH)
				  << get_format_field(contacts_list[i].get_first_name())
				  << "|";
		
		std::cout << std::setw(CL_WIDTH)
				  << get_format_field(contacts_list[i].get_last_name())
				  << "|";
		
		std::cout << std::setw(CL_WIDTH)
				  << get_format_field(contacts_list[i].get_nickname())
				  << std::endl;
	}
	std::cout << std::endl;
}

void PhoneBook::display_contact(int idx) {
	if (idx < 0 || idx >= MAX_CONTACTS)
		return ;
	contacts_list[idx].print();
}

int	PhoneBook::get_num() {
	return (num);
}

std::string	PhoneBook::get_format_field(std::string const src) const {
	std::string	field = src;
	if (field.length() > CL_WIDTH) {
		field.resize(CL_WIDTH);
		field[CL_WIDTH - 1] = '.';
	}
	return (field);
}
