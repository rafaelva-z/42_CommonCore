/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:52:48 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/02 20:00:43 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSOLE_HPP
# define CONSOLE_HPP

#include <iostream>
#include <string>
#include "utils.hpp"

void	clearScreen();
void	printCommands();
void	printWelcome();
void	displayField(const std::string& text, int fieldWidth);

#endif
