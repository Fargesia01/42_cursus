#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class PresidentialPardonForm: public Form
{
	public :

		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		virtual ~PresidentialPardonForm(void);

		PresidentialPardonForm &	operator=(PresidentialPardonForm const &src);

		std::string		getTarget() const;
		virtual void	execute(Bureaucrat const &executor) const;


	private :

		PresidentialPardonForm(void);

		const std::string	_target;


};

#endif
