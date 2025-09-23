/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:58:13 by nefimov           #+#    #+#             */
/*   Updated: 2025/09/23 18:41:32 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACTS 8

# include "Contact.hpp"

class PhoneBook {
private:
	Contact	contacts_list[MAX_CONTACTS];
	int		num;
	
public:
	PhoneBook();
	~PhoneBook();
	
	void	add_contact(Contact cont);
	void	display_contacts();
	void	display_contact(int i);
};

#endif