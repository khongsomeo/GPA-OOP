/**
 * InputHelper.h
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#pragma once

#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H

#include<string>
#include<vector>
#include<stdexcept>
#include<fstream>

#include"Utility.h"

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
  static std::vector<std::string> splitTokens(std::string, const std::string&);

  /**
   * Read a file to vector of strings.
   *
   * @param  const std::string&
   *
   * @return std::vector<std::string>
   *
   * @throw  std::runtime_error
   */
  static std::vector<std::string> readFileLines(const std::string&);
};

#endif
