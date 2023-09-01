/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 16:26:16 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/01 17:48:25 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc > 1)
	{
		while (argv[i])
		{
			if (!argv[i][j])
			{
				i++;
				j = 0;
				continue;
			}
			if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
				argv[i][j] -= 32;
			std::cout << argv[i][j++];
		}
	}
	else 
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";

}