#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern default constructor called." << std::endl;
	return ;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern copy constructor called."<< std::endl;
	*this = src;
	return ;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called." << std::endl;
	return ;
}

Intern &	Intern::operator=(Intern const &src)
{
	std::cout << "Intern assignation operator called." << std::endl;
	return (*this);
}

Form *	Intern::makeForm(std::string const &name, std::string const &target) const
{
	Form*	end_form = NULL;
	t_formList forms[] = 
	{
		{"presidential pardon", new PresidentialPardonForm(target)},
		{"robotomy request", new RobotomyRequestForm(target)},
		{"shrubbery creation", new ShrubberyCreationForm(target)},
		{"", NULL}
	};

	for (int i = 0; forms[i].type != NULL; i++)
	{
		if (forms[i].name == name)
			end_form = forms[i].type;
		else
			delete (forms[i].type);
	}

	if (end_form == NULL)
		std::cout << "Intern couldn't find this type of form." << std::endl;
	else
		std::cout << "Intern created form " << name << std::endl;
	return (end_form);
}

std::ostream &	operator<<(std::ostream &o, Intern const &src)
{
	o << "Intern" << std::endl;
	return (o);
}
