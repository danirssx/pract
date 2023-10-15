#ifndef MEMVIEW_H
#define MEMVIEW_H

#include <string>

namespace mem
{
    std::string IntToHexa(int num);
    template<typename POINTER>
    void MemView(POINTER pointer, int length, int lines);
}

#endif