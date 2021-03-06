/**
 * Copyright (c) 2016 Tiny Express Project. All rights reserved.
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

#include "../../../Test.hpp"
#include "Vector.hpp"

using namespace Java::Util;

TEST (JavaUtilVector, Constructor) {
    Vector<int> vector;
    assertEquals(10, vector.capacity());

    // Checks initial capacity.
    Vector<int> vector1(30);
    assertEquals(30, vector1.capacity());

    // Checks initial capacity and capacity increment.
    Vector<int> vector2(3, 2);
    assertEquals(0, vector2.size());
    assertEquals(3, vector2.capacity());
    vector2.add(1);
    assertEquals(1, vector2.size());
    assertEquals(3, vector2.capacity());
    vector2.add(2);
    assertEquals(2, vector2.size());
    assertEquals(3, vector2.capacity());
    vector2.add(3);
    assertEquals(3, vector2.size());
    assertEquals(3, vector2.capacity());

    // new capacity = old capacity + capacity increment.
    vector2.add(4);
    assertEquals(4, vector2.size());
    assertEquals(5, vector2.capacity());
}

TEST (JavaUtilVector, InitializerListConstructor) {
    // Given a vector construct from a std::initializer_list.
    Vector<int> vector{1, 2, 3, 4, 5};

    // Checks size.
    assertEquals(5, vector.size());

    // Check the first-last elements.
    assertEquals(1, vector.firstElement());
    assertEquals(5, vector.lastElement());
}

TEST (JavaUtilVector, CopyConstructor) {
    // Given a valid vector.
    Vector<int> target;
    target.add(1);
    target.add(2);
    target.add(3);
    target.add(4);
    target.add(5);

    // Use copy-constructor.
    Vector<int> vector(target);
    assertEquals(target.size(), vector.size());
    assertEquals(target.firstElement(), vector.firstElement());
    assertEquals(target.lastElement(), vector.lastElement());
}

TEST (JavaUtilVector, Add) {
    // Given a valid vector - check size and check the first - last element.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);
    vector.add(5);
    assertEquals(5, vector.size());
    assertEquals(1, vector.firstElement());
    assertEquals(5, vector.lastElement());

    // Add an element at specified index in vector
    // return that element at that index.
    vector.add(3, 100);
    assertEquals(100, vector.get(3));
    assertEquals(4, vector.get(4));

    // Test exception
    try {
        vector.add(-1, 100);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }

    try {
        vector.add(100, 100);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }
}

TEST (JavaUtilVector, AddAll) {
    // Given an empty vector.
    Vector<int> vector1;

    // Add all elements from initializer list.
    assertTrue(vector1.addAll({1, 2, 3, 4, 5}));

    // Checks size.
    assertEquals(5, vector1.size());

    // Check the first-last elements.
    assertEquals(1, vector1.firstElement());
    assertEquals(5, vector1.lastElement());

    // Given a valid vector.
    Vector<int> vector2;
    vector2.add(1);
    vector2.add(2);
    vector2.add(3);
    vector2.add(4);
    vector2.add(5);

    // Add initializer list at index 2.
    assertTrue(vector2.addAll(2, {7, 8, 9}));

    // Check the first-last element.
    assertEquals(8, vector2.size());
    assertEquals(1, vector2.firstElement());
    assertEquals(5, vector2.lastElement());

    // Check element at index 2.
    assertEquals(7, vector2.get(2));
}

TEST (JavaUtilVector, AddElement) {
    Vector<int> vector;
    vector.addElement(1);
    vector.addElement(2);
    vector.addElement(3);
    vector.addElement(4);
    vector.addElement(5);
    assertEquals(1, vector.firstElement());
    assertEquals(5, vector.lastElement());
}

TEST (JavaUtilVector, Clear) {
    // Given empty vector - return size of vector is 0.
    Vector<String> vector;
    assertEquals(0, vector.size());

    // Add three elements into vector - return size of vector is 3.
    vector.add("Hello");
    vector.add("World");
    vector.add("Vector");
    assertEquals(3, vector.size());

    // Clear all elements of vector - return size of vector is 0.
    vector.clear();
    assertEquals(0, vector.size());
}

TEST (JavaUtilVector, Clone) {
    // Given an empty vector, check size of cloned vector.
    Vector<int> vector;
    Vector<int> clonedVector1 = vector.clone();
    assertEquals(0, clonedVector1.size());

    // Given a valid vector, check size of cloned vector;
    // check first-last element.7
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);
    vector.add(5);
    Vector<int> clonedVector2 = vector.clone();
    assertEquals(5, clonedVector2.size());
    assertEquals(1, clonedVector2.firstElement());
    assertEquals(5, clonedVector2.lastElement());
}

TEST (JavaUtilVector, Contains) {
    // Given a valid vector - checks element exists or not.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);
    vector.add(5);
    assertFalse(vector.contains(0));
    assertTrue(vector.contains(5));
}

TEST (JavaUtilVector, ContainsAll) {
    // Given a valid vector.
    Vector<int> vector{1, 2, 3, 4, 5};

    // Checks vector for having all elements in a list.
    assertFalse(vector.containsAll({1, 2, 3, 4, 6}));
    assertTrue(vector.containsAll({1, 2, 3, 4, 5}));
}

TEST (JavaUtilVector, CopyInto) {
    Vector<int> vector{1, 2, 3, 4, 5};
    Array<int> anArray;
    vector.copyInto(anArray);
    assertEquals(vector.size(), anArray.length);
    int index;
    for (index = 0; index < vector.size(); index++) {
        assertEquals(vector.get(index), anArray.get(index));
    }
}

TEST (JavaUtilVector, ElementAt) {
    // Given a valid vector.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);
    vector.add(5);

    // Get element at the first and the last position.
    assertEquals(vector.firstElement(), vector.elementAt(0));
    assertEquals(vector.lastElement(), vector.elementAt(4));
}

TEST (JavaUtilVector, EnsureCapacity) {
    // Given an empty vector with initial capacity is 10 and capacity increment is 5.
    Vector<int> vector1(10, 5);
    assertEquals(10, vector1.capacity());

    // New capacity = old capacity + capacity increment.
    vector1.ensureCapacity(12);
    assertEquals(15, vector1.capacity());

    // New capacity = min capacity (because old capacity + capacity increment < min capacity).
    vector1.ensureCapacity(25);
    assertEquals(25, vector1.capacity());

    // Given an empty vector with initial capacity is 10 and capacity increment is 0.
    Vector<int> vector2(10, 0);

    // New capacity = old capacity * 2 (because capacity increment is zero).
    vector2.ensureCapacity(15);
    assertEquals(20, vector2.capacity());

    // New capacity = min capacity (because old capacity * 2 < min capacity).
    vector2.ensureCapacity(100);
    assertEquals(100, vector2.capacity());
}

TEST (JavaUtilVector, Equals) {
    // Given two valid vectors, check they are equals or not.
    Vector<int> vector1{1, 2, 3, 4, 5};
    Vector<int> target1{1, 2, 3, 5, 4};
    assertFalse(vector1.equals(target1));

    // Given two valid vector, check they are equals or not.
    Vector<int> vector2{1, 2, 3, 4, 5, 6, 7};
    Vector<int> target2{1, 2, 3, 4, 5, 6, 7};
    assertTrue(vector2.equals(target2));

    // Test different size
    Vector<int> vector3;
    Vector<int> target3;
    vector3.setSize(5);
    target3.setSize(10);
    assertFalse(vector3.equals(target3));
}

TEST (JavaUtilVector, FirstElement) {
    // Given a valid vector, contains three elements are string - return the first element.
    Vector<String> vector;
    vector.add("Hello");
    vector.add("World");
    vector.add("Vector");
    assertEquals("Hello", vector.firstElement().toString());

    // Test exception
    Vector<String> emptyVector;
    try {
        emptyVector.firstElement();
    } catch (Exception exception) {
        assertEquals("vector is empty", exception.getMessage());
    }
}

TEST (JavaUtilVector, Get) {
    // Given an valid vector with elements are string.
    Vector<String> vector;
    vector.add("Hello");
    vector.add("World");
    vector.add("I'm");
    vector.add("a");
    vector.add("Vector");

    // Get element at index 0, then index 4.
    assertEquals("Hello", vector.get(0).toString());
    assertEquals("Vector", vector.get(4).toString());

    // Test exception
    try {
        vector.get(-1);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }

    try {
        vector.remove(100);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }
}

TEST (JavaUtilVector, IsEmpty) {
    // Given an empty vector, vector is empty.
    Vector<int> vector;
    assertTrue(vector.isEmpty());

    // Add an element into vector, vector is not empty.
    vector.add(0);
    assertFalse(vector.isEmpty());
}

TEST (JavaUtilVector, IndexOf) {
    // Given a valid vector - return index of an element in vector.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(3);
    assertEquals(0, vector.indexOf(1));
    assertEquals(2, vector.indexOf(3));

    vector.clear();
    vector.add(1);
    vector.add(2);
    vector.add(4);
    vector.add(4);
    vector.add(5);
    assertEquals(-1, vector.indexOf(4, 4));
    assertEquals(2, vector.indexOf(4, 0));

    // Test exception
    try {
        vector.indexOf(4, -1);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }

    try {
        vector.indexOf(4, 100);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }
}

TEST (JavaUtilVector, InsertElementAt) {
    // Given a valid vector.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);
    vector.add(5);
    assertEquals(1, vector.firstElement());
    assertEquals(5, vector.lastElement());

    // Inserts an element.
    vector.insertElementAt(0, 0);

    // Checks that element after added.
    assertEquals(0, vector.get(0));
}

TEST (JavaUtilVector, LastElement) {
    // Given a valid vector, contains three elements are string - return the last element.
    Vector<String> vector;
    vector.add("Hello");
    vector.add("World");
    vector.add("Vector");
    assertEquals("Vector", vector.lastElement().toString());

    // Test exception
    Vector<String> emptyVector;
    try {
        emptyVector.lastElement();
    } catch (Exception exception) {
        assertEquals("vector is empty", exception.getMessage());
    }
}

TEST (JavaUtilVector, LastIndexOf) {
    // Given an valid vector - check last index of some elements.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(2);
    vector.add(2);
    vector.add(5);
    assertEquals(0, vector.lastIndexOf(1));
    assertEquals(3, vector.lastIndexOf(2));

    assertEquals(3, vector.lastIndexOf(2, 4));
    assertEquals(1, vector.lastIndexOf(2, 1));

    // Test exception

    try {
        vector.lastIndexOf(2, -1);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }

    try {
        vector.lastIndexOf(2, 100);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }
}

TEST (JavaUtilVector, Remove) {
    // Given empty vector, add three elements, remove at index 1 twice times, then remove at index 0.
    // Result is element that removed from vector.
    Vector<int> vector1;
    vector1.add(1);
    vector1.add(2);
    vector1.add(3);
    assertEquals(2, vector1.remove(1));
    assertEquals(3, vector1.remove(1));
    assertEquals(1, vector1.remove(0));

    // Check size of vector.
    assertEquals(0, vector1.size());

    // Given a valid vector, removes specified elements.
    Vector<String> vector2;
    vector2.add(String("1"));
    vector2.add(String("2"));
    vector2.add(String("3"));
    vector2.add(String("4"));
    vector2.add(String("5"));
//	assertFalse(vector2.remove(String("10"))); // This element doesn't exists.
//	assertTrue(vector2.remove(String("5")));

    Vector<Integer> vector3;
    vector3.add(Integer(1));
    vector3.add(Integer(2));
    vector3.add(Integer(3));
    vector3.add(Integer(4));
    vector3.add(Integer(5));
    vector3.remove(Integer(3));
    assertFalse(vector3.contains(Integer(3)));
    assertFalse(vector3.remove(Integer(10)));

    // Test execption
    try {
        vector1.remove(-1);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }

    try {
        vector1.remove(100);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }
}

TEST (JavaUtilVector, RemoveAll) {
    // Given a valid vector.
    Vector<int> vector({1, 2, 3, 4, 5});

    // Removes element appearing in the specified list.
    assertTrue(vector.removeAll({1, 2, 3}));

    // Checks size and the first-last element.
    assertEquals(2, vector.size());
    assertEquals(4, vector.firstElement());
    assertEquals(5, vector.lastElement());
}

TEST (JavaUtilVector, RemoveAllElements) {
    // Given empty vector - return size of vector is 0.
    Vector<String> vector;
    assertEquals(0, vector.size());

    // Add three elements into vector - return size of vector is 3.
    vector.add("Hello");
    vector.add("World");
    vector.add("Vector");
    assertEquals(3, vector.size());

    // Remove all elements of vector - return size of vector is 0.
    vector.clear();
    assertEquals(0, vector.size());
}

TEST (JavaUtilVector, RemoveElement) {
    Vector<Integer> vector;
    vector.add(Integer(1));
    vector.add(Integer(2));
    vector.add(Integer(3));
    vector.add(Integer(4));
    vector.add(Integer(5));

    vector.removeElement(Integer(3));
    assertEquals(4, vector.size());
    assertFalse(vector.contains(Integer(3)));
}

TEST (JavaUtilVector, RemoveElementAt) {
    // Given a valid vector.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);
    vector.add(5);

    // Removes element at index = 2.
    vector.removeElementAt(2);

    // Checks element value at index = 2.
    assertEquals(4, vector.get(2));
}

// This class use to call some protected methods in Vector class to run in test cases.
template<typename E>
class VectorFriend : public Vector<E> {
public:
    void removeRange(int fromIndex, int toIndex) {
        Vector<E>::removeRange(fromIndex, toIndex);
    }
};

TEST (JavaUtilVector, RemoveRange) {
    // Given a valid vector.
    VectorFriend<int> vector;
    vector.add(1); // 0
    vector.add(2); // 1
    vector.add(3); // 2
    vector.add(4); // 3
    vector.add(5);
    vector.add(6);
    vector.add(7);
    vector.add(8);

    // index: 0 1 2 3 4 5 6 7
    // value: 1 2 3 4 5 6 7 8
    // Removes elements at index: {1, 2}
    vector.removeRange(1, 3);

    // index: 0 1 2 3 4 5
    // value: 1 4 5 6 7 8
    assertEquals(1, vector.get(0));
    assertEquals(4, vector.get(1));

    // index: 0 1 2 3 4 5
    // value: 1 4 5 6 7 8
    // Remove element at index : {1, 1}
    vector.removeRange(1, 1);

    // index: 0 1 2 3 4
    // value: 1 5 6 7 8
    assertEquals(1, vector.get(0));
    assertEquals(5, vector.get(1));

    // Test Exception
    try {
        vector.removeRange(3, 1);
    } catch (IllegalArgumentException exception) {
        assertEquals("start index greater than end index", exception.getMessage());
    }

    try {
        vector.removeRange(-1, 5);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }

    try {
        vector.removeRange(100, 3);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }

    try {
        vector.removeRange(1, -1);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }

    try {
        vector.removeRange(1, 100);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }
}

TEST (JavaUtilVector, RetainAll) {
    Vector<int> vector{1, 2, 3, 4, 5};
    assertTrue(vector.retainAll({4, 5, 6}));
    assertEquals(2, vector.size());
    assertEquals(4, vector.firstElement());
    assertEquals(5, vector.lastElement());
}

TEST (JavaUtilVector, Set) {
    // Given a valid vector.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);
    vector.add(5);

    // Change element at index 0.
    assertEquals(1, vector.set(0, 10));

    // Check element at index 0.
    assertEquals(10, vector.get(0));

    // Change element at index 4.
    assertEquals(5, vector.set(4, 0));

    // Check element at index 4.
    assertEquals(0, vector.get(4));

    // Test index out of range
    try {
        vector.set(-1, 1302);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }

    try {
        vector.set(100, 1302);
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }


}

TEST (JavaUtilVector, SetElementAt) {
    // Given a valid vector.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);
    vector.add(5);

    // Change element at index 0.
    vector.setElementAt(10, 0);

    // Check element at index 0.
    assertEquals(10, vector.get(0));

    // Change element at index 4.
    vector.setElementAt(0, 4);

    // Check element at index 4.
    assertEquals(0, vector.get(4));
}

TEST (JavaUtilVector, SetSize) {
    // Given a valid vector.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);
    vector.add(5);
    vector.add(6);
    vector.add(7);
    vector.add(8);
    vector.add(9);

    // Set new size > original size
    vector.setSize(20);
    assertEquals(20, vector.size());

    // Sets size and checks size.
    vector.setSize(5);
    assertEquals(5, vector.size());

    // Set negative size
    try {
        vector.setSize(-1);
    } catch (IllegalArgumentException exception) {
        assertEquals("new size is negative", exception.getMessage());
    }
}

TEST (JavaUtilVector, Size) {
    // Given a empty vector, then add an element - return size.
    Vector<int> vector;
    vector.add(0);
    assertEquals(1, vector.size());

    // Remove the element at index 0 - return size.
    vector.remove(0);
    assertEquals(0, vector.size());

    // Add five elements into vector - return size.
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);
    vector.add(5);
    assertEquals(5, vector.size());
}

TEST (JavaUtilVector, ToArray) {
    // Given a valid vector.

    Vector<int> vector{1, 2, 3, 4, 5};
    // Copies vector to an array.

    Array<int> anArray = vector.toArray();
    // Check elements of vector and array at same order.
    int index;
    for (index = 0; index < vector.size(); index++) {
        assertEquals(vector[index], anArray[index]);
    }
}

TEST (JavaUtilVector, TrimToSize) {
    // Given a valid vector.
    Vector<int> vector;
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);
    vector.add(5);
    vector.add(6);

    // Trims the capacity to be the current size.
    vector.trimToSize();
    assertEquals(vector.size(), vector.capacity());

    // After removing an element, capacity is not equal with size.
    vector.remove(0);
    assertNotEquals(vector.size(), vector.capacity());
    vector.trimToSize();
    assertEquals(vector.size(), vector.capacity());
}

TEST (JavaUtilVector, RangeBasedForLoop) {
    // Given a valid vector.
    Vector<int> vector;
    vector.add(0);
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);

    // Using range-base-for-loop and checks element value.
    int index = 0;
    for (int element : vector) {
        assertEquals(index, element);
        index++;
    }
}

TEST (JavaUtilVector, ArrayOperator) {
    // Given a valid vector.
    Vector<int> vector;
    vector.add(0);
    vector.add(1);
    vector.add(2);
    vector.add(3);
    vector.add(4);

    // Accesses element value using array operator.
    int index;
    for (index = 0; index < vector.size(); index++) {
        assertEquals(index, vector[index]);
    }
    vector[0] = -1;
    assertEquals(-1, vector.get(0));

    // Test IllegalArgumentException
    try {
        vector[-1] = 1302;
    } catch (IllegalArgumentException exception) {
        assertEquals("index is out of range", exception.getMessage());
    }
}

TEST (JavaUtilVector, AssignmentOperator) {
    // Given an empty vector and add an element to it.
    Vector<int> vector;
    vector.add(-1);

    // Assigns with an initializer list.
    vector = {1, 2, 3, 4, 5};

    // Checks size and the first-last element.
    assertEquals(5, vector.size());
    assertEquals(1, vector.firstElement());
    assertEquals(5, vector.lastElement());

    // Given an target vector with some elements inside.
    Vector<int> target{10, 11, 12};

    // Assigns target to vector.
    vector = target;

    // Checks size and the first-last element.
    assertEquals(3, vector.size());
    assertEquals(10, vector.firstElement());
    assertEquals(12, vector.lastElement());
}
