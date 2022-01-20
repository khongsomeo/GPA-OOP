/**
 * InputHelper implementation
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include"InputHelper.h"

/**
 * Split a haystack to tokens by needle.
 *
 * @param  std::string
 * @param  const std::string&
 *
 * @return std::vector<std::string>
 */
std::vector<std::string> InputHelper::splitTokens(
    std::string haystack,
    const std::string& needle) {
  std::vector<std::string> tokens;

  size_t index = 0;

  while ((index = haystack.find(needle)) != std::string::npos) {
    tokens.push_back(haystack.substr(0, index));

    haystack.erase(0, index + needle.length());
  }

  tokens.push_back(haystack);

  return tokens;
}

/**
 * Read a file to vector of strings.
 *
 * @param  const std::string&
 *
 * @return std::vector<std::string>
 *
 * @throw  std::runtime_error
 */
std::vector<std::string> InputHelper::readFileLines(
    const std::string& inputFile) {
  // If the file DNE, throw new error.
  if (!Utility::isFileExist(inputFile)) {
    throw std::runtime_error("Input file does not exist");
  }

  std::ifstream openFile(inputFile);
  std::string buffer;
  std::vector<std::string> resultVector;

  while (std::getline(openFile, buffer)) {
    resultVector.push_back(buffer);
  };

  return resultVector;
}
