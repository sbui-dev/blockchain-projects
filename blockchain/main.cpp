#include <iostream>
#include "Blockchain.h"

int main() {
    cout << "*** Blockchain Demo ***" << endl;

    Blockchain bChain = Blockchain();

    cout << endl;
    cout << "Mining block 1..." << endl;
    bChain.addBlock(Block(1, "Block 1 Data"));

    cout << endl;
    cout << "Mining block 2..." << endl;
    bChain.addBlock(Block(2, "Block 2 Data"));

    cout << endl;
    cout << "Mining block 3..." << endl;
    bChain.addBlock(Block(3, "Block 3 Data"));
    cout << endl;


    // test
    Block pBlock1 = bChain.getBlock(1);
    pBlock1.getJson();
    pBlock1.print();
   

    return 0;
}