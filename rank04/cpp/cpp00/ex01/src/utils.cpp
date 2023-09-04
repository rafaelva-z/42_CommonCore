/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:05:05 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/04 17:53:26 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/utils.hpp"

// Align text to the right on a field of size characters
std::string	alignRight(const std::string& text, long unsigned int size)
{
	int			padding;
	std::string	result;

	padding = size - text.size();
    if (text.size() <= size)
	{
		result = std::string(padding, ' ') + text;
        return (result);
	}
	else
        return (text.substr(0, size - 1) + ".");
}

// Get user input and repeat if it's empty
void	getInput(const std::string& prompt, std::string& input)
{
    while (input.empty())
	{
        std::cout << prompt;
        std::getline(std::cin, input);
    }
}

std::string	itos(int i)
{
    std::stringstream ss;
    std::string s;

    ss << i;
    s = ss.str();
	return (s);
}

int ft_stoi(std::string input)
{
    int id;

    std::stringstream ss;
	ss << input;
	std::string hey;
	ss >> id;
    return (id);
}
