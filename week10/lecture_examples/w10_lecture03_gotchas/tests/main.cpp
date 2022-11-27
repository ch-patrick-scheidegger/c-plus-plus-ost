#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>


template <typename T>
struct Parent {
  auto foo() const -> int { return 42; }
  static int const bar{43};
};

int foo() { return 1; }

double const bar{3.14};

template <typename T>
struct Gotchas : Parent<T> {
  auto demo() const -> std::string {
    std::ostringstream result{};
    result << bar << " bar \n";
    result << this->bar << " this->bar \n";
    result << Gotchas::bar << " Gotchas::bar\n";
    result << foo() << " foo() \n";
    result << this->foo() << " this->foo() \n";
    result << Gotchas::foo() << " Gotchas::foo() \n";
    return result.str();
  }
};

TEST(test_name_resolution_gotchas) {
  Gotchas<int> demo{};

  ASSERT_EQUAL("3.14 bar \n"
               "43 this->bar \n"
               "43 Gotchas::bar\n"
               "1 foo() \n"
               "42 this->foo() \n"
               "42 Gotchas::foo() \n",
               demo.demo());
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "Sack<T> Tests",
    {
      test_name_resolution_gotchas,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
