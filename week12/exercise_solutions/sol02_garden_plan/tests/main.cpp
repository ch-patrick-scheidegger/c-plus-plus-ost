#include "bed.hpp"
#include "diamond.hpp"
#include "rectangle.hpp"
#include "shoppingList.hpp"
#include "square.hpp"
#include "triangle.hpp"

#include <cute/cute.h>
#include <cute/cute_runner.h>
#include <cute/ide_listener.h>
#include <cute/summary_listener.h>

#include <sstream>
#include <string>
#include <vector>
#include <memory>

TEST(triangle_has_3_pegs) {
    auto obj = Triangle{3, 6, 6.70820393};
    ASSERT_EQUAL(3, obj.pegs());
}

TEST(triangle_example_ropes) {
    auto obj = Triangle{3, 6, 6.70820393};
    ASSERT_EQUAL_DELTA(15.7082, obj.ropes(), 0.001);
}

TEST(triangle_example_seeds) {
    auto obj = Triangle{3, 6, 6.70820393};
    ASSERT_EQUAL_DELTA(0.9, obj.seeds(), 0.001);
}

TEST(triangle_example_print) {
    Bed const & obj = Triangle{3, 6, 6.70820393};
    auto buffer = std::ostringstream{};
    obj.print(buffer);
    ASSERT_EQUAL("Triangle 3 15.7082 0.9", buffer.str());
}

TEST(square_has_4_pegs) {
    auto obj = Square{3.0};
    ASSERT_EQUAL(4, obj.pegs());
}

TEST(square_example_ropes) {
    auto obj = Square{3.0};
    ASSERT_EQUAL_DELTA(12, obj.ropes(), 0.001);
}

TEST(square_example_seeds) {
    auto obj = Square{3.0};
    ASSERT_EQUAL_DELTA(0.9, obj.seeds(), 0.001);
}

TEST(square_example_print) {
    Bed const & obj = Square{3.0};
    auto buffer = std::ostringstream{};
    obj.print(buffer);
    ASSERT_EQUAL("Square 4 12 0.9", buffer.str());
}

TEST(rectangle_has_4_pegs) {
    auto obj = Rectangle{4.0, 9.0};
    ASSERT_EQUAL(4, obj.pegs());
}

TEST(rectangle_example_ropes) {
    auto obj = Rectangle{4.0, 9.0};
    ASSERT_EQUAL_DELTA(26, obj.ropes(), 0.001);
}

TEST(rectangle_example_seeds) {
    auto obj = Rectangle{4.0, 9.0};
    ASSERT_EQUAL_DELTA(3.6, obj.seeds(), 0.001);
}

TEST(rectangle_example_print) {
    Bed const & obj = Rectangle{4.0, 9.0};
    auto buffer = std::ostringstream{};
    obj.print(buffer);
    ASSERT_EQUAL("Rectangle 4 26 3.6", buffer.str());
}

TEST(diamond_has_4_pegs) {
    auto obj = Diamond{4.0, 60};
    ASSERT_EQUAL(4, obj.pegs());
}

TEST(diamond_example_ropes) {
    auto obj = Diamond{4.0, 60};
    ASSERT_EQUAL_DELTA(16, obj.ropes(), 0.001);
}

TEST(diamond_example_seeds) {
    auto obj = Diamond{4.0, 60};
    ASSERT_EQUAL_DELTA(1.38564, obj.seeds(), 0.001);
}

TEST(diamond_example_print) {
    Bed const & obj = Diamond{4.0, 60};
    auto buffer = std::ostringstream{};
    obj.print(buffer);
    ASSERT_EQUAL("Diamond 4 16 1.38564", buffer.str());
}

TEST(shopping_list_example) {
    using namespace std::string_literals;
    auto buffer = std::ostringstream{};

    auto expected = R"(Triangle 3 15.7082 0.9
Triangle 3 11 0.556215
Triangle 3 11 0.556215
Diamond 4 16 1.38564
Square 4 12 0.9
Square 4 12 0.9
Rectangle 4 26 3.6
pegs needed: 25
seeds needed: 8.79807 kg
rope needed: 103.708 m)"s;

    auto list = std::vector<std::shared_ptr<Bed>>{
        std::make_shared<Triangle>(3, 6, 6.70820393),
        std::make_shared<Triangle>(3,4,4),
        std::make_shared<Triangle>(3,4,4),
        std::make_shared<Diamond>(4, 60),
        std::make_shared<Square>(3),
        std::make_shared<Square>(3),
        std::make_shared<Rectangle>(4, 9),
    };

    printShoppingList(list, buffer);
    ASSERT_EQUAL(expected, buffer.str());
}

auto main(int argc, char const *argv[]) -> int {
  auto suite = cute::suite{
    "Garden Plan Tests",
    {
      triangle_has_3_pegs,
      triangle_example_ropes,
      triangle_example_seeds,
      triangle_example_print,
      square_has_4_pegs,
      square_example_ropes,
      square_example_seeds,
      square_example_print,
      rectangle_has_4_pegs,
      rectangle_example_ropes,
      rectangle_example_seeds,
      rectangle_example_print,
      diamond_has_4_pegs,
      diamond_example_ropes,
      diamond_example_seeds,
      diamond_example_print,
      shopping_list_example,
    }
  };

  auto listener = cute::ide_listener<cute::summary_listener<>>{};
  auto runner = cute::makeRunner(listener, argc, argv);

  return runner(suite) ? EXIT_SUCCESS : EXIT_FAILURE;
}
