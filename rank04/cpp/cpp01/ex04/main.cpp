/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:48:17 by rvaz              #+#    #+#             */
/*   Updated: 2023/09/07 12:47:52 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char** argv)
{
	std::string		filename;
	std::ofstream	w_file;
	std::ifstream	r_file;
	int				i;
	char			c;
	std::string		phrase;
	std::string		to_subs(argv[2]);

	if (argc != 4)
		return 0;
	filename = argv[1];
	r_file.open(filename.c_str());
	if (!r_file.is_open())
	{
		std::cerr << "Can't open file: " + filename;
		return 0;
	}
	w_file.open((filename + ".replace").c_str());
	i = 0;
	c = 0;
	while (c != -1)
	{
		c = r_file.get();
		if (c != argv[2][i])
		{
			if (phrase.size())
			{
				w_file << phrase;
				phrase = "";
				i = 0;
			}
			if (c > 0)
				w_file << c;
		}
		else
		{
			phrase += c;
			if (!phrase.compare(to_subs))
			{
				w_file << argv[3];
				phrase = "";
			}
			else
				i++;
		}
		
	}
	//if finds argv[2], instead put argv[3]
	if (w_file.is_open())
		w_file.close();
	if (r_file.is_open())
		r_file.close();
}
