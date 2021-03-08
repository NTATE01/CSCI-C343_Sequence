/*
 _ _    _  _________
| \ \  | ||___   ___|
| |\ \ | |    | |      Nathan Tate, 
| | \ \| |    | |      IU Southeast, Class of 2023
| |  \ \ |    | |      https://github.com/ntate01
|_|   \__|    |_|
*/
#pragma once
#include "Sequence.hpp"
#include <iostream>
using namespace std;
int main()
{
    Sequence<int> seq;
    int x = 1;
    int y = 2;
    int z = 3; 

    seq.add(x, 0);
    seq.outputSequence();
    cout<<"\n";
    cout <<"seq after add x\n";
    seq.add(y,1);
    cout <<"seq after add y\n";
    seq.outputSequence();
    return 0;
} //main
