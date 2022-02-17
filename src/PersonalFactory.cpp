/**
 * PersonalFactory.h implementation
 *
 * Code by @trhgquan - https://github.com/trhgquan
 */

#include "PersonalFactory.h"

/**
 * PersonalFactory default constructor
 * This will push prototypes (classes) to a list - to create later.
 *
 * @return void
 */
PersonalFactory::PersonalFactory() {
  // Push list of prototypes.
  _prototypes.push_back(std::make_shared<PersonalGPA>());
  _prototypes.push_back(std::make_shared<PersonalSpecific>());
  _prototypes.push_back(std::make_shared<PersonalExcept>());
}

/**
 * PersonalFactory destructor
 *
 * @return void
 */
PersonalFactory::~PersonalFactory() {
  // Do nothing.
}

/**
 * Init a new instance.
 *
 * @return std::shared_ptr<PersonalFactory>
 */
std::shared_ptr<PersonalFactory> PersonalFactory::instance() {
  static std::shared_ptr<PersonalFactory> instance(new PersonalFactory());

  return instance;
}

/**
 * Create a new instance of PersonalGPA
 *
 * @param  const std::vector<std::string>&
 *
 * @return std::shared_ptr<PersonalGPA>
 */
std::shared_ptr<PersonalGPA> PersonalFactory::create(
    int option, const std::vector<std::string> &arguments) {
  return _prototypes.at(option)->parse(arguments);
}
