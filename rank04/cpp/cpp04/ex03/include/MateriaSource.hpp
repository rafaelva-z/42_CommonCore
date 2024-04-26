/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:44:44 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/25 16:12:45 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# define MATERIA_TEMPLATE_SLOTS 4

class MateriaSource : public IMateriaSource
{
	private:
	AMateria *materia_template_inventory[4];
	
	public:
	~MateriaSource() {}
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif