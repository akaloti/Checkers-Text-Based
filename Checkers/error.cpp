#include "error.h"

void error(std::string message) 
{
	throw message;
}