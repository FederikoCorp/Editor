#ifndef TOOLSELECT_H
#define TOOLSELECT_H

#include "tool.h"

class ToolSelect : public Tool
{
public:
    ToolSelect(const std::function<void(uint x, uint y)> &func);
    void action(uint x, uint y) override;
private:
    std::function<void(uint x, uint y)> func;
};

#endif // TOOLSELECT_H
