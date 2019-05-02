//  blockchain demo
//
//  Created by Steven Bui on 5/1/19.
//  Copyright © 2019 Steven Bui. All rights reserved.
//
#include "Blockchain.h"

Blockchain::Blockchain() {
    // create the first block aka the genesis block
    m_chain.emplace_back(Block(0, "Genesis Block"));
    // set leading zeros
    m_difficulty = 4; // TODO: change back to 4
    cout << "Number of leading 0s needed in hash: " << m_difficulty << endl;
}

void Blockchain::addBlock(Block bNew) {
    bNew.prevHash = getLastBlock().getHash();
    bNew.mineBlock(m_difficulty);
    m_chain.push_back(bNew);
}

bool Blockchain::validateBlock() {
    return true;
}

// Returns entire blockchain as a JSON
Json::Value Blockchain::getFullChain() {
    Json::Value root;

    root["length"] = m_chain.size();

    for (int i = 0; i < m_chain.size(); i++) {
        root["chain"][i] = m_chain[i].getJson();
    }

    cout << root << endl;

    return root;
}

Block Blockchain::getLastBlock() const {
    return m_chain.back();
}

Block Blockchain::getBlock(int i) const {
    return m_chain[i];
}