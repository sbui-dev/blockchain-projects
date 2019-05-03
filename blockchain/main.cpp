//  blockchain demo
//
//  Created by Steven Bui on 5/1/19.
//  Copyright © 2019 Steven Bui. All rights reserved.
//

#include <iostream>
#include "Blockchain.h"

int main() {
    cout << "*** Blockchain Demo ***" << endl;

    Blockchain bChain = Blockchain();

    cout << endl;
    cout << "Mining block 1..." << endl;
    bChain.addBlock("Block 1 Data");

    cout << endl;
    cout << "Mining block 2..." << endl;
    bChain.addBlock("Block 2 Data");

    cout << endl;
    cout << "Mining block 3..." << endl;
    bChain.addBlock("Block 3 Data");

    cout << endl;

    // test
    //bChain.validateBlockchain();

    auto b = bChain.getFullChain();

    // test
    //Block pBlock1 = bChain.getBlock(1);
    //pBlock1.getJson();
    //pBlock1.print();
   
    return 0;
}