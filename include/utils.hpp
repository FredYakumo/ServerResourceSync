#ifndef UTILS_H
#define UTILS_H

#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <openssl/sha.h>
#include <sstream>
#include <sys/types.h>

namespace utils {
inline std::string read_to_end(std::ifstream &fs) {
  std::stringstream ss{};
  while (ss << fs.rdbuf()) {
  }
  return ss.str();
}

inline std::string calculate_str_sha1(const char *origin) {
  unsigned char hash[SHA_DIGEST_LENGTH];

  SHA1(reinterpret_cast<const unsigned char *>(origin), strlen(origin), hash);
  std::stringstream ss;
  for (const unsigned char i : hash) {
    ss << std::hex << std::setw(2) << std::setfill('0')
       << static_cast<uint32_t>(i);
  }
  return ss.str();
}
} // namespace utils

#endif