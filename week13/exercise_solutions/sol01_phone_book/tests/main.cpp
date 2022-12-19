#include "address.hpp"
#include "entry.hpp"
#include "person.hpp"

#include <cute/cute.h>
#include <cute/cute_equals.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>

TEST(can_default_construct_address) {
  auto obj = Address{};
  ASSERT_EQUAL("", obj.street);
  ASSERT_EQUAL(0, obj.streetNumber);
  ASSERT_EQUAL(0, obj.zipCode);
  ASSERT_EQUAL("", obj.city);
}

TEST(can_print_default_constructed_address) {
  auto obj = Address{};
  auto out = std::ostringstream{};

  out << obj;

  ASSERT_EQUAL(" 0\n0 ", out.str());
}

TEST(can_construct_address_with_data) {
  auto obj = Address{"Examplestreet", 42, 1234, "Testcity"};
  ASSERT_EQUAL("Examplestreet", obj.street);
  ASSERT_EQUAL(42, obj.streetNumber);
  ASSERT_EQUAL(1234, obj.zipCode);
  ASSERT_EQUAL("Testcity", obj.city);
}

TEST(can_print_address_constructed_with_data) {
  auto obj = Address{"Examplestreet", 42, 1234, "Testcity"};
  auto out = std::ostringstream{};

  out << obj;

  ASSERT_EQUAL("Examplestreet 42\n1234 Testcity", out.str());
}

TEST(can_default_construct_person) {
  auto obj = Person{};
  ASSERT_EQUAL("", obj.firstName);
  ASSERT_EQUAL("", obj.lastName);
}

TEST(can_print_default_constructed_person) {
  auto obj = Person{};
  auto out = std::ostringstream{};

  out << obj;

  ASSERT_EQUAL(", ", out.str());
}

TEST(can_construct_person_with_data) {
  auto obj = Person{"Arthur", "Dent"};
  ASSERT_EQUAL("Arthur", obj.firstName);
  ASSERT_EQUAL("Dent", obj.lastName);
}

TEST(can_print_person_constructed_with_data) {
  auto obj = Person{"Arthur", "Dent"};
  auto out = std::ostringstream{};

  out << obj;

  ASSERT_EQUAL("Dent, Arthur", out.str());
}

TEST(can_default_construct_entry) {
  auto obj = Entry{};

  ASSERT_EQUAL(0, obj.address.streetNumber);
  ASSERT_EQUAL("", obj.address.street);
  ASSERT_EQUAL("", obj.address.city);
  ASSERT_EQUAL(0, obj.address.zipCode);
  ASSERT_EQUAL("", obj.phoneNumber);
  ASSERT_EQUAL("", obj.person.firstName);
  ASSERT_EQUAL("", obj.person.lastName);
}

TEST(can_print_default_constructed_entry) {
  auto obj = Entry{};
  auto out = std::ostringstream{};

  out << obj;

  ASSERT_EQUAL(", \n\n 0\n0 ", out.str());
}

TEST(can_construct_entry_with_data) {
  auto obj = Entry{
    {"Durnan", "Dryndilstann"},
    "(Sending Stone)",
    {"Rainrun Street", 17, 843, "Waterdeep"}
  };

  ASSERT_EQUAL(17, obj.address.streetNumber);
  ASSERT_EQUAL("Rainrun Street", obj.address.street);
  ASSERT_EQUAL("Waterdeep", obj.address.city);
  ASSERT_EQUAL(843, obj.address.zipCode);
  ASSERT_EQUAL("(Sending Stone)", obj.phoneNumber);
  ASSERT_EQUAL("Durnan", obj.person.firstName);
  ASSERT_EQUAL("Dryndilstann", obj.person.lastName);
}

TEST(can_print_entry_constructed_with_data) {
  auto obj = Entry{
    {"Durnan", "Dryndilstann"},
    "(Sending Stone)",
    {"Rainrun Street", 17, 843, "Waterdeep"}
  };
  auto out = std::ostringstream{};

  out << obj;

  ASSERT_EQUAL("Dryndilstann, Durnan\n(Sending Stone)\nRainrun Street 17\n843 Waterdeep", out.str());
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "Phone Book Tests",
    {
      can_default_construct_address,
      can_print_default_constructed_address,
      can_construct_address_with_data,
      can_print_address_constructed_with_data,
      can_default_construct_person,
      can_print_default_constructed_person,
      can_construct_person_with_data,
      can_print_person_constructed_with_data,
      can_default_construct_entry,
      can_print_default_constructed_entry,
      can_construct_entry_with_data,
      can_print_entry_constructed_with_data,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
