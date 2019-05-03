//  blockchain demo
//
//  Created by Steven Bui on 5/1/19.
//  Copyright © 2019 Steven Bui. All rights reserved.
//
#pragma once
#include <cstdint>
#include <iostream>
#include <sstream>
#include <time.h>
#include "picosha2.h"
#include "jsoncpp/json/json.h"

using namespace std;

// a block contains index, timestamp, data, proof, and previous block's hash
class Block {
public:

    Block(uint32_t index, const string &data);
    Block(uint32_t index, const string& data, string prevHash, int64_t nonce, time_t time);

    string getPrevHash();
    int64_t getProof();
    void print();
    Json::Value getJson();
    string calculateHash(uint64_t nonce, string prevHash);

private:
    uint32_t m_index{ 0 };
    int64_t m_nonce{ -1 };
    string m_data;
    string m_prevHash;
    time_t m_time;
};