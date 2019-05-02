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

void Blockchain::addBlock(string data) {
    Block newBlock = Block(m_chain.size(), data);
    mineBlock(newBlock, getLastBlock().getPrevHash());
    m_chain.push_back(newBlock);
}

void Blockchain::mineBlock(Block &block, string prevHash) {

    unique_ptr<char[]> cstr(new char[m_difficulty + 1]);

    for (uint32_t i = 0; i < m_difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[m_difficulty] = '\0';

    string str(cstr.get());

    // output what is being hashed
    cout << "Doing proof of work..." << endl;
    cout << "Previous Hash: " << prevHash << endl;

    // proof of work
    // nonce is changed every round to calculate the hash
    // hash needs to have leading number of 0s
    uint64_t nonce = -1;
    string hash;
    do {
        nonce++;
        hash = block.calculateHash(nonce, prevHash);
    } while (hash.substr(0, m_difficulty) != str);
 
    cout << "Nonce used: " << nonce << endl;
    cout << "Block mined: " << hash << endl;
}

// validates an entire blockchain
bool Blockchain::validateBlockchain() {

    cout << "Validating blockchain..." << endl;

    // validate the proof
    for (size_t i = 1; i < m_chain.size(); i++) {
        Block& currBlock = m_chain[i];
        string prevHash = m_chain[i - 1].getPrevHash();

        if (currBlock.getPrevHash() != currBlock.calculateHash(currBlock.getProof(), prevHash)) {
            cout << "Invalid blockchain detected!" << endl;
            return true;
        }
    }

    cout << "Valid blockchain!" << endl;
    return false;
}

// Returns entire blockchain as a JSON
Json::Value Blockchain::getFullChain() {
    Json::Value root;

    root["length"] = m_chain.size();

    for (size_t i = 0; i < m_chain.size(); i++) {
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