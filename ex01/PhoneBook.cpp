/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cesasanc <cesasanc@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 14:11:42 by cesasanc          #+#    #+#             */
/*   Updated: 2024/11/21 14:04:29 by cesasanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* Function to create a PhoneBook object */
PhoneBook::PhoneBook(void)
{
	this->contact_count = 0;
	this->is_full = false;
	return ;
}

/* Function to destroy a PhoneBook object */
PhoneBook::~PhoneBook(void)
{
	return ;
}

std::string	PhoneBook::get_input(const std::string &prompt)
{
	std::string input;

	while (true)
	{
		std::cout << prompt + ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << "\nInput interrupted!" << std::endl;
			exit(0);
		}
		if (input.empty())
		{
			std::cout << "Please enter a valid input." << std::endl;
			continue ;
		}
		return (input);
	}
}

/* Function to add a contact to the PhoneBook */
void	PhoneBook::add_contact(void)
{
	Contact new_contact;
	int 	index;
	
	index = this->contact_count % 8;
	new_contact.set_info(index);
	if (this->is_full)
	
		this->contacts[this->contact_count % 8] = new_contact;
	else
	{
		this->contacts[this->contact_count] = new_contact;
		if (this->contact_count == 7)
			this->is_full = true;
	}
	this->contact_count++;
}

void PhoneBook::search_contact(void) const
{
    int max_contacts;
    std::string index_str;
    int index;

    max_contacts = is_full ? 8 : contact_count;
	
    std::cout << std::endl << "***** Relevant PhoneBook Entries *****" << std::endl;
    std::cout << "|   Index  |First Name|Last  Name| Nickname |" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (int i = 0; i < max_contacts; i++)
        contacts[i].show_contact();

    std::cout << "Enter the index of the contact you want to display: ";
    std::getline(std::cin, index_str);

    if (std::cin.eof())
        exit(1);

    if (index_str.empty()
		|| !std::all_of(index_str.begin(), index_str.end(), [](unsigned char c){ return std::isdigit(c); }))
    {
        std::cout << "Invalid input. Please try again." << std::endl;
        return;
    }

    index = std::stoi(index_str) - 1;

    if (index < 0 || index >= max_contacts)
    {
        std::cout << "Invalid index. Please try again." << std::endl;
        return;
    }

    contacts[index].get_info();
}

