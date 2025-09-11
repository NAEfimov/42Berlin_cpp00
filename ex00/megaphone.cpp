/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nefimov <nefimov@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:46:36 by nefimov           #+#    #+#             */
/*   Updated: 2025/09/11 16:02:01 by nefimov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define	DFLT_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int argc, char *argv[]) {
	for (int i = 1; i < argc; ++i) {
		std::string arg(argv[i]);
		for (size_t j = 0; j < arg.length(); ++j) {
			std::cout << (char)std::toupper(arg[j]);
		}
	}
	if (argc == 1) {
		std::cout << DFLT_MSG;
	}
	std::cout << "\n";
	return (0);
}