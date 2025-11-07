// PURPOSE: Define type traits.

export module brand.core.type_traits;

import brand.core.mpl;

import std;

export namespace brand::core {
    template <typename F, typename ArgList> 
    struct is_callable : std::false_type {};

    template <typename F, typename ...Args>
        requires std::invocable<F, Args...>
    struct is_callable<F, typelist<Args...>> : std::true_type {};
    
    template <typename F>
    inline constexpr bool is_callable_v = is_callable<F, params_of_t<F>>::value;
} // namespace brand::core
