#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{

	public :

		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &src);
		~Bureaucrat(void);

		Bureaucrat&	operator=(const Bureaucrat &src);

		const std::string	getName() const;
		int					getGrade() const;

		void	addGrade(int amount);
		void	lowGrade(int amount);
		bool	signForm(Form &form) const;
		bool	executeForm(Form &form) const;

	private :

		Bureaucrat(void);
		void	checkGrade() const;
		const std::string	_name;
		int					_grade;

	public : 

		class GradeTooHighException: public std::exception
		{
			public : 

				virtual const char*	what() const throw()
				{
					return ("The grade set is too high.");
				}
		};

		class GradeTooLowException: public std::exception
		{
			public : 

				virtual const char*	what() const throw()
				{
					return ("The grade set is too low.");
				}
		};
};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &src);

#endif
