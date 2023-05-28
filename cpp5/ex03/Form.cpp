#include "Form.hpp"

Form::Form():_name("Unknown"),_grade_to_signed(150),_grade_to_exe(150) {}

const char * Form::GradeTooLowException::what() const throw() {
	return ("The Form grade is too low or the Bureaucrat grade is not high enough!");
}

const char * Form::GradeTooHighException::what() const throw() {
	return ("The Form grade is too high!");
}

const char * Form::AlreadySigned::what() const throw() {
	return ("The Form grade is already signed!");
}

const char * Form::ExecutionException::what() const throw() {
	return ("The form is not signed or the execution grade is too low!");
}

Form::Form(const std::string name, const int grade_sign, const int grade_exe): 
	_name(name),
	_grade_to_signed(grade_sign),
	_grade_to_exe(grade_exe){
	if (_grade_to_exe < 1 || _grade_to_signed < 1)
		throw (Form::GradeTooHighException());
	else if (_grade_to_exe > 150 || _grade_to_signed > 150)
		throw (Form::GradeTooLowException());
	_signed = false;
}

Form::~Form(){
}

Form &Form::operator=(const Form& copy) {
	_signed = copy._signed;
	return (*this);
}

Form::Form(const Form &copy):_name(copy._name), _grade_to_signed(copy._grade_to_signed), _grade_to_exe(copy._grade_to_exe){
	*this = copy;
}

void Form::beSigned(Bureaucrat &worker) {
	if (_signed == true)
		throw (Form::AlreadySigned());
	else if (worker.getGrade() > _grade_to_signed)
		throw (Form::GradeTooLowException());
	else
		_signed = true;
}

std::string Form::getName(void) const {
	return (_name);
}

bool Form::getSigned(void) const {
	return (_signed);
}

int Form::getGradeExe(void) const {
	return (_grade_to_exe);
}
int Form::getGradeSign(void) const {
	return (_grade_to_signed);
}

std::ostream &operator<< (std::ostream &out, Form &form) {
	out << "Form name: " << form.getName() << ", Grade To Signed: " << form.getGradeSign();
	out << ", Grade To Execute: " << form.getGradeExe() << std::endl;
	return (out);
}
