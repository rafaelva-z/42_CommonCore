/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 19:08:34 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/04 17:47:05 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <string>
#include <sstream>

std::string	alignRight(const std::string& text, long unsigned int size);
void		getInput(const std::string& prompt, std::string& input);
std::string	itos(int i);
int			ft_stoi(std::string id);

#endif
