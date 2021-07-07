/**
 * InputHelper.h
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#pragma once

#ifndef INCLUDE_H
#include"include.h"
#endif

#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H

class InputHelper {
public:
  /**
   * Split a haystack to tokens by needle.
   *
   * @param  std::string
   * @param  const std::string&
   *
   * @return std::vector<std::string>
   */
  static std::vector<std::string> splitTokens(
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
  static std::vector<std::string> readFileLines(
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
};

#endif
