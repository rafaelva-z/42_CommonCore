/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:15:34 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/12 11:39:54 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	private:
	void		(Harl::*_fLevel[4])(void);
	std::string _level[4];
	int			_filter;
	void		debug(void);
	void		info(void);
	void		warning(void);
	void		error(void);

	public:
	Harl(void);
	~Harl(void);
	void		complain(std::string const &level);
	void		set_filter(std::string const &level);
};

#endif