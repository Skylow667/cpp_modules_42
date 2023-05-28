#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string Name);
		ScavTrap(const ScavTrap &copy);
		ScavTrap &operator= (const ScavTrap &copy);
		void attack(const std::string &target);
		~ScavTrap(void);
		void guardGate(void);
	private:
		ScavTrap(void);
};
#endif
