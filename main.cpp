#include <string>
#include <iostream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <string>
#include <concepts>
#include <optional>

template<typename T>
concept HasMappend = requires(T a, T b) {
    {a.mappend(a, b)} -> std::same_as<T>;
};

template<typename T>
concept HasMempty = requires(T a) {
    {a.mempty()} -> std::same_as<T>;
};

template<typename T>
concept Monoid = HasMappend<T> && HasMempty<T>;

struct Any {
    Any() : value{} {}
    Any(bool value) : value{value} {}
    bool value{false};
    static Any mempty(Any a = Any{}) { return Any{};}
    static Any mappend(Any a, Any b) { return a.value || b.value;}
};

struct All {
    All() : value{} {}
    All(bool value) : value{value} {}
    bool value{true};
    static All mempty(All a = All{}) { return All{};}
    static All mappend(All a, All b) { return a.value && b.value;}
};

static_assert(Monoid<Any>);
static_assert(Monoid<All>);

template<Monoid T>
T fold(std::vector<T> vec) {
    auto result = T::mempty();
    for (const auto& item : vec) {
        result = T::mappend(result, item);
    }
    return result;
}

int main() {
    auto collection_of_monoids = std::vector<Any>{{true}, {false}, {false}, {false}};

    return fold(collection_of_monoids).value ? 42 : 0;
}