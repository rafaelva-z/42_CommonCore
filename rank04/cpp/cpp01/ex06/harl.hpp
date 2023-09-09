/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:15:34 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/09 20:58:20 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl
{
	private:
	void	(Harl::*f[4])(void);
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	public:
	Harl(void);
	~Harl(void);
	std::string f_name[4];
	void		complain(std::string level);
	int			filter;
};

#endif