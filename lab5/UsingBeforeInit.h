#include <exception>
#ifndef USINGBEFOREINIT_H
#define USINGBEFOREINIT_H

class UsingBeforeInit :
    public std::exception
{
public:
    UsingBeforeInit() : reason_("Using Before Initializaton!") {}
    const char* what() { return reason_; }
private:
    const char* reason_;
};

#endif // !USINGBEFOREINIT_H
