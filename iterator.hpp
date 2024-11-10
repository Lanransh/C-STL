#ifndef M_ITERATOR_HPP
#define M_ITERATOR_HPP
#include <cstddef>
#include <type_traits>
#include <iostream>
#include "type_traits.hpp"

#endif // !M_ITERATOR_HPP
//定义 迭代器类别
namespace sh {
	struct input_iterator_tag {};	//读取
	struct output_iterator_tag {};	//写入   (不支持多次遍历同一元素
	struct forward_iterator_tag :public input_iterator_tag {};  //pr		//forward_iterator_tag 支持 input_iteraot_tag的所有操作，可以多次遍历元素
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag{};
	//bidirectional_iterator_tag和random_access_iterator_tag 的基础上增加 双向遍历里的能力，支持向前和向后
}
template<typename Category, typename T,typename Distance = std::ptrdiff_t,
			typename Pointer = T *,typename Reference = T&>
struct iterator {
	using iterator_category = Category;	//指定 该迭代器属于哪种类别，算法可以根据迭代器的类别来优化
	using value_type = T;				//迭代器锁指向的值的类类
	using difference_type = Distance;	//表示两个迭代器之间的距离
	using pointer = Pointer;			// 指向值的指针类型
	using reference = Reference;		//值的引用类型
	using const_pointer = T const*;		// 指向常量值的指针类型
	using const_reference = T const&;	//常量值的引用类型
};

template<typename Iterator>
struct iterator_traits {
	using itterator_category = typename Iterator::iterator_category;
	using value_type = typename Iterator::value_type;
	using difference_tpye = typename Iterator::difference_type;
	using pointer = typename Iterator::pointer;
	using reference = typename Iterator::reference;
};

template<typename T>
struct iterator_traits<T*> {
	using iterator_category = random_access_iterator_tag;
	using value_type = T;
	using difference_type = std::ptrdiff_t;
	using pointer == T*;
	using reference = T&;
};

template <typename T>
struct iterator_traits <T const*> {
	using iterator_category = random _access_iterator_tag;
	using value_type = const T;
	using difference_type = std::ptrdiff_t;
	using pointer = T const* ;
	using reference = T const& ;
};
template<typename Iterator> inline
typename iterator_traits<Iterator>::difference_tpye
iterator_category(Iterator const&);

template<typename Iterator> inline
typename iterator_traits<Iterator>::diffeence_type
distance_type(Iterator const&);

template <typename Iterator> inline
typename iterator_traits<Iterator>::value_type
iterator_value_type(Iterator const&);

template<typename InputIterator> inline
typename iterator_traits<InputIterator>:: difference_type
__distance_aux(InputIterator first, InputIterator last, input_iterator_tag)
{

}