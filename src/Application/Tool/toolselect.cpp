#include "toolselect.h"

ToolSelect::ToolSelect(const std::function<void(uint, uint)> &func) : func(func)
{

}

void ToolSelect::action(uint x, uint y)
{
    if(func)
        func(x, y);
}
