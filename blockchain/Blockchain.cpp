#include "Blockchain.h"

Blockchain::Blockchain() {
    m_chain.emplace_back(Block(0, "Genesis Block"));
    m_difficulty = 4;
    cout << "Number of leading 0s needed in hash: " << m_difficulty << endl;
}

void Blockchain::addBlock(Block bNew) {
    bNew.prevHash = getLastBlock().getHash();
    bNew.mineBlock(m_difficulty);
    m_chain.push_back(bNew);
}

Block Blockchain::getLastBlock() const {
    return m_chain.back();
}

Block Blockchain::getBlock(int i) const {
    return m_chain[i];
}