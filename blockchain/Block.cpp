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

    do {
        m_nonce++;
        m_hash = calculateHash();
    } while (m_hash.substr(0, difficulty) != str);

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