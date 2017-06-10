/**
 * Copyright (c) 2016 Food Tiny Project. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef NATIVE_JAVA_UTIL_ARRAY_LIST_HPP
#define NATIVE_JAVA_UTIL_ARRAY_LIST_HPP

#include "../../lang/Cloneable/Cloneable.hpp"
#include "../../io/Serializable/Serializable.hpp"
#include "../AbstractList/AbstractList.hpp"
#include "../Collection/Collection.hpp"
#include "../RandomAccess/RandomAccess.hpp"
#include "../ListIterator/ListIterator.hpp"
#include "../List/List.hpp"
#include "../Comparator/Comparator.hpp"
#include "../Spliterator/Spliterator.hpp"
#include "../function/Consumer/Consumer.hpp"
#include "../function/Predicate/Predicate.hpp"
#include "../function/UnaryOperator/UnaryOperator.hpp"
#include <initializer_list>

using namespace Java::Lang;
using namespace Java::IO;
using namespace Java::Util::Function;

namespace Java {
	namespace Util {
		template <typename E>
		class ArrayList;
		
		template <typename E>
		class ArrayListIterator {
		public:
			ArrayListIterator(const ArrayList<E> *p_vec, int pos) : _pos(pos), _p_vec(p_vec) {

			}

			boolean operator!=(const ArrayListIterator<E> &other) const {
				return _pos != other._pos;
			}

			int operator*() const {
				return _p_vec->get(_pos);
			}

			const ArrayListIterator<E> &operator++() {
				++_pos;
				return *this;
			}

		private:
			int _pos;
			const ArrayList<E> *_p_vec;
		};
		template <typename E>
		class ArrayList :
			public virtual AbstractList<E>,
			public virtual Serializable,
			public virtual Cloneable,
			// public virtual List<E>,
			public virtual RandomAccess {
		private:
			std::vector<E> original;

		public:
			/**
			 * Constructs an empty list
			 */
			ArrayList() {

			}

			/**
			 * Constructs a list containing the elements of the specified collection
			 *
			 * @param c
			 */
			ArrayList(Collection<E> &c) {

			}

			/**
			 * Constructs an empty list with the specified initial capacity.
			 *
			 * @param initialCapacity
			 */
			ArrayList(int initialCapacity) {
				this->original.resize(initialCapacity);
			}

			/**
			 * Destructor ArrayList
			 */
			~ArrayList() {

			}

		public:
			/**
			 * @return
			 */
			ArrayListIterator<E> begin() const {
				return ArrayListIterator<E>(this, 0);
			}

			/**
			 *
			 * @return
			 */
			ArrayListIterator<E> end() const {
				return original.end();
			}

		public:

			/**
			 * Appends the specified element to the end of this list.
			 *
			 * @param e
			 * @return boolean
			 */
			boolean add(E &e) {
				this->original.push_back(e);
				return true;
			}

			/**
			 * Inserts the specified element at the specified position in this list.
			 *
			 * @param index
			 * @param element
			 */
			void add(int index, E &element)  {
				if (index < 0 || index > this->original.size() - 1) {
					return;
				}
				this->original.insert(this->original.begin() + index, element);
			}

			/**
			 * Appends all of the elements in the specified collection to the end of this list,
			 * in the order that they are returned by the specified collection's Iterator.
			 *
			 * @param c
			 * @return boolean
			 */
			boolean addAll(Collection<E> &c) {
				// TODO
				return true;
			}

			/**
			 * Inserts all of the elements in the specified collection into this list,
			 * starting at the specified position.
			 *
			 * @param index
			 * @param c
			 * @return boolean
			 */
			boolean addAll(int index, Collection<E> &c) {
				// TODO
				return true;
			}

			/**
			 * Removes all of the elements from this list.
			 *
			 */
			void clear() {
				this->original.clear();
			}

			/**
			 * Returns a shallow copy of this ArrayList instance.
			 *
			 * @return Object
			 */
			Object &clone() {
				// TODO
				Object c;
				return c;
			}

			/**
			 * Returns true if this list contains the specified element.
			 *
			 * @param o
			 * @return boolean
			 */
			boolean contains(Object &o) const {
				// TODO
				return true;
			}

			/**
			 * Increases the capacity of this ArrayList instance, if necessary,
			 * to ensure that it can hold at least the number of elements specified by
			 * the minimum capacity argument.
			 *
			 * @param minCapacity
			 */
			void ensureCapacity(int minCapacity) const {
				this->original.reserve(minCapacity);
			}

			/**
			 *  Performs the given action for each element of the Iterable until all elements
			 *  have been processed or the action throws an exception.
			 *
			 * @param action
			 */
			void forEach(Consumer<E> &action) const {
				// TODO
			}

			/**
			 * Returns the element at the specified position in this list.
			 *
			 * @param index
			 * @return
			 */
			E &get(int index) const {
				if (index < 0) return (E&)this->original.at(0);
				if (index > this->size() - 1) return (E&)this->original.at(this->size() - 1);
				return (E&) original.at(index);
			}

			/**
			 * Returns the index of the first occurrence of the specified element in this list,
			 * or -1 if this list does not contain the element.
			 *
			 * @param o
			 * @return int
			 */
			int indexOf(Object &o) const {
				return 0;
			}

			/**
			 * Returns true if this list contains no elements.
			 *
			 * @return boolean
			 */
			boolean isEmpty() const {
				return original.empty();
			}

			/**
			 * Returns an iterator over the elements in this list in proper sequence.
			 *
			 * @return Address of Iterator<E>
			 */
			Iterator<E> &iterator() const {
				// TODO
				Iterator<E> *it = new Iterator<E>();
				return *it;
			}

			/**
			 * Returns the index of the last occurrence of the specified element in this list,
			 * or -1 if this list does not contain the element.
			 *
			 * @param object
			 * @return int
			 */
			int lastIndexOf(Object &object) const {
				// TODO
				return 0;
			}

			/**
			 * Returns a list iterator over the elements in this list (in proper sequence).
			 *
			 * @return Address of ListIterator<E>
			 */
			ListIterator<E> &listIterator() const {
				// TODO
				ListIterator<E> *listIterator = new ListIterator<E>();
				return *listIterator;
			}

			/**
			 * Returns a list iterator over the elements in this list (in proper sequence),
			 * starting at the specified position in the list.
			 *
			 * @param index
			 * @return Address of ListIterator<E>
			 */
			ListIterator<E> &listIterator(int index) const {
				// TODO
				ListIterator<E> *listIterator = new ListIterator<E>();
				return *listIterator;
			}

			/**
			 * Removes the element at the specified position in this list.
			 *
			 * @param index
			 * @return Address of element
			 */
			E &remove(int index) {
				// TODO
				E *e = new E();
				return *e;
			}

			/**
			 * Removes the first occurrence of the specified element
			 * from this list, if it is present.
			 *
			 * @param object
			 * @return boolean
			 */
			boolean remove(Object &object) {
				// TODO
				return true;
			}

			/**
			 * Removes from this list all of its elements that are
			 * contained in the specified collection.
			 *
			 * @param target
			 * @return boolean
			 */
			boolean removeAll(Collection<Object> &target) {
				// TODO
				return true;
			}

			/**
			 * Removes all of the elements of this collection that satisfy the given predicate.
			 *
			 * @param filter
			 * @return boolean
			 */
			boolean removeIf(Predicate<E> &filter) {
				// TODO
				return true;
			}

			/**
			 * Replaces each element of this list with the result of applying
			 * the operator to that element.
			 *
			 * @param unaryOperator
			 */
			void replaceAll(UnaryOperator<E> &unaryOperator) {
				// TODO
			}

			/**
			 * Retains only the elements in this list that are contained
			 * in the specified collection.
			 *
			 * @param c
			 * @return
			 */
			boolean retainAll(Collection<Object> &c) {
				// TODO
				return true;
			}

			/**
			 * Replaces the element at the specified position in this list with
			 * the specified element.
			 *
			 * @param index
			 * @param element
			 * @return Adress of E
			 */
			E &set(int index, E &element) {
				// TODO
				E *e = new E();
				return *e;
			}

			/**
			 * Return the number of the all element of this list
			 *
			 * @return int
			 */
			int	size() const {
				return original.size();
			}

			/**
			 * Sorts this list according to the order induced by the specified Comparator.
			 *
			 * @param cmp
			 */
			void sort(Comparator<E> &cmp) {
				// TODO
			}

			/**
			 * Creates a late-binding and fail-fast Spliterator over the elements in this list.
			 *
			 * @return Spliterator<E>
			 */
			Spliterator<E>	&spliterator() const {
				// TODO
				Spliterator<E> *spliterator = new Spliterator<E>();
				return *spliterator;
			}

