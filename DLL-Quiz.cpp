/*******************************************************************************
** CPSC 131: Part 1 - Sequence Containers
**           Doubly Linked List Quiz
**
** Implement the insert function for a doubly linked circular list with one dummy node that dynamically allocates nodes.
*
** Insert:
**   -  Return a pointer to the newly inserted node
**   -  Assume the pointer-to-Node called "position" is valid and points to an existing node in the list (no error checking needed)
** Hint:  Solutions should have no loops or decisions
*******************************************************************************/


#include <iomanip>
#include <string>
#include <iostream>
#include <new>
#include <stdexcept>
#include <utility>





template<typename T>
struct DLL
{
  struct Node
  {
    Node() = default;
    Node( T value ) : _data( std::move(value) ) {}

    T      _data = T{};
    Node * _next = this;
    Node * _prev = this;
  };

  Node        _sentinel;
  Node *&     _head = _sentinel._next;
  Node *&     _tail = _sentinel._prev;
  std::size_t _size = 0;



  Node * insert( Node * position, T const & data )
  {
    ///////////////////////// TO-DO (1) //////////////////////////////
    Node * newnode = new Node{data};
    if (position == begin()){
      newnode->_next = _sentinel._next;
      newnode->_prev = &_sentinel;
      _sentinel._next->_prev = newnode;
      _sentinel._next = newnode;
    } else if (position == end()){
      newnode->_next = &_sentinel;
      newnode->_prev = _sentinel._prev;
      _sentinel._prev->_next = newnode;
      _sentinel._prev = newnode;
    } else {
      newnode->_next = position;
      newnode->_prev = position->_prev;
      position->_prev->_next = newnode;
      position->_prev = newnode;
  }
  ++_size;
  return newnode;
    /////////////////////// END-TO-DO (1) ////////////////////////////
  }







  void print ()
  {
    constexpr unsigned minimumCount = 15;
    std::cout << '+' << std::string( minimumCount + 41*_size, '-' ) << "+\n"
              << '|' << std::string( minimumCount + 41*_size, ' ' ) << "|\n"
              << "+-> _sentinel";

    for (auto p = begin(); p != end(); p = p->_next)
    {
      std::cout << " <-> {" << std::setw( 14 ) << p->_prev << ", " << p->_data << ", " << std::setw( 14 ) << p->_next << "}";
    }

    std::cout << " <-+\n";

    std::cout << ' ' << std::setw( 14 ) << end();
    for (auto p = begin(); p != end(); p = p->_next)
    {
      std::cout << "             " << std::setw( 14 ) << p << "              ";
    }
    std::cout << '\n';


    std::cout << "_head -> " << (_size == 0 ? "_sentinel" : std::to_string(_head->_data)) << '\n'
              << "_tail -> " << (_size == 0 ? "_sentinel" : std::to_string(_tail->_data)) << '\n'
              << "_size  = " << _size << "\n\n\n";
  }


  Node * end()   { return &_sentinel; }
  Node * begin() { return _head;      }
};






int main()
{
  std::cout << std::setfill( '0' ) << std::showbase;



  DLL<unsigned int> theList;
  // Sketch the initial state of the list.
  // Be mindful to how you sketch.  Note the required 6 lines, attribute names, and the arrow syntax.  Be sure to not place your
  // sketch in comments (the autograder's code review pass ignores comments)
  // For example:
  #if 0
   +------------------------------------+
   |                                    |
   +-> _sentinel <-> 73 <-> 94 <-> 13 <-+
   _head -> 73
   _tail -> 13
   _size  =  3

     or

   +---------------+
   |               |
   +-> _sentinel <-+
   _head -> _sentinel
   _tail -> _sentinel
   _size  =  0

  ///////////////////////// TO-DO (2) //////////////////////////////

  /////////////////////// END-TO-DO (2) ////////////////////////////
  #endif
  theList.print();


  auto n1 = theList.insert( theList.begin(), 20 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  // Be mindful to how you sketch.  Note the required 6 lines, attribute names, and the arrow syntax
  #if 0
  ///////////////////////// TO-DO (3) //////////////////////////////
+------------------------+
|                        |
+-> _sentinel <-> 20 <-+
            
_head -> 20
_tail -> 20
_size  = 1
  /////////////////////// END-TO-DO (3) ////////////////////////////
  #endif


  theList.insert( n1, 10 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  // Be mindful to how you sketch.  Note the required 6 lines, attribute names, and the arrow syntax
  #if 0
  ///////////////////////// TO-DO (4) //////////////////////////////
+-----------------------------+
|                             |
+-> _sentinel <-> 10 <-> 20 <-+
            
_head -> 10
_tail -> 20
_size  = 2
  /////////////////////// END-TO-DO (4) ////////////////////////////
  #endif


  theList.insert( theList.end(), 40 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  // Be mindful to how you sketch.  Note the required 6 lines, attribute names, and the arrow syntax
  #if 0
  ///////////////////////// TO-DO (5) //////////////////////////////
+-----------------------------------+
|                                   |
+-> _sentinel <-> 10 <->20 <-> 40 <-+
_head -> 10
_tail -> 40
_size  = 3
  /////////////////////// END-TO-DO (5) ////////////////////////////
  #endif


  theList.insert( n1, 30 );
  theList.print();
  // Sketch the state of the list after the above operation has completed.
  // Be mindful to how you sketch.  Note the required 6 lines, attribute names, and the arrow syntax
  #if 0
  ///////////////////////// TO-DO (6) //////////////////////////////
+-------------------------------------------+
|                                           |
+-> _sentinel <-> 10 <-> 30 <-> 20 <-> 40 <-+
_head -> 10
_tail -> 40
_size  = 4
  /////////////////////// END-TO-DO (6) ////////////////////////////
  #endif
}
