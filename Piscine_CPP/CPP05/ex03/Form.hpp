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
		virtual ~Form(void);

		Form& operator=(Form const &src);

		std::string		getName() const;
		bool			getSigned() const;
		int				getGradeToSigne() const;
		int				getGradeToExe() const;
		void			beSigned(Bureaucrat const &src);
		virtual void	execute(Bureaucrat const &executor) const = 0;
		void			checkExe(Bureaucrat const &src) const;

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

		class FormNotSignedException: public std::exception
		{
			public : 

				virtual const char* what() const throw()
				{
					return ("The form is not signed");
				}
		};
};

std::ostream	&operator<<(std::ostream &o, const Form &src);

#endif
