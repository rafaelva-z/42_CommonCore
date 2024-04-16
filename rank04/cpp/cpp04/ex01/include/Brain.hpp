/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:57:12 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/15 19:41:28 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

# define IDEAS_SIZE 100

class Brain
{
	public:
	Brain();
	~Brain();
	Brain(const Brain &other);
	Brain& operator=(const Brain &other);

	const std::string&	getIdea(int index) const;
	void				setIdea(int index, const std::string &new_idea);

	private:
	std::string _ideas[IDEAS_SIZE];
};

#endif