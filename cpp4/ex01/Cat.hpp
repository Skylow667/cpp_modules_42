#ifndef CAT_HPP
# define CAT_HPP
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal 
{
	 public:
		Cat();
		~Cat();
		Cat (const Cat &copy);
		Cat &operator=(const Cat& copy);
		void makeSound(void) const;
		void setCatIdeas(std::string ideas);
		void printCatIdeas(void);
	private:
		Brain *_cat_brain;
};

#endif
