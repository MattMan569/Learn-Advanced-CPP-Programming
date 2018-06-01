#pragma once

#include <iostream>
using namespace std;


template <class T>
class ring
{
private:
	int m_pos;
	int m_size;
	T * m_values;

public:
	// Declare iterator as a sub type of ring
	class iterator;


	ring(int size) : m_pos(0), m_size(size), m_values(NULL)
	{
		m_values = new T[size];
	}

	~ring()
	{
		delete[] m_values;
	}


	iterator begin()
	{
		// Specify pos 0, pass the ring object to the iterator
		// to gain access to be able to refer to member variables
		return iterator(0, *this);
	}

	iterator end()
	{
		// Specify last position
		return iterator(m_size, *this);
	}


	int size()
	{
		return m_size;
	}

	void add(T value)
	{
		m_values[m_pos] = value;

		m_pos++;

		// If the position has reached the end, circle back around
		// to the start of the buffer
		if (m_pos == m_size)
		{
			m_pos = 0;
		}
	}

	T & get(int pos)
	{
		return m_values[pos];
	}
};


// Not a free standing class, nested within ring
// Iterator class assumes the type of ring class
template <class T>
class ring<T>::iterator
{
private:
	int m_pos;
	ring & m_ring;

public:
	iterator(int pos, ring & buffer) : m_pos(pos), m_ring(buffer)
	{
		
	}


	// Specifying a type denotes this as the postfix version of the ++ operator
	iterator & operator++(int)
	{
		m_pos++;
		return *this;
	}

	// Prefix
	iterator & operator++()
	{
		m_pos++;
		return *this;
	}

	// Return the data from this iterator's position
	T & operator*()
	{
		return m_ring.get(m_pos);
	}

	bool operator!=(const iterator & other) const
	{
		// Iterators are not equal if their positions are not equal
		return m_pos != other.m_pos;
	}
};

