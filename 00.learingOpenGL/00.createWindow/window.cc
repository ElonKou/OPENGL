/*================================================================
*  Copyright (C)2020 All rights reserved.
*  FileName : window.cc
*  Author   : elonkou
*  Email    : elonkou@ktime.cc
*  Date     : Thu 09 Apr 2020 10:29:28 PM CST
================================================================*/

#include "Window.hh"

int main(int argc, char* argv[]) {
    Window window;
    while (!window.Closed()) {
        window.Clear();
        window.PollEvents();
        window.Swap();
    }
    window.Terminate();
    return 0;
}
