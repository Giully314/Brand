import std;

import brand;

using namespace brand::core;

auto f(int x) -> int {
    return x * 2;
}

auto g(int y) -> int {
    return y + 4;
}

auto main() -> int {
    auto fog = compose(f, g);
    
    std::println("result of composition is {}", fog(10));

    if constexpr (std::same_as<result_of_t<decltype(f)>, int>) {
        std::println("here we go.");
    }
    

    return 0;
}