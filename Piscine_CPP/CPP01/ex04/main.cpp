/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slott <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:51:58 by slott             #+#    #+#             */
/*   Updated: 2022/11/14 17:32:58 by slott            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Replace.hpp"

int	printError(std::string msg)
{
	std::cout << "Error: " << msg << std::endl;
	return (1);
}

int	main(int argc, char **argv)
{
	Replace	rep;

	if (argc != 4)
		return (printError("Wrong number of arguments"));
	if (rep.open_files(argv[1], argv[2], argv[3]))
		return (printError("File name can't be empty"));
	return (0);
}
