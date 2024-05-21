/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 22:29:07 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/20 22:34:44 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

class Data
{	
	public:
		Data();
		Data(int data);
		Data(Data &other);
		~Data();
		Data& operator=(Data &other);

		int		getData() const;
		void	setData(int d);

	private:
		int data;
};

#endif