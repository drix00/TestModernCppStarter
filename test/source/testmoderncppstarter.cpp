#include <doctest/doctest.h>
#include <testmoderncppstarter/version.h>

#include <string>

#include "testmoderncppstarter/testmoderncppstarter.h"

TEST_CASE("TestModernCppStarter") {
  using namespace testmoderncppstarter;

  TestModernCppStarter testmoderncppstarter("Tests");

  CHECK(testmoderncppstarter.greet(LanguageCode::EN) == "Hello, Tests!");
  CHECK(testmoderncppstarter.greet(LanguageCode::DE) == "Hallo Tests!");
  CHECK(testmoderncppstarter.greet(LanguageCode::ES) == "¡Hola Tests!");
  CHECK(testmoderncppstarter.greet(LanguageCode::FR) == "Bonjour Tests!");
}

TEST_CASE("TestModernCppStarter version") {
  static_assert(std::string_view(TESTMODERNCPPSTARTER_VERSION) == std::string_view("1.0"));
  CHECK(std::string(TESTMODERNCPPSTARTER_VERSION) == std::string("1.0"));
}
