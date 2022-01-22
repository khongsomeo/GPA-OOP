/**
 * InputHelper.h
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#ifndef INPUT_HELPER_H
#define INPUT_HELPER_H

#include<string>
#include<vector>
#include<stdexcept>
#include<fstream>
#include<memory>

#include"Utility.h"

/**
 * Constants (flags) for input
 *
 */
namespace InputConstants {
  enum {
    ALLOW_INPUT_ERROR = 1 << 0,
    IGNORE_INPUT_ERROR = 1 << 1 
  };
}

/**
 * InputHelper
 * 
 */
class InputHelper {
private:
  int _inputFlag = 0;

  InputHelper();

public:
  ~InputHelper();

  /**
   * Get instance of InputHelper
   * 
   * @return std::shared_ptr<InputHelper>
   */
  static std::shared_ptr<InputHelper> instance();

public:
  /**
   * Set input flag for InputHelper
   *
   * @param  int
   */
  void setInputFlag(int);
  
  /**
   * Check if InputHelper is logging input errors
   *
   * @return bool
   */
  bool isLoggingErrors();

  /**
   * Split a haystack to tokens by needle.
   *
   * @param  std::string
   * @param  const std::string&
   *
   * @return std::vector<std::string>
   */
  std::vector<std::string> splitTokens(std::string, const std::string&);

  /**
   * Read a file to vector of strings.
   *
   * @param  const std::string&
   *
   * @return std::vector<std::string>
   *
   * @throw  std::runtime_error
   */
  std::vector<std::string> readFileLines(const std::string&);
};

#endif  //INPUT_HELPER_H
