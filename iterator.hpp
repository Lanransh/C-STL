#ifndef M_ITERATOR_HPP
#define M_ITERATOR_HPP
#include <cstddef>
#include <type_traits>
#include <iostream>
#include "type_traits.hpp"

#endif // !M_ITERATOR_HPP
//���� ���������
namespace sh {
	struct input_iterator_tag {};	//��ȡ
	struct output_iterator_tag {};	//д��   (��֧�ֶ�α���ͬһԪ��
	struct forward_iterator_tag :public input_iterator_tag {};  //pr		//forward_iterator_tag ֧�� input_iteraot_tag�����в��������Զ�α���Ԫ��
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag{};
	//bidirectional_iterator_tag��random_access_iterator_tag �Ļ��������� ˫��������������֧����ǰ�����
}
template<typename Category, typename T,typename Distance = std::ptrdiff_t,
			typename Pointer = T *,typename Reference = T&>
struct iterator {
	using iterator_category = Category;	//ָ�� �õ�����������������㷨���Ը��ݵ�������������Ż�
	using value_type = T;				//��������ָ���ֵ������
	using difference_type = Distance;	//��ʾ����������֮��ľ���
	using pointer = Pointer;			// ָ��ֵ��ָ������
	using reference = Reference;		//ֵ����������
	using const_pointer = T const*;		// ָ����ֵ��ָ������
	using const_reference = T const&;	//����ֵ����������
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