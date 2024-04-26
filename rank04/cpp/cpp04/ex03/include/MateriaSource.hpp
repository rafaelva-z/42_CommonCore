/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:44:44 by rvaz              #+#    #+#             */
/*   Updated: 2024/04/26 16:45:02 by rvaz             ###   ########.fr       */
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
	AMateria *mat_inventory[4];
	
	public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);
};

#endif