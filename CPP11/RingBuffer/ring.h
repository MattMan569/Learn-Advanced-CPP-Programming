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
	ring(int size) : m_pos(0), m_size(size), m_values(NULL)
	{
		m_values = new T[size];
	}

	~ring()
	{
		delete[] m_values;
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


	// Declare iterator as a sub type of ring
	class iterator;
};


// Not a free standing class, nested within ring
// Iterator class assumes the type of ring class
template <class T>
class ring<T>::iterator
{
public:
	void print()
	{
		cout << "Hello from iterator" << endl;
	}
};

