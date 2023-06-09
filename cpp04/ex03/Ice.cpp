#include "Ice.hpp"

Ice::Ice(void):AMateria("ice"){
}

Ice::~Ice(){
}

Ice::Ice(const Ice &copy):AMateria(copy){
}

Ice & Ice::operator=(const Ice &copy){
	if (&copy != this)
	{
		this->~Ice();
		new(this) Ice();
	}
	return (*this);
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
