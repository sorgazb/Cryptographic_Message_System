/*
 * bstree.h
 *
 *  Created on: Mar. 2022
 *      Author: Juan A. Rico (jarico@unex.es)
 */


#ifndef _BSTREE_H
#define _BSTREE_H


#include <iostream>
using namespace std;


/*
 * BSTree
 *
 * Binary Search Tree.
 * Implemented with templates.
 * (The BSTree could store elements of any type, including simple types, objects and pointers.)
 * Please, see documentation details below.
 *
 */

template <class TYPE>
class BSTree {

private:

	TYPE          nData;
	BSTree<TYPE> *tLeft;
	BSTree<TYPE> *tRight;

	bool  isEmpty;

	BSTree<TYPE> *removeOrder (TYPE data);

public:

	 BSTree  ();
	 BSTree  (BSTree<TYPE> *tLeft,TYPE nData,BSTree<TYPE> *tRight);
	~BSTree  ();

	BSTree  *left    ();
	BSTree  *right   ();
	TYPE     root    ();

	bool     empty   ();
	void     insert  (const TYPE &data);
	void     remove  (      TYPE  data);
	bool     exist   (const TYPE &data);
};


/*
 *  CLASS BSTree

    BSTree     ();
   ~BSTree     ();

    // Descr.: create a new BSTree from two children and a root node.
    // Complexity: O(1)
    BSTree     (BSTree<TYPE> *tLeft,TYPE nData,BSTree<TYPE> *tRight);

   // Descr.: return the left subtree of a node
   // Pre  = { BSTree != nullptr }
   // Post = { }
   // Complexity: O(log n)
   BSTree  *left  ();

   // Descr.: return the right subtree of a node
   // Pre  = { BSTree != nullptr }
   // Post = { }
   // Complexity: O(log n)
   BSTree  *right ();
   
   // Descr.: return the root node oa a tree
   // Pre  = { BSTree != nullptr }
   // Post = { }
   // Complexity: O(log n)
   TYPE  root    ();

   // Descr.: return true if BSTree is empty (has no nodes)
   // Complexity: O(1)
   bool  empty   ();
   
   // Descr.: insert a new node
   // Pre  = { exist(data) == false }
   // Post = { empty(BSTree) = false }
   // Complexity: O(log n)
   void  insert  (const TYPE &data);
   
   // Descr.: remove a node by value
   // Pre  = { BSTree != nullptr }
   // Post = { exist(data) == false }
   // Complexity: O(log n)
   void  remove  (      TYPE  data);
   
   // Descr.: return true is a node exist in a tree
   // Pre  = { BSTree != nullptr }
   // Post = { }
   // Complexity: O(log n)
   bool  exist   (const TYPE &data);
   
*/




//   Implementation:

template <class TYPE>
BSTree<TYPE>::BSTree() {

	isEmpty = true;
	tLeft   = nullptr;
	tRight  = nullptr;
}


template <class TYPE>
BSTree<TYPE>::BSTree (BSTree<TYPE> *tLeft, TYPE data, BSTree<TYPE> *tRight) {

	isEmpty = false;
	this->nData  = data;
	this->tLeft  = tLeft;
	this->tRight = tRight;
}


template <class TYPE>
BSTree<TYPE>::~BSTree() {

   BSTree<TYPE> *aux;

   if (!empty()) {

      aux = left();
      if (aux != nullptr) {
         delete aux;
      }

      aux = right();
      if (aux != nullptr) {
         delete aux;
      }

      isEmpty = true;
   }
}


template <class TYPE>
BSTree<TYPE> *BSTree<TYPE>::left() {

	return this->tLeft;
}


template <class TYPE>
BSTree<TYPE> *BSTree<TYPE>::right() {

	return this->tRight;
}


template <class TYPE>
TYPE BSTree<TYPE>::root() {

	return this->nData;
}


template <class TYPE>
bool BSTree<TYPE>::empty() {

	return this->isEmpty;
}


