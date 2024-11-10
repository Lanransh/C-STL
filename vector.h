#pragma once
#include<cstdint>
template<typename T>
class vector
{
public:
	using value_type = T;
	using size_type = std::size_t;
	using difference_type = std::ptrdiff_t;
	using pointer = T*;
	using reference = T&;
	using const_pointer = T const*;
	using const_reference = T const&;
	using iterator = T*;
	using const_iterator = T const*;
public:
	vector(const std::initializer_list<T> &ilist) {}
	iterator begin() {
		return nullptr;
	}
	iterator end() {
		return nullptr;
	}
};