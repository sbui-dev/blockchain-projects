//  blockchain demo
//
//  Created by Steven Bui on 5/1/19.
//  Copyright © 2019 Steven Bui. All rights reserved.
//

#include <iostream>
#include "Blockchain.h"

#include <fstream>
#include <sstream> //std::stringstream

// use for debugging json
Json::Value readJsonFile() {
    ifstream inFile;
    inFile.open("testJson.txt"); //open the input file

    stringstream strStream;
    strStream << inFile.rdbuf(); //read the file
    string json = strStream.str(); //str holds the content of the file

    cout << json << endl; //you can do anything with the string!!!

    Json::Value root;
    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();
    string errors;

    if (!reader->parse(json.c_str(), json.c_str() + json.size(), &root, &errors))
    {
        cout << "error parsing the json string" << endl;
        exit(-1); // TODO: do correctly
    }

    return root;
}

int main() {
    cout << "*** Blockchain Demo ***" << endl;

    Json::Value json = readJsonFile();
    Blockchain fileChain = Blockchain(json);

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