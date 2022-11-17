#include <exception>
#ifndef WRONGQUEUESIZE_H
#define WRONGQUEUESIZE_H

class WrongQueueSize :
    public std::exception
{
public:
    WrongQueueSize() : reason_("Wrong Queue Size!") {}
    const char* what() { return reason_; }
private:
    const char* reason_;
};

#endif // !WRONGQUEUESIZE_H
