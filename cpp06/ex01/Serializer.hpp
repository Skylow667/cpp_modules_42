#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <string>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	 private:
		Serializer();
		~Serializer();
		Serializer (const Serializer &copy);
		Serializer &operator=(const Serializer&);
	 public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
