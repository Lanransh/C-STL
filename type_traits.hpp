#pragma once
#include "iterator.hpp"
#include <type_traits>

namespace sh {

template<typename T>
class value_type {
	// ��� T �Ƿ��� value_type ��Ա����
	template<typename U,typename U1 = typename U::value_type
	static std::true_type match(std::nullptr_t)
		// ��� T û�� value_type ��Ա���ͣ���ƥ���������
	template<typename U>
	static std::flase_type mathch()
public:
	using type = std::conditional_t<decltype(match<T>(nullptr))::value,
									typename T::value_type;//value_type ����stl����ʢװ�����ݵ���������value_type ����stl����ʢװ�����ݵ���������
									std::remove_pointer_t<T >>;	//�Ƴ�ָ������
	//std::conditional_t: ����һ��ģ������������ڱ���ʱ��������ѡ�����͡�������ʽ�� std::conditional_t<bool, TrueType, FalseType>������ bool ��һ���������ʽ�����Ϊ�棬��ѡ�� TrueType������ѡ�� FalseType��

};
template<typename T>
using value_type_t = typename value_type<T>::type;
}