#ifndef WRONGSTACKSIZE_H
#define WRONGSTACKSIZE_H
#include<exception>

class WrongStackSize : public std::exception
{
public:
	WrongStackSize() : reason_("Wrong Stack Size") {}
	const char* what() const { return reason_; }
private:
	const char* reason_;
};

#endif // !WRONGSTACKSIZE_H
