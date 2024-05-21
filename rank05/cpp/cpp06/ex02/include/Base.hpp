/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:48:46 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/21 19:21:32 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

class Base 
{
	public:
		virtual	~Base();

	int _a;
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
#endif