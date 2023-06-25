#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class	Intern
{
	public :
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		Intern&	operator=(Intern const &src);

		Form*	makeForm(std::string const &name, std::string const &target) const;

	private : 

		typedef struct	s_formlist
		{
			std::string name;
			Form*	type;
		}					t_formList;

};

std::ostream &	operator<<(std::ostream &o, Intern const &src);

#endif
