/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:56:30 by nefimov           #+#    #+#             */
/*   Updated: 2025/09/24 12:01:44 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# define FIELDS_NUM 5
# include <string>

class Contact {
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	
public:
	Contact();
	Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
	~Contact();	
	
	std::string get_first_name() const;
	std::string get_last_name() const;
	std::string get_nickname() const;
	std::string get_phone_number() const;
	std::string get_darkest_secret() const;
};

#endif