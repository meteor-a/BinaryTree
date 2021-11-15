#include "binary_tree.h"
#include "assert.h"
#include "malloc.h"
#include <stdio.h>

/*----------------------------------------------------------------------------------------------*/

const int _ERROR_CODE_SUCCESSFULL__ = 0;

/*----------------------------------------------------------------------------------------------*/

int _InizializeNode__(Node* node);
int _PrintfGraph__(Node* node, int num_node_left, int num_node_right, FILE* graph_file, int side);

/*----------------------------------------------------------------------------------------------*/

int _BTreeConstructor__(BTree* b_tree DEBUG_CODE_ADD(, LOCATION_VAR_CALL_STRUCT__ info_call)) {
    assert(b_tree != nullptr);

    b_tree->head = (Node*)calloc(1, sizeof(Node));
    assert(b_tree->head != nullptr);

    _InizializeNode__(b_tree->head);

    return _ERROR_CODE_SUCCESSFULL__;
}

int _BTreeDestructor__(BTree* b_tree DEBUG_CODE_ADD(, LOCATION_VAR_CALL_STRUCT__ info_call)) {
    if (b_tree->head) {
        _DeleteNode__(b_tree->head DEBUG_CODE_ADD(, info_call));
    }

    return _ERROR_CODE_SUCCESSFULL__;
}

/*----------------------------------------------------------------------------------------------*/

Node* _CreateNode__(DEBUG_CODE_ADD(, LOCATION_VAR_CALL_STRUCT__ info_call)) {
    Node* new_node = nullptr;
    new_node = (Node*)calloc(1, sizeof(Node));
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

    node->left = nullptr;
    node->right = nullptr;

    return _ERROR_CODE_SUCCESSFULL__;
}

/*----------------------------------------------------------------------------------------------*/

const char* LOG_FILENAME_VISUAL = "dump_doubly_link_list_visual.dot";
const char* FILENAME_PNG = "dump_dlink_list_";

const int SIZE_PNG_NAME = 40;
const int SIZE_BUFFER_COMMAND_SYSTEM = 200;

void bst_print_dot_null(char* key, int nullcount, FILE* stream) {
    fprintf(stream, "    null%d [shape=point];\n", nullcount);
    fprintf(stream, "    \"%s\" -> null%d;\n", key, nullcount);
}

void bst_print_dot_aux(Node* node, FILE* stream) {
    static int nullcount = 0;

    if (node->left)
    {
        fprintf(stream, "    \"%s\" -> \"%s\";\n", node->data, node->left->data);
        bst_print_dot_aux(node->left, stream);
    }
    else
        bst_print_dot_null(node->data, nullcount++, stream);

    if (node->right)
    {
        fprintf(stream, "    \"%s\" -> \"%s\";\n", node->data, node->right->data);
        bst_print_dot_aux(node->right, stream);
    }
    else
        bst_print_dot_null(node->data, nullcount++, stream);
}

void bst_print_dot(Node* tree) {
    FILE* graph_file = fopen(LOG_FILENAME_VISUAL, "w");

    fprintf(graph_file, "digraph BST {\n");
    fprintf(graph_file, "    node [fontname=\"Arial\"];\n");

    if (!tree)
        fprintf(graph_file, "\n");
    else if (!tree->right && !tree->left)
        fprintf(graph_file, "    %d;\n", tree->data);
    else
        bst_print_dot_aux(tree, graph_file);

    fprintf(graph_file, "}\n");

    fclose(graph_file);
}
