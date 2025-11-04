// PURPOSE: Define type traits.

export module brand.core.mpl;

import std;

export namespace brand::core {
   template <typename ...TTypes>
   struct typelist {}; 


   // ************** CALLABLE INFO *************

   /// @brief Info about type of parameters and return type of a callable.
   /// @tparam F The type of the function.
   template <typename F>
   struct callable_info;

    template <typename Result, typename ...Args>
    struct callable_info<std::function<Result(Args...)>> {
        using return_t = Result;
        using params = typelist<Args...>;
    };

    /// @brief Info about the parameters of a function.
    /// @tparam F The function type.
    template <typename F>
    struct params_of {
        using function_type = decltype(std::function{std::declval<F>()});
        using type = typename callable_info<function_type>::params;
    };

    template <typename F>
    using params_of_t = typename params_of<F>::type;

    /// @brief Info about the return type of a function.
    /// @tparam F The function type.
    template <typename F>
    struct result_of {
        using function_type = decltype(std::function{std::declval<F>()});
        using type = typename callable_info<function_type>::return_t;
    };

    template <typename F>
    using result_of_t = typename result_of<F>::type;
    
} // namespace brand::core
