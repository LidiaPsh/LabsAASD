#include <exception>
#ifndef QUEUEOVERFLOW_H
#define QUEUEOVERFLOW_H


class QueueOverflow :
    public std::exception
{
public:
    QueueOverflow() : reason_("Queue Overflow!") {}
    const char* what() { return reason_; }
private:
    const char* reason_;
};

#endif // !QUEUEOVERFLOW_H
