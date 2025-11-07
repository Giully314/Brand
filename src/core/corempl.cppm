// PURPOSE: Define type traits.

export module brand.core.mpl;

import std;

export namespace brand::core {

    /// @brief A list of types.
    /// @tparam ...TTypes 
    template <typename ...TTypes>
    struct typelist {}; 

    /// @brief Size of the typelist.
    /// @tparam T typelist.
    template <typename T>
    struct tlist_size;

    template <typename ...Args>
    struct tlist_size<typelist<Args...>> {
        static constexpr auto value = sizeof...(Args); 
    };

    /// @brief Get the front type of a typelist.
    /// @tparam T 
    template <typename T>
    struct tlist_front;

    template <typename T, typename ...Args>
    struct tlist_front<typelist<T, Args...>> {
        using type = T;
        using tail = typelist<Args...>;
    };

    template <typename T>
    using tlist_front_t = typename tlist_front<T>::type;

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

    /// @brief Info about the number of parameters a function takes.
    /// @tparam F The function type.
    template <typename F>
    struct arity_of {
        using function_type = decltype(std::function{std::declval<F>()});
        static constexpr auto value = tlist_size<params_of_t<F>>::value;
    };  

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
