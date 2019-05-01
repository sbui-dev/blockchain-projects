#pragma once
#include <cstdint>
#include <iostream>

using namespace std;

class Block {
public:
    string prevHash;

    Block(uint32_t index, const string* data);

    string getHash();

    void mineBlock(uint32_t difficulty);

private:
    uint32_t m_index;
    int64_t m_nonce;
    string m_data;
    string m_hash;
    time_t m_time;

    string calculateHash() const;
};