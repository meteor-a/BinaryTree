#include "binary_tree.h"
#include "assert.h"
#include "malloc.h"

/*----------------------------------------------------------------------------------------------*/

const int _ERROR_CODE_SUCCESSFULL__ = 0;

/*----------------------------------------------------------------------------------------------*/

int _InizializeNode__(Node* node);

/*----------------------------------------------------------------------------------------------*/

int _BTreeConstructor__(Btree* b_tree DEBUG_CODE_ADD(, LOCATION_VAR_CALL_STRUCT__ info_call)) {
    assert(b_tree != nullptr);

    b_tree->head = (Node*) calloc(1, sizeof(Node*));
    assert(b_tree->head != nullptr);

    _InizializeNode__(b_tree->head);

    return _ERROR_CODE_SUCCESSFULL__;
}

int _BTreeDestructor__(Btree* b_tree DEBUG_CODE_ADD(, LOCATION_VAR_CALL_STRUCT__ info_call)) {
    if (b_tree->head) {
        _DeleteNode__(b_tree->head DEBUG_CODE_ADD(, info_call));
    }

    return _ERROR_CODE_SUCCESSFULL__;
}

/*----------------------------------------------------------------------------------------------*/

Node* _CreateNode__(DEBUG_CODE_ADD(, LOCATION_VAR_CALL_STRUCT__ info_call)) {
    Node* new_node = nullptr;
    new_node = (Node*)calloc(1, sizeof(Node*));
    assert(new_node != nullptr);

    _InizializeNode__(new_node);

    return new_node;
}

int _DeleteNode__(Node* node DEBUG_CODE_ADD(, LOCATION_VAR_CALL_STRUCT__ info_call)) {
    if (node->left)
        _DeleteNode__(node->left DEBUG_CODE_ADD(, info_call));
    if (node->right)
        _DeleteNode__(node->right DEBUG_CODE_ADD(, info_call));

    _InizializeNode__(node);
    free(node);

    return _ERROR_CODE_SUCCESSFULL__;
}

int _InizializeNode__(Node* node) {
    assert(node != nullptr);

    node->data  = "";
    node->left  = nullptr;
    node->right = nullptr;

    return _ERROR_CODE_SUCCESSFULL__;
}
