#ifndef TOOLERASE_H
#define TOOLERASE_H

#include "tool.h"

class ToolErase : public Tool
{
public:
    ToolErase(const std::function<void(uint x, uint y)> &func);
    void action(uint x, uint y) override;
private:
    std::function<void(uint x, uint y)> func;
};

#endif // TOOLERASE_H
