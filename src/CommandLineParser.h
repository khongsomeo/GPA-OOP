/**
 * Command Line Parser for C++ applications
 *
 * Source: https://stackoverflow.com/a/868894
 */

#ifndef COMMAND_LINE_PARSER
#define COMMAND_LINE_PARSER

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
  CommandLineParser(int& argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
      _tokens.push_back(std::string(argv[i]));
    }
  }

public:
  /**
   * Get a command line option
   *
   * @param  const std::string& option
   *
   * @return std::string
   */
  const std::string& getCmdOption(const std::string& option) const {
    std::vector<std::string>::const_iterator itr;

    itr = std::find(_tokens.begin(), _tokens.end(), option);

    if (itr != _tokens.end() && ++itr != _tokens.end()) {
      return *itr;
    }

    throw std::runtime_error("missing arguments");
  }

  
  /**
   * Check if an option exist.
   *
   * @param  std::string option
   *
   * @return bool
   */
  bool cmdOptionExists(const std::string& option) const {
    return std::find(_tokens.begin(), _tokens.end(), option) != _tokens.end();
  }
};

#endif
