//  blockchain demo
//
//  Created by Steven Bui on 5/1/19.
//  Copyright © 2019 Steven Bui. All rights reserved.
//
#pragma once
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
public:
    Blockchain();

    void mineBlock(Block &block, string prevHash);
    bool validateBlock();
    void addBlock(string data);
    Block getBlock(int i) const;
    Json::Value getFullChain();

private:
    uint32_t m_difficulty;
    vector<Block> m_chain;

    Block getLastBlock() const;
};