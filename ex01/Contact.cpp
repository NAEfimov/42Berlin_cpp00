/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:58:44 by nefimov           #+#    #+#             */
/*   Updated: 2025/09/23 18:53:07 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact()  {
	first_name = "";
	last_name = "";
	nickname  = "";
	phone_number = "";
	darkest_secret = "";
	// std::cout << "Contact default constructor called" << "\n";
}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)  {
	first_name = fn;
	last_name = ln;
	nickname  = nn;
	phone_number = pn;
	darkest_secret = ds;
	// std::cout << "Contact field constructor called" << "\n";
	// std::cout << "Contact created" << "/n";
}

Contact::~Contact() {
	// std::cout << "Contact destructor called!" << "\n";
}

std::string Contact::get_first_name() {
	return (first_name);
}

std::string Contact::get_last_name() {
	return (last_name);
}

std::string Contact::get_nickname() {
	return (nickname);	
}

std::string Contact::get_phone_number() {
	return (phone_number);
}

std::string Contact::get_darkest_secret() {
	return (darkest_secret);
}