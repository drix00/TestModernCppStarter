#pragma once

#include <string>

namespace testmoderncppstarter {

  /**  Language codes to be used with the TestModernCppStarter class */
  enum class LanguageCode { EN, DE, ES, FR };

  /**
   * @brief A class for saying hello in multiple languages
   */
  class TestModernCppStarter {
    std::string name;

  public:
    /**
     * @brief Creates a new testmoderncppstarter
     * @param name the name to greet
     */
    TestModernCppStarter(std::string name);

    /**
     * @brief Creates a localized string containing the greeting
     * @param lang the language to greet in
     * @return a string containing the greeting
     */
    std::string greet(LanguageCode lang = LanguageCode::EN) const;
  };

}  // namespace testmoderncppstarter
