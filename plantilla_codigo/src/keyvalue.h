/*
 * file:   keyvalue.h
 * Desc:   Specification / Implementation of the Key/Value structure
 * Author: Juan A. Rico  (jarico@unex.es)
 * Date:   30 / 03 / 2022
 */

#ifndef _KEYVALUE_H
#define _KEYVALUE_H


#include <iostream>

using namespace std;

/*
 *  KeyValue
 *  Class of pairs of elements <Key-Value> to store in order of KEY.
 *  (Please, see documentation below)
 */

///////////////////////////////////////////////
////      CLass  KeyValue  INTERFACE
///////////////////////////////////////////////

template<class KEY, class VALUE>
class KeyValue {
	
private:
	
	KEY    _key;
	VALUE  _value;
	
public:
	
  KeyValue           ();
  KeyValue           (KEY key);
  KeyValue           (KEY key, VALUE value);

  KEY    key         ();
  VALUE  value       ();
	
  bool   operator<   (const KeyValue &kv) const;
  bool   operator>   (const KeyValue &kv) const;
  bool   operator==  (const KeyValue &kv) const;
  bool   operator!=  (const KeyValue &kv) const;
  void   operator=   (const KeyValue &kv);
	
};



/*
 *
 *  Class KeyValue:
 
      // Default constructor
      // Pre  = {}
      // Post = {key()==<empty>, value()==<empty>}
      KeyValue  ();

      // Parametrized constructor
      // Pre  = {}
      // Post = {key()==key, value()==<empty>}
      KeyValue  (KEY key);

      // Parametrized constructor
      // Pre  = {}
      // Post = {key()==key, value()==value}
      KeyValue  (KEY key, VALUE value);

      // Return "key" part of the object
      // Pre  = {}
      // Post = {}
      // Complexity:   O(1)
      KEY   key     ();

      // Return "value" part of the object
      // Pre  = {}
      // Post = {}
      // Complexity:   O(1)
      VALUE value   ();

      // Compare two KeyValue objects using "key"
      // Pre  = {}
      // Post = {}
      // Complexity:   O(1)
      bool  operator<   (const KeyValue &kv) const;

      // Compare two KeyValue objects using "key"
      // Pre  = {}
      // Post = {}
      // Complexity:   O(1)
      bool  operator>   (const KeyValue &kv) const;

      // Compare two KeyValue objects using "key"
      // Pre  = {}
      // Post = {}
      // Complexity:   O(1)
      bool  operator==  (const KeyValue &kv) const;

      // Compare two KeyValue objects using "key"
      // Pre  = {}
      // Post = {}
      // Complexity:   O(1)
      bool  operator!=  (const KeyValue &kv) const;

      // Assign two KeyValue objects
      // Pre  = {}
      // Post = {}
      // Complexity:   O(1)
      void  operator=   (const KeyValue &kv);
 */




// Implementation

template<class KEY, class VALUE>
KeyValue<KEY,VALUE>::KeyValue () {
}

template<class KEY, class VALUE>
KeyValue<KEY,VALUE>::KeyValue (KEY key) {
  this->_key   = key;
}

template<class KEY, class VALUE>
KeyValue<KEY,VALUE>::KeyValue (KEY key, VALUE value) {
  this->_key   = key;
  this->_value = value;
}

template<class KEY, class VALUE>
KEY KeyValue<KEY,VALUE>::key () {
  return this->_key;
}

template<class KEY, class VALUE>
VALUE KeyValue<KEY,VALUE>::value () {
  return this->_value;
}

template<class KEY, class VALUE>
bool KeyValue<KEY,VALUE>::operator< (const KeyValue &kv) const {
  if (this->_key < kv._key)
    return true;
  return false;
}

template<class KEY, class VALUE>
bool KeyValue<KEY,VALUE>::operator> (const KeyValue &kv) const {
  if (this->_key > kv._key)
    return true;
  return false;
}

template<class KEY, class VALUE>
bool KeyValue<KEY,VALUE>::operator== (const KeyValue &kv) const {
  if (this->_key == kv._key)
    return true;
  return false;
}

template<class KEY, class VALUE>
bool KeyValue<KEY,VALUE>::operator!= (const KeyValue &kv) const {
  if (this->_key != kv._key)
    return true;
  return false;
}

template<class KEY, class VALUE>
void KeyValue<KEY,VALUE>::operator= (const KeyValue &kv) {
  this->_key   = kv._key;
  this->_value = kv._value;
}



#endif /* _KEYVALUE_H */


