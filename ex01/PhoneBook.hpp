/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:58:13 by nefimov           #+#    #+#             */
/*   Updated: 2025/12/11 13:52:53 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_CONTACTS 8
# define CL_WIDTH 10

# include "Contact.hpp"

class PhoneBook {
  public:
	PhoneBook();
	~PhoneBook();
	
	int		get_num();
	void	add_contact(Contact cont);
	void	display_contact(int i);
	void	display_contacts();
	
  private:
	Contact	contacts_list[MAX_CONTACTS];
	int		num;

	std::string get_format_field(std::string const src) const;
};

#endif