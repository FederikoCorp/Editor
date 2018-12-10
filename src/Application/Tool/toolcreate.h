#ifndef TOOLCREATE_H
#define TOOLCREATE_H

#include "tool.h"

class ToolCreate : public Tool
{
public:
    ToolCreate(const std::function<void(uint x, uint y, uint index)> &);
    void action(uint x, uint y) override;
    void setIndex(const uint &value);

private:
    std::function<void(uint x, uint y, uint index)> func;
    uint index;
};

#endif // TOOLCREATE_H
