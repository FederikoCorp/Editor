#ifndef TOOL_H
#define TOOL_H

#include <functional>

using uint = unsigned int;

class Tool
{
public:
    Tool() = default;
    virtual ~Tool() = default;
    virtual void action(uint x, uint y) = 0;
};

#endif // TOOL_H
