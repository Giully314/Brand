// PURPOSE: define core operations on functions.
// TODO:
//  Add concepts.
//  Add operator * for function composition.

export module brand.core.function;

import std;

import brand.core.concepts;

export namespace brand::core {

// Add concepts. 
template <typename F, typename G>
    requires valid_composition<F, G>
auto compose(F f, G g) {
    return [f, g](auto&& x) {
        return f(g(std::forward<decltype(x)>(x)));
    };
}

template <typename T>
auto&& id(T&& x) {
    return std::forward<T>(x);
}

} // namespace brand::core
