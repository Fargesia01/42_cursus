#include <iostream>
#include "data.hpp"

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main()
{
	Data		*ptr = new Data;
	Data		*new_ptr;
	uintptr_t		raw;

	ptr->data = "Teeeest";
	raw = serialize(ptr);
	new_ptr = deserialize(raw);
	std::cout << "New data : " << new_ptr->data << std::endl;
}
