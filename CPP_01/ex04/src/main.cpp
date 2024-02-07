/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrimmei <lgrimmei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:41:52 by lgrimmei          #+#    #+#             */
/*   Updated: 2024/02/06 20:13:36 by lgrimmei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

#define USAGE_ERR "Wrong Usage. ./SedIsForLoosers file.txt oldString newString"
#define FILE_IN_ERR "Error: Could not read from file"
#define FILE_OUT_ERR "Error: Could not write to file"

void	copy_and_replace(std::string& s1, std::string& s2, std::ifstream& inputFile, std::ofstream& outputFile)
{
	std::string	line;
	size_t	pos;
	while (std::getline(inputFile, line))
	{
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			if (pos != std::string::npos)
				line = line.substr(0, pos) + s2 + line.substr(pos + s1.length());
			pos = line.find(s1);
		}
		outputFile << line << std::endl;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << USAGE_ERR << std::endl;
		return (1);
	}

	std::string	filename = argv[1];
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	std::ifstream	inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cerr << FILE_IN_ERR << std::endl;
		return (2);
	}

	std::ofstream	outputFile((filename + ".replace").c_str());
	if (!outputFile)
	{
		std::cerr << FILE_OUT_ERR << std::endl;
		return (3);
	}

	copy_and_replace(s1, s2, inputFile, outputFile);

	return (0);
}

