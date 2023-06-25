#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): Form("ShrubberyCreationForm", 145, 137), _target("")
{
	std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target):Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm base constructor." << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): Form("SchrubberyCreationFrom", 145, 137), _target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
	*this = src;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
	return ;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	std::cout << "ShrubberyCreationForm assignation operator called." << std::endl;
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::ofstream	myfile;
	std::string		fileName = this->_target + "_shrubbery";

	checkExe(executor);
	myfile.open(fileName.c_str(), std::ios::out);
	myfile << "             v .   ._, |_  .," << std::endl;
	myfile << "           `-._\\/  .  \\ /    |/_" << std::endl;
	myfile << "               \\  _\\, y | \\//" << std::endl;
	myfile << "         _\\_.___\\, \\/ -.\\||" << std::endl;
	myfile << "           `7-,--.`._||  / / ," << std::endl;
	myfile << "           /'     `-. `./ / |/_.'" << std::endl;
	myfile << "                     |    |//" << std::endl;
	myfile << "                     |_    /" << std::endl;
	myfile << "                     |-   |" << std::endl;
	myfile << "                    |   =|" << std::endl;
	myfile << "                    |    |" << std::endl;
	myfile << "--------------------/ ,  . \\--------._" << std::endl;
	myfile.close();
	std::cout << "Created file in " << this->_target << "_shrubbery;" << std::endl;
	return ;
}
