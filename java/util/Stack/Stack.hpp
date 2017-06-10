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

#ifndef NATIVE_JAVA_STACK_LIST_HPP
#define NATIVE_JAVA_STACK_LIST_HPP

#include <stack>
#include "../function/UnaryOperator/UnaryOperator.hpp"
#include "../Iterator/Iterator.hpp"
#include "../Collection/Collection.hpp"
#include "../Comparator/Comparator.hpp"

namespace Java {
    namespace Util {
        template <typename E>
        class Stack : public virtual Collection<E> {
            private:
			std::stack<E> original;
            public:
			Stack() {
			}
	                ~Stack() {
	                }
            public:
	
	        /**
		* Stack empty - check the Stack is empty or not
		*
		* @param original
		*/
	        bool empty() {
		        int size = this->original.size();
		        if (size != 0) {
			        return TRUE;
		        }
		        return FALSE;
	        }
	
	        /**
		* Stack peek - return the top element
		*
		* @param original
		*/
	        E peek() {
		        return this->original.top();
	        }
	
	        /**
		* Stack pop - return the top element and remove it
		*
		* @param original
		*/
	        E pop() {
		        E result = this->original.top();
		        this->original.pop();
		        return result;
	        }
	
	        /**
		* Stack push - Push new element
		*
		* @param original
		*/
	        E push(const E &item) {
		        this->original.push(item);
	        }
	
	        /**
		* Stack search - search the object in Stack, return the 1-based position from the top, -1 if can not find the object in Stack
		*
		* @param original
		*/
	        int search(const E &o) {
		        int position = 0;
		        int i;
		        for (i = 0; i < this->original.size(); i++) {
			        if (i == o) {
				        return i;
			        }
		        }
		        return -1;
	        }
	
	        boolean add(E &e) {
		        this->original.push(e);
	        }
	
	        /**
   * Size of Stack
   *
   * @param original
   */
	        int size() {
		        return this->original.size();
	        }
	
	        boolean addAll(Collection<E> &c) {
	        }
	        void clear() {
	        }
	        boolean contains(Object &o) const {
	        }
	        boolean equals(Object &o) const {
	        }
	        int hashCode() const {
	        }
	        boolean isEmpty() const {
	        }
	        Iterator<E> &iterator() const {
	        }
	        boolean remove(Object &o) {
	        }
	        boolean removeAll(Collection<Object> &c) {
	        }
	        boolean removeIf(Java::Util::Function::Predicate<E> &filter) {
	        }
	        boolean retainAll(Collection<Object> &c) {
	        }
	
	        int size() const {
		        return this->original.size();
	        }

        };
    }
}

#endif