//			List<E> &subList(int fromIndex, int toIndex) const {
//				// TODO
//				List<E> *list = new ArrayList<E>();
//				return *list;
//			}

			/**
			 * Returns an array containing all of the elements in this
			 * list in proper sequence (from first to last element).
			 *
			 * @return Array<Object>
			 */
			Array<Object>	&toArray() {
				// TODO
				Array<Object> objects;
				return objects;
			}

			/**
			 * Returns an array containing all of the elements in this list
			 * in proper sequence (from first to last element);the runtime type of
			 * the returned array is that of the specified array.
			 *
			 * @tparam T
			 * @param a
			 * @return Array<T>
			 */
			template <typename T>
			Array<T> &toArray(Array<T> &a) const {
				// TODO
				return a;
			}

			/**
			 * Trims the capacity of this ArrayList instance to be the list's current size.
			 *
			 */
			void trimToSize() {
				// TODO
			}

			/**
			 * Convert ArrayList to string
			 *
			 * @return string
			 */
			string toString() const {
				return (string) "" ;
			}

		protected:
			/**
			 * Removes from this list all of the elements
			 * whose index is between fromIndex, inclusive, and toIndex, exclusive.
			 * Shifts any succeeding elements to the left (reduces their index).
			 *
			 * @param fromIndex
			 * @param toIndex
			 */
			void removeRange(int fromIndex, int toIndex) {
				// TODO
			}
		};
	
		template <typename E>

		class SubList : public virtual AbstractList<E> {
		private:
			AbstractList<E> l;
		};
	}
}

#endif//NATIVE_JAVA_UTIL_ARRAY_LIST_HPP
