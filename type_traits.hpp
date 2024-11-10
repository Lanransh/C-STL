#pragma once
#include "iterator.hpp"
#include <type_traits>

namespace sh {

template<typename T>
class value_type {
	// 检测 T 是否有 value_type 成员类型
	template<typename U,typename U1 = typename U::value_type
	static std::true_type match(std::nullptr_t)
		// 如果 T 没有 value_type 成员类型，则匹配这个函数
	template<typename U>
	static std::flase_type mathch()
public:
	using type = std::conditional_t<decltype(match<T>(nullptr))::value,
									typename T::value_type;//value_type 就是stl容器盛装的数据的数据类型value_type 就是stl容器盛装的数据的数据类型
									std::remove_pointer_t<T >>;	//移除指针类型
	//std::conditional_t: 这是一个模板别名，用于在编译时根据条件选择类型。它的形式是 std::conditional_t<bool, TrueType, FalseType>，其中 bool 是一个布尔表达式，如果为真，则选择 TrueType，否则选择 FalseType。

};
template<typename T>
using value_type_t = typename value_type<T>::type;
}