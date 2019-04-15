/**
* Copyright 2017 Tiny Express Project. All rights reserved.
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

#ifndef NATIVE_JAVA_UTIL_COLLECTION_HPP
#define NATIVE_JAVA_UTIL_COLLECTION_HPP

#include "../../Lang/Iterable/Iterable.hpp"
#include "../Collection/Collection.hpp"
#include "../Spliterator/Spliterator.hpp"
#include "../../Util/function/Predicate/Predicate.hpp"
#include "../../Util/stream/Stream/Stream.hpp"

using namespace Java::Lang;

namespace Java {
		namespace Util {
				template <class E>
				class Collection;
				
				template <class E>
				class Collection : public virtual Iterable<E> {
				public:
						/**
						 * Add a element to this collection
						 * @param e
						 * @return boolean
						 */
						virtual boolean add(E &element) = 0;
						
						/**
						 * Add a Collection element to this collection
						 * @param c
						 * @return boealn
						 */
//			virtual boolean addAll(Collection<E> &c) = 0;//FIXME: should to implement foreach first
						
						/**
						 * Clear all element inside this collection
						 * @return
						 */
						virtual void clear() = 0;
						
						/**
						 * Search for specified object, return true if it occurs
						 * @param o
						 * @return boolean
						 */
						virtual boolean contains(E &element) = 0;
						
						/**
						 * Search for a Collection of object, return true if all element inside <c> occurs inside this collection
						 * @param c
						 * @return boolean
						 */
//			boolean containsAll(Collection<Object> &c);//FIXME: should to implement foreach first
						
						/**
						 * Compare object <o> with this collection through hashCode(), return true if it is equal
						 * @param o
						 * @return boolean
						 */
						virtual boolean equals(const Object &object) = 0;
						
						/**
						 * Make a hashcode through this virtual address on memory
						 * @return int
						 */
						virtual int hashCode() = 0;
						
						/**
						 * A hash code value for this object.
						 * @return int
						 */
						virtual boolean isEmpty() = 0;
						
						/**
						 * Don't support this method
						 * @return
						 */
						//			Java::Util::Stream::Stream<E> &parallelStream();
						
						/**
						 * Remove a specified object inside this collection, return true if it exits and be removed also
						 * @param o
						 * @return boolean
						 */
						virtual boolean remove(Object &object) = 0;
						
						/**
						 * Remove a collection of object inside this collection, return true if it exits and be removed all also
						 * @param c
						 * @return
						 */
						virtual boolean removeAll(Collection<Object> &collection) = 0;
						
						/**
						 * Don't support this method
						 * @param filter
						 * @return
						 */
//			virtual boolean removeIf(Java::Util::Function::Predicate<E> &filter) = 0;
						
						/**
						 * Don't support this method
						 * @return
						 */
//			virtual boolean retainAll(Collection<Object> &c) = 0;
						
						/**
						 * Return number of element inside this collection
						 * @return
						 */
						virtual int size() = 0;
						
						/**
						 * Don't support this method
						 * @return
						 */
//			Spliterator<E> &spliterator() {
//				Spliterator<E> spliterator;
//				return spliterator;
//			}
						
						/**
						 * Don't support this method
						 * @return
						 */
//			Java::Util::Stream::Stream<E> &stream() {
//				Java::Util::Stream::Stream<E> *stream = new Java::Util::Stream::Stream<E>();
//				return *stream;
//			}
						
						/**
						 * Don't support this method
						 * @return
						 */
//			Array<Object> &toArray() {
//				Array<Object> *array = new Array<Object>();
//				return *array;
//			}
						
						/**
						 * Don't suppor this method
						 * @param a
						 * @return
						 */
//			template <typename T>
//			Array<T> toArray(Array<T> &a) const;
				
				};
		}
}

#endif // NATIVE_JAVA_COLLECTION_HPP
