/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvaz <rvaz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:54:12 by rvaz              #+#    #+#             */
/*   Updated: 2024/05/07 23:06:27 by rvaz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("ShrubberyCreationForm", 145, 137)
{
	// Nothing to do here
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other.getName() + " copy", 145, 137)
{
	*this = other;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}

std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &f)
{
	return (os << "Form: "		<< f.getName()
		<< ", Sign status: "	<< f.getSigned()
		<< ", GradeToExecute: "	<< f.getGradeToExecute())
		<< ", GradeToSign: "	<< f.getGradeToSign();
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	// Nothing to do here
}

// Other Methods

void	ShrubberyCreationForm::executeForm() const
{
	// Working on the other file
	std::string fileName = _target + "_shrubbery";

	std::ofstream file(fileName.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open file");
	
	file << "                                                         ." << std::endl;
    file << "                                          .         ;  " << std::endl;
    file << "             .              .              ;%     ;;   " << std::endl;
    file << "               ,           ,                :;%  %;   " << std::endl;
    file << "                :         ;                   :;%;'     .," << std::endl;   
    file << "       ,.        %;     %;            ;        %;'    ,;" << std::endl;
    file << "         ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
    file << "          %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
    file << "           ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    file << "            `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    file << "             `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    file << "                `:%;.  :;bd%;          %;@%;'" << std::endl;
    file << "                  `@%:.  :;%.         ;@@%;'   " << std::endl;
    file << "                    `@%.  `;@%.      ;@@%;         " << std::endl;
    file << "                      `@%%. `@%%    ;@@%;        " << std::endl;
    file << "                        ;@%. :@%%  %@@%;       " << std::endl;
    file << "                          %@bd%%%bd%%:;     " << std::endl;
    file << "                            #@%%%%%:;;" << std::endl;
    file << "                            %@@%%%::;" << std::endl;
    file << "                        %@@@%(o);  . '         " << std::endl;
    file << "          /\\             %@@@o%;:(.,'         " << std::endl;
    file << "         | ^|           `.. %@@@o%::;         " << std::endl;
    file << "        /w   \\              `)@@@o%::;         " << std::endl;
    file << "       |    w |              %@@(o)::;        " << std::endl;
    file << "      /* ^   * \\            .%@@@@%::;         " << std::endl;
    file << "      \vuwuwwvu/            ;%@@@@%::;.          " << std::endl;
    file << "         || |              ;%@@@@%%:;;;. " << std::endl;
    file << "         || | rvaz      ...;%@@@@@%%:;;;;,..    Gilo97" << std::endl;


	if (file.is_open())
		file.close();
}