/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42lisboa.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 15:48:17 by rvaz              #+#    #+#             */
/*   Updated: 2024/02/11 19:46:20 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	display_error(std::string msg, short exit_status)
{
	std::cerr << "\033[0;31m[sed_is_for_losers]\033[0m ";
	std::cerr << msg << std::endl;
	return (exit_status);
}

void	replace_text(std::ofstream &w_file, std::ifstream &r_file, char** argv)
{
	int				i;
	char			c;
	std::string		phrase;
	std::string		to_subs(argv[2]);
	
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
}

int	arg_check(int argc, char **argv)
{
	if (argc != 4 || !argv[1][0] || !argv[2][0])
		return (display_error("invalid args: ./sed_is_for_losers <filename> <s1> <s2>", 1));
	return (0);
}

int	main(int argc, char** argv)
{
	std::string		filename;
	std::ofstream	w_file;
	std::ifstream	r_file;

	if (arg_check(argc, argv))
		return (1);
	filename = argv[1];
	r_file.open(filename.c_str());
	if (!r_file.is_open())
		return (display_error("Can't open file: \"" + filename + "\"", 2));
	w_file.open((filename + ".replace").c_str());
	if (!w_file.is_open())
	{
		r_file.close();
		return (display_error("Can't write to file: \"" + filename + ".replace\"", 2));
	}
	replace_text(w_file, r_file, argv);
	if (w_file.is_open())
		w_file.close();
	if (r_file.is_open())
		r_file.close();
	std::cout << "\033[96m[sed_is_for_losers]\033[0m ";
	std::cout << "Output written to \"" + filename + ".replace\"" << std::endl;
	return (0);
}
