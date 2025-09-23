/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapb.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:03:12 by nefimov           #+#    #+#             */
/*   Updated: 2025/09/23 21:07:20 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

#define ADD "ADD"
#define EXIT "EXIT"
#define SEARCH "SEARCH"

Contact read_contact(void);
int		read_index(int max_index);

int main() {
	PhoneBook			phone_book;
	std::string			input;

	std::cout << "====================" << std::endl;
	std::cout << "My Awesome PhoneBook" << std::endl;
	std::cout << "====================" << std::endl;
	std::cout << "Enter one of the following commands: ADD, SEARCH or EXIT" << std::endl << std::endl;
	
	while (input != EXIT) {
		std::cout << "phonebook> ";
		std::cin >> input;
		// add contact to the phonebook
		if (input == ADD) {
			phone_book.add_contact(read_contact());
			std::cout << std::endl;
			continue;
		}
		// search contact in the phonebook
		if (input == SEARCH) {
			if (phone_book.get_num() == 0) {
				std::cout << "PhoneBook is empty" << std::endl;
				continue;
			}
			phone_book.display_contacts();
			phone_book.display_contact(read_index(phone_book.get_num()) - 1);
			// std::cout << std::endl;
			continue;
		}			
	}
		
	return (0);
}

Contact read_contact(void) {
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	
	std::cout << "First name: ";
	std::cin >> first_name;
	std::cout << "Last name: ";
	std::cin >> last_name;
	std::cout << "Nickname: ";
	std::cin >> nickname;
	std::cout << "Phone number: ";
	std::cin >> phone_number;
	std::cout << "Darkest secret: ";
	std::cin >> darkest_secret;
		
	return (Contact(first_name, last_name, nickname, phone_number, darkest_secret));
}

int read_index(int max_index) {
	std::string	input;
	int			i;
	
	i = 0;
	while ((input.length() != 1) || (i < 1) || (i > max_index) || (i > MAX_CONTACTS)) {
		std::cout << "Index to display: ";
		std::cin >> input;
		i = input[0] - '0';
	}
	return (i);
}