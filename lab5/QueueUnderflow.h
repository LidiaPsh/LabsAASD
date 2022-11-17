#include <exception>

#ifndef QUEUEUNDERFLOW_H
#define QUEUEUNDERFLOW_H

class QueueUnderflow :
    public std::exception
{
public:
    QueueUnderflow() : reason_("Queue Underflow!") {}
    const char* what() { return reason_; }
private:
    const char* reason_;
};

#endif // !QUEUEUNDERFLOW_H
