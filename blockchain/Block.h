#pragma once
#include <cstdint>
#include <iostream>
#include <sstream>
#include <time.h>
#include "picosha2.h"
#include "jsoncpp/json/json.h"

using namespace std;

class Block {
public:
    string prevHash;

    Block(uint32_t index, const string &data);

    string getHash();

    void mineBlock(const uint32_t difficulty);
    void print();
    Json::Value getJson();

private:
    uint32_t m_index;
    int64_t m_nonce;
    string m_data;
    string m_hash;
    time_t m_time;

    string calculateHash() const;
};