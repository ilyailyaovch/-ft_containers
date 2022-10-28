#ifndef FT_RANDOM_ACCESS_ITERATOR_HPP
# define FT_RANDOM_ACCESS_ITERATOR_HPP

# include "iterator.hpp"

namespace	ft
{
	template <typename T>
	// class random_access_iterator : public ft::iterator <ft::random_access_iterator_tag, T>
	class	random_access_iterator : public ft::iterator<	typename ft::iterator_traits<T *>::iterator_category,
															typename ft::iterator_traits<T *>::value_type>
	{
		public:
			/*	Member types defines */
			typedef std::iterator<ft::random_access_iterator_tag, T>	iterator_type;
			//typedef ft::iterator<ft::random_access_iterator_tag, T>	iterator_type;
			typedef typename iterator_type::iterator_category			iterator_category;	// std for unit tests
			typedef typename iterator_type::value_type					value_type;			// T
			typedef typename iterator_type::difference_type				difference_type;	// std::ptrdiff_t
			typedef typename iterator_type::pointer						pointer;			// T *
			typedef typename iterator_type::reference					reference;			// T &
			typedef const reference										const_reference;	// const T &
		public:
			/*	Canonical form */
			random_access_iterator();
			random_access_iterator(pointer ptr);
			random_access_iterator(const random_access_iterator &other);
			random_access_iterator&		operator=(const random_access_iterator &other);
			virtual						~random_access_iterator();
		public:
			/*	Property */
			bool							operator==(const random_access_iterator &other) const;
			bool							operator!=(const random_access_iterator &other) const;
			reference						operator*() const						{return (*(_elem));}
			pointer							operator->() const						{return (_elem);}
			random_access_iterator<T>&		operator++();	// prefix
			random_access_iterator<T>&		operator--();
			random_access_iterator<T>		operator++(int);// postfix	
			random_access_iterator<T>		operator--(int);
			reference						operator[](difference_type num) const	{return *(_elem + num);}
			random_access_iterator<T>		operator+(difference_type num) const;
			random_access_iterator<T>		operator-(difference_type num) const;
			difference_type					operator-(const random_access_iterator<T> &other) const;
			random_access_iterator<T>&		operator+=(difference_type num);  
			random_access_iterator<T>&		operator-=(difference_type num);
			bool							operator>(const random_access_iterator<T> &other) const;
			bool							operator<(const random_access_iterator<T> &other) const;
			bool							operator>=(const random_access_iterator<T> &other) const;
			bool							operator<=(const random_access_iterator<T> &other) const;
			pointer							base() const;
		protected:
			pointer						_elem;
	};	//end of "random_access_iterator"

	/*	Non-member functions */

	template <typename T_L, typename T_R>
	typename random_access_iterator<T_L>::difference_type
	operator-(	const random_access_iterator<T_L> &lhs,
				const random_access_iterator<T_R> &rhs);

	template <typename T_L, typename T_R>
	bool operator>(	const random_access_iterator<T_L> &lhs,
					const random_access_iterator<T_R> &rhs);

	template <typename T_L, typename T_R>
	bool operator<(	const random_access_iterator<T_L> &lhs,
					const random_access_iterator<T_R> &rhs);

	template <typename T_L, typename T_R>
	bool operator>=(const random_access_iterator<T_L> &lhs,
					const random_access_iterator<T_R> &rhs);

	template <typename T_L, typename T_R>
	bool operator<=(const random_access_iterator<T_L> &lhs,
					const random_access_iterator<T_R> &rhs);

	template <typename T_L, typename T_R>
	bool operator==(const random_access_iterator<T_L> &lhs,
					const random_access_iterator<T_R> &rhs);

	template <typename T_L, typename T_R>
	bool operator!=(const random_access_iterator<T_L> &lhs,
					const random_access_iterator<T_R> &rhs);

	template <typename T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type n,
										random_access_iterator<T> &rhs);

}	//end of "namespace	ft"

# include "random_access_iterator.tpp"

#endif