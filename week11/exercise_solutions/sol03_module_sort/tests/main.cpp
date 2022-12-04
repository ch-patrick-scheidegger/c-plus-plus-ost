#include "module.hpp"
#include "moduleSort.hpp"

#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <algorithm>
#include <sstream>

TEST(test_module_nodeps) {
  auto m = Module{"OO"};
  ASSERT(m.is_ready());
  ASSERT_EQUAL(Module{"OO"}, m);
  ASSERT_LESS(Module{"AA"}, m);
}

TEST(test_module_deps) {
  auto oo = make_module("OO");
  auto ad1 = make_module("AD1");
  ad1->add(oo);
  ASSERT(!ad1->is_ready());
  ad1->done_with(oo);
  ASSERT(ad1->is_ready());
}

TEST(test_deep_name_comare) {
  auto l = make_module("AA");
  auto r = make_module("BB");
  DeepNameCompare cmp{};
  ASSERT(cmp(l, r));
  ASSERT(!cmp(r, l));
  ASSERT(!cmp(l, l));
  ASSERT(cmp(nullptr, l));
  ASSERT(!cmp(l, nullptr));
  ASSERT(!cmp(nullptr, nullptr));
}

auto const input = std::string{
    R"(
        DB1 OO
        DB2 DB1
        Math
        OO
        AD1 OO
        CPI OO Math
        Thesis DB2 SE2 UI2
        SE1 AD1 CPI DB1
        SE2 DB1 SE1 UI1
        UI1 AD1
        UI2 UI1
)"};

TEST(test_input) {
  std::istringstream is{input};
  ModuleSort ms{is};
  ASSERT_EQUAL(11, ms.all_modules.size());
}

struct EqualName {
  EqualName(char const *n) : name{n} {}
  auto operator()(Module::spm m) -> bool {
    return m && m->name == name;
  }

  std::string name;
};

template <typename RESULT>
auto result_contains(RESULT res, char const *name) -> bool {
  return end(res) != std::ranges::find_if(res, EqualName{name});
}

TEST(test_level_1) {
  std::istringstream is{input};
  ModuleSort ms{is};
  auto res = ms.next_level();
  ASSERT_EQUAL(9, ms.all_modules.size());

  ASSERT_EQUAL(2, res.size());
  ASSERT(result_contains(res, "Math"));
  ASSERT(result_contains(res, "OO"));
}

TEST(test_level_2) {
  std::istringstream is{input};
  ModuleSort ms{is};
  ms.next_level();
  ASSERT_EQUAL(9, ms.all_modules.size());
  auto res = ms.next_level();
  ASSERT_EQUAL(3, res.size());
  ASSERT(result_contains(res, "AD1"));
  ASSERT(result_contains(res, "CPI"));
  ASSERT(result_contains(res, "DB1"));
}

TEST(test_level_3) {
  std::istringstream is{input};
  ModuleSort ms{is};
  ms.next_level();
  ms.next_level();
  ASSERT_EQUAL(6, ms.all_modules.size());
  auto res = ms.next_level();
  ASSERT_EQUAL(3, res.size());
  ASSERT(result_contains(res, "DB2"));
  ASSERT(result_contains(res, "SE1"));
  ASSERT(result_contains(res, "UI1"));
}

TEST(test_level_4) {
  std::istringstream is{input};
  ModuleSort ms{is};
  ms.next_level();
  ms.next_level();
  ms.next_level();
  ASSERT_EQUAL(3, ms.all_modules.size());
  auto res = ms.next_level();
  ASSERT_EQUAL(2, res.size());
  ASSERT(result_contains(res, "UI2"));
  ASSERT(result_contains(res, "SE2"));
}

TEST(test_level_5) {
  std::istringstream is{input};
  ModuleSort ms{is};
  ms.next_level();
  ms.next_level();
  ms.next_level();
  ms.next_level();
  ASSERT_EQUAL(1, ms.all_modules.size());
  auto res = ms.next_level();
  ASSERT_EQUAL(1, res.size());
  ASSERT(result_contains(res, "Thesis"));
  ASSERT_EQUAL(0, ms.all_modules.size());
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "ModuleSort Tests",
    {
      test_module_nodeps,
      test_module_deps,
      test_deep_name_comare,
      test_input,
      test_level_1,
      test_level_2,
      test_level_3,
      test_level_4,
      test_level_5,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
