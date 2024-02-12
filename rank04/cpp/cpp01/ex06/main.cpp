/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 20:15:36 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/12 12:07:45 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int	main(int argc, char **argv)
{
	int			case_int;
	std::string	arg;
	Harl		harl;

	if (argc != 2)
		return 0;
	case_int = 0;
	harl.set_filter(argv[1]);
	harl.complain(argv[1]);
}
