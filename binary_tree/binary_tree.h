#ifndef _BINARY_TREE_H__
#define _BINARY_TREE_H__

/*----------------------------------------------------------------------------------------------*/

#include "../../bin/_mtLib/logger/logger.h"

/*----------------------------------------------------------------------------------------------*/

#define DEBUG_MODE_BTREE_ON__   1
#define DEBUG_MODE_BTREE_OFF__  0

#ifndef DEBUG_MODE_BTREE
    #define DEBUG_MODE_BTREE DEBUG_MODE_BTREE_OFF__
#endif // !DEBUG_MODE_BTREE


#if DEBUG_MODE_BTREE == DEBUG_MODE_BTREE_ON__
    #define DEBUG_CODE_ADD(...) __VA_ARGS__
#else
    #define DEBUG_CODE_ADD(...)
#endif

/*----------------------------------------------------------------------------------------------*/

typedef const char* BTreeElem_t;

struct Node {
    BTreeElem_t data;
    Node* left = nullptr;
    Node* right = nullptr;
};

struct Btree {
    Node* head;
};

#define BTreeConstructor(...)  _BTreeConstructor__(__VA_ARGS__)
int     _BTreeConstructor__(Btree* b_tree DEBUG_CODE_ADD(, LOCATION_VAR_CALL_STRUCT__ info_call));

#define BTreeDestructor(...) _BTreeDestructor__(__VA_ARGS__);
int     _BTreeDestructor__(Btree* b_tree DEBUG_CODE_ADD(, LOCATION_VAR_CALL_STRUCT__ info_call));

#define CreateNode(...) _CreateNode__(__VA_ARGS__)
Node* _CreateNode__(DEBUG_CODE_ADD(, LOCATION_VAR_CALL_STRUCT__ info_call));

#define DeleteNode(...) _DeleteNode__(__VA_ARGS__)
int _DeleteNode__(Node* node DEBUG_CODE_ADD(, LOCATION_VAR_CALL_STRUCT__ info_call));

#endif