#include "toolerase.h"

ToolErase::ToolErase(const std::function<void(uint, uint)> &func) : func(func)
{

}

void ToolErase::action(uint x, uint y)
{
    if(func)
        func(x, y);
}
