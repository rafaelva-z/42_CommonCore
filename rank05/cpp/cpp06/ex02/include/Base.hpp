/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:48:46 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/23 12:07:23 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base 
{
	public:
		virtual	~Base();
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
#endif