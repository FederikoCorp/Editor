#include "toolcreate.h"

ToolCreate::ToolCreate(const std::function<void(uint, uint, uint)> &func) : func(func)
{

}

void ToolCreate::action(uint x, uint y)
{
    if(func)
        func(x, y, index);
}

void ToolCreate::setIndex(const uint &value)
{
    index = value;
}
