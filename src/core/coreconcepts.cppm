// PURPOSE: Define concepts.

export module brand.core.concepts;

import std;
import brand.core.type_traits;
import brand.core.mpl;

export namespace brand::core {
   
template <typename F>
concept regular_callable = is_callable_v<F>;

template <typename F>
concept unary_function = regular_callable<F> && arity_of<F>::value == 1;

// TODO: Must also check type qualifiers? 
/// @brief Check if the 2 functions can be composed into one.
template <typename F, typename G>
concept valid_composition = unary_function<F> && unary_function<G> && 
    std::same_as<result_of_t<F>, tlist_front_t<params_of_t<G>>>;
    
} // namespace brand::core
