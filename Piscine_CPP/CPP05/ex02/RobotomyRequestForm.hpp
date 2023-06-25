#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class RobotomyRequestForm: public Form
{
	public :

		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual ~RobotomyRequestForm(void);

		RobotomyRequestForm &	operator=(RobotomyRequestForm const &src);

		std::string		getTarget() const;
		virtual void	execute(Bureaucrat const &executor) const;


	private :

		RobotomyRequestForm(void);

		const std::string	_target;


};

#endif
