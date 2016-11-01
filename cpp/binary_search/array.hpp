
#ifndef ARRAY_H 
#define ARRAY_H 

#include <ostream>
#include <vector>

template <class T> 
class Array : public std::vector <T>
{
	public:

	bool isSorted () const
	{
		int prev_sign = 0; 
		int curr_sign;
		for (int i = 0; i < this->size() - 1; ++i)
		{
			curr_sign = (*this)[i] - (*this)[i+1];	
			if (prev_sign != 0)
			{
				if (prev_sign * curr_sign < 0)
					return false;
			}
			prev_sign = curr_sign;
		}
		return true;
	}

	int binary_search (const T & key) const
	{
		int len = this->size();
		if (len == 0)
			return -1;

		int lo = 0;
		int hi = len-1;
		int mid; 

		while (lo < hi)
		{
			mid = lo / 2 + hi / 2; 
			if (key > (*this)[mid])
				lo = mid + 1;
			else 
				hi = mid;
		}
		return (*this)[hi] == key ? hi : -1;
	}

	friend std::ostream & operator << (
	std::ostream & stream, 
	const Array <T> & array) 
	{
		stream << "{";
		for (int i = 0; i < array.size(); ++i)
		{
			stream << array[i];
			if (i != array.size()-1)
				stream << ", ";
		}
		stream << "}" << std::endl;
		return stream;
	}
};

#endif