template <class TYPE>
void BSTree<TYPE>::insert (const TYPE &data) {

	if (empty()) {

		nData   = data;
		isEmpty = false;

	} else {

		if (data != this->nData) {

			BSTree<TYPE> *aux;

			if (data < nData) {
				aux = left();
				if (aux == nullptr) {
					tLeft = aux = new BSTree<TYPE>();
				}
			} else {
				aux = right();
				if (aux == nullptr) {
					tRight = aux = new BSTree<TYPE>();
				}
			}
			aux->insert(data);

		}
	}
}


template <class TYPE>
void BSTree <TYPE>::remove(TYPE data) {

	if (!empty()) {

		if (data < this->nData) {

         if (tLeft != nullptr) {
				tLeft = tLeft->removeOrder(data);
         }

		} else if (data > this->nData) {

         if (tRight != nullptr) {
				tRight = tRight->removeOrder(data);
         }
			
		} else {

			if ((tLeft == nullptr) && (tRight == nullptr)) {
				isEmpty = true;
			} else {
				removeOrder(data);
			}

		}

	}
}


/*
 * Auxiliar method to remove a node. It rebuilds the tree after removing.
 * Possibilities:
 * 	a) The node has not children (it is a leaf): it is removed.
 * 	b) The node has one child: the node is replaced by the child node.
 * 	c) The node has two children: the node is replaced by the higher value in its left subtree.
 * Complexity: O(log(n))
 */
template <class TYPE>
BSTree<TYPE> *BSTree<TYPE>::removeOrder (TYPE data) {

	TYPE dataaux;
	BSTree *toreturn = this, *toremove, *candidate, *ancestor;

	if (!empty()) {

		if (data < this->nData) {

         if (tLeft != nullptr) {
				tLeft = tLeft->removeOrder(data);
         }

		} else if (data > this->nData) {
         if (tRight != nullptr) {
				tRight = tRight->removeOrder(data);
         }

		} else {

			toremove=this;

			// 1. It is a leaf
			if ((tRight == nullptr) && (tLeft == nullptr)) {

				delete toremove;
				toreturn = nullptr;

			} else {

				// 2. It has only one child
				// 2.1. Only the left child:
				if (tRight == nullptr) {

					toremove = tLeft;
					dataaux = nData;
					nData = tLeft->root();
					tLeft->nData = dataaux;
					tLeft = tLeft->left();
					tRight = toremove->right();

					toreturn = this;

					// 2.2. Only the right child:
				} else if (tLeft == nullptr) {

					toremove = tRight;
					dataaux = nData;
					nData = tRight->root();
					tRight->nData = dataaux;
					tRight = tRight->right();
					tLeft = toremove->left();

					toreturn = this;

					// 3. It has two children.
				} else {

					candidate = left();
					ancestor = this;
					while (candidate->right()) {
						ancestor = candidate;
						candidate = candidate->right();
					}

					// Exchange of candidate data
					dataaux = nData;
					nData = candidate->root();
					candidate->nData = dataaux;
					toremove = candidate;
					if (ancestor == this) {
						tLeft = candidate->left();
					} else {
						ancestor->tRight = candidate->left();
					}
				}

				// Remove the node (not the whole subtree)
				toremove->tLeft  = nullptr;
				toremove->tRight = nullptr;
				delete toremove;
			}
		}

	}

	return toreturn;
}


template <class TYPE>
bool BSTree<TYPE>::exist (const TYPE &data) {

	bool enc = false;

	if (empty()) {

		enc  = false;

	} else {

		BSTree<TYPE> *aux;

		if (data < this->nData) {

			aux = left();
         if (aux != nullptr) {
				enc = aux->exist(data);
         }

		} else if (data > this->nData) {

			aux = right();
         if (aux != nullptr) {
				enc = aux->exist(data);
         }

		} else {
			enc = true;
		}

	}

	return enc;
}


#endif /* _BSTREE_H_ */


