/**
 * Command Line Parser for C++ applications
 *
 * Source: https://stackoverflow.com/a/868894
 */

#ifndef COMMAND_LINE_PARSER
#define COMMAND_LINE_PARSER

#include<algorithm>
#include<vector>
#include<string>
#include<stdexcept>

class CommandLineParser {
private:
  std::vector<std::string> _tokens;

public:
  /**
   * Constructor for CommandLineParser:
   * Create a vector of arguments from argc and argv
   *
   * @param  int&   argc
   * @param  char** argv
   *
   * @return void
   */
  CommandLineParser(int&, char**);

public:
  /**
   * Get a command line option
   *
   * @param  const std::string& option
   *
   * @return std::string
   */
  const std::string& getCmdOption(const std::string&) const;
  
  /**
   * Check if an option exist.
   *
   * @param  std::string option
   *
   * @return bool
   */
  bool cmdOptionExists(const std::string&) const;
};

#endif  //COMMAND_LINE_PARSER_H
