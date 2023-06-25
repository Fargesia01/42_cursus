#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public :

		Form(std::string name, int gradeToSign, int gradeToExe);
		Form(Form const &src);
		~Form(void);

		Form& operator=(Form const &src);

		std::string	getName() const;
		bool		getSigned() const;
		int			getGradeToSigne() const;
		int			getGradeToExe() const;
		void		beSigned(Bureaucrat const &src);

	private :

		Form		(void);
		void		checkGrades() const;

		const std::string	_name;
		bool				_signed;
		const int			_gToSign;
		const int			_gToExe;

	public : 

		class GradeTooHighException: public std::exception
		{
			public :

				virtual const char* what() const throw()
				{
					return ("The grade you set is too high.");
				}
		};

		class GradeTooLowException: public std::exception
		{
			public :

				virtual const char* what() const throw()
				{
					return ("The grade you set is too low.");
				}
		};
};

std::ostream	&operator<<(std::ostream &o, const Form &src);

#endif
