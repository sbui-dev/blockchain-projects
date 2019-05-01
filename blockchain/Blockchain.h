#pragma once
#include <vector>
#include "Block.h"

using namespace std;

class Blockchain {
public:
    Blockchain();

    void addBlock(Block newBlock);
    Block getBlock(int i) const;

private:
    uint32_t m_difficulty;
    vector<Block> m_chain;

    Block getLastBlock() const;
};