// PURPOSE: define core operations on functions.
// TODO:
//  Add concepts.
//  Add operator * for function composition.

export module brand.core.function;

import std;

export namespace brand::core {

// Add concepts. 
// template <typename F, typename G>
auto compose(auto f, auto g) {
    return [f, g](auto x) {
        return f(g(x));
    };
}

template <typename T>
auto&& id(T&& x) {
    return std::forward<T>(x);
}

} // namespace brand::core
