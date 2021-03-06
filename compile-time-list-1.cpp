#include "pch.h"

#include <iostream>
#include <string>


template<typename T, typename ... Args>
struct List
{
	typedef T             Head;
	typedef List<Args...> Tail;

	Head head;
	Tail tail;
	constexpr List() = default;
	constexpr List(const List&) = default;
	constexpr List(Head h, Args... t) : head(h), tail(t...) {}

	static constexpr int size() { return 1 + Tail::size(); }
};

struct Null {};

template<>
struct List<Null>
{
	typedef Null Head;
	Head head;
	constexpr List() = default;
	constexpr List(const List&) = default;
	constexpr List(Head h) : head(h) {}
	static constexpr int size() { return 0; }
};


template<typename ... Args>
constexpr auto make_list(Args... args)
{
	return List<Args..., Null>(args..., Null());
}


template<typename T, typename ... Args>
List<T, Args...> push_front(List<Args...> t, T h)
{
	List<T, Args...> res;
	res.head = h;
	res.tail = t;
	return res;
}

template<typename T, typename ... Args>
List<Args...> pop_front(List<T, Args...> l)
{
	return l.tail;
}

template<int I, typename T, typename ... Args>
struct Getter
{
	constexpr static auto get(List<T, Args...> l)
	{
		return Getter<I - 1, Args...>::get(l.tail);
	}
};

template<typename T, typename ... Args>
struct Getter<0, T, Args...>
{
	constexpr static auto get(List<T, Args...> l)
	{
		return l.head;
	}
};

template<int I, typename T, typename ... Args>
auto get(List<T, Args...> l)
{
	return Getter<I, T, Args...>::get(l);
}


template<typename T, typename ... Args>
std::ostream& operator<<(
	std::ostream& os, const List<T, Args...>& l)
{
	os << l.head << " " << l.tail;
	return os;
}

template<>
std::ostream& operator<<(
	std::ostream& os, const List<Null>& l) {
	return os;
}


int main()
{
	List<int, char, std::string, Null> l(1, 'c', "lala", Null());
	std::cout << l << std::endl;
	auto l2 = push_front(l, 0.7);
	std::cout << l2 << std::endl;
	auto l3 = pop_front(pop_front(l));
	static_assert(l3.size() == 1, "");
	std::cout << l3 << std::endl;
	std::cout << get<1>(l) << std::endl;
	auto l4 = make_list(1, 0.5, "lala");
	std::cout 
		<< get<0>(l4) << " "
		<< get<1>(l4) << " "
		<< get<2>(l4) << " "
		<< std::endl;
}




