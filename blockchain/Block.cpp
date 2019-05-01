#include "Block.h"

Block::Block(uint32_t index, const string &data) : m_index(index), m_data(data), m_nonce(-1), m_time(time(nullptr)) {
}

string Block::getHash() {
    return m_hash;
}

void Block::mineBlock(const uint32_t difficulty) {

    unique_ptr<char[]> cstr(new char[difficulty + 1]);

    for (uint32_t i = 0; i < difficulty; ++i) {
        cstr[i] = '0';
    }
    cstr[difficulty] = '\0';

    string str(cstr.get());
    int count = 0;
    cout << "Hashing... " << endl;
    cout << "Index: " << m_index << endl;
    cout << "Time: " << m_time << endl;
    cout << "Data: " << m_data << endl;
    cout << "Previous Hash: " << prevHash << endl;

    cout << "Finding a suitable nonce..." << endl;

    // nonce is changed every round to calculate the hash
    // hash needs to have leading number of 0s
    do {
        m_nonce++;
        count++;
        m_hash = calculateHash();
    } while (m_hash.substr(0, difficulty) != str);

    cout << "Tries before hash found: " << count << endl;
    cout << "Nonce used: " << m_nonce << endl;
    cout << "Block mined: " << m_hash << endl;
}

inline string Block::calculateHash() const {
    stringstream ss;
    ss << m_index << m_time << m_data << m_nonce << prevHash;

    std::vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(ss.str(), hash);

    string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());

    return hex_str;
}

void Block::print() {
    cout << "*** Block ***" << endl;
    cout << "Index: " << m_index << endl;
    cout << "Time: " << m_time << endl;
    cout << "Data: " << m_data << endl;
    cout << "Nonce: " << m_nonce << endl;
    cout << "Hash: " << m_hash << endl;
}