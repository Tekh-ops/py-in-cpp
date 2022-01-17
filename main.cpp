/*
Created on: Nov 19, 2021
Author: SciFi NaUT

This C++ program is using Python in C++

Compile with:
g++ -I/Library/Developer/CommandLineTools/Library/Frameworks/Python3.framework/Versions/3.8/Headers/  main.cpp -o output -L/Library/Developer/CommandLineTools/Library/Frameworks/Python3.framework/Versions/3.8/lib/python3.8/config-3.8-darwin -lpython3.8 && ./output
*/

#define PY_SSIZE_T_CLEAN

#include "/Library/Developer/CommandLineTools/Library/Frameworks/Python3.framework/Versions/3.8/Headers/Python.h"

int main(int argc, char const *argv[])
{
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }

    Py_SetProgramName(program); /* optional but recommended */
    Py_Initialize();

    // PyRun_SimpleString("print('Python')");
    // PyRun_SimpleString("from math import sqrt");
    // PyRun_SimpleString("print(sqrt(25))");

    PyRun_SimpleString("exec(open('side.py').read())");

    if (Py_FinalizeEx() < 0) {
        exit(120);
    }

    PyMem_RawFree(program);

    return 0;
}
