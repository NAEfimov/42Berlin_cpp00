/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapb.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:03:12 by nefimov           #+#    #+#             */
/*   Updated: 2025/09/23 18:51:15 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <sstream>
#include <iostream>



int main() {
	PhoneBook			phone_book;
	std::stringstream	ss;

	std::cout << "====================" << std::endl;
	std::cout << "My Awesome PhoneBook" << std::endl;
	std::cout << "====================" << std::endl << std::endl;
	std::cout << "Enter one of the following commands: ADD, SEARCH or EXIT" << std::endl;
	// phone_book.display_contacts();
	
	phone_book.add_contact(Contact("name", "surname", "nickname", "phone_num", "secret"));
	phone_book.display_contacts();

	for (int i = 0 ; i < 16 ; ++i) {
		ss << i;
		phone_book.add_contact(Contact("name", "surname", ss.str(), "phone_num", "secret"));
		phone_book.display_contacts();
	}
	
	phone_book.display_contact(7);
	
	return (0);
}