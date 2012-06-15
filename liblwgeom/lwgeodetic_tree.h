
#ifndef _LWGEODETIC_TREE_H
#define _LWGEODETIC_TREE_H 1

#include "lwgeodetic.h"

/**
* Note that p1 and p2 are pointers into an independent POINTARRAY, do not free them.
*/
typedef struct circ_node
{
	GEOGRAPHIC_POINT center;
	double radius;
	int num_nodes;
	struct circ_node** nodes;
	int edge_num;
	POINT2D* p1;
	POINT2D* p2;
} CIRC_NODE;

void circ_tree_print(const CIRC_NODE* node, int depth);
CIRC_NODE* circ_tree_new(const POINTARRAY* pa);
void circ_tree_free(CIRC_NODE* node);
int circ_tree_contains_point(const CIRC_NODE* node, const POINT2D* pt, const POINT2D* pt_outside, int* on_boundary);
double circ_tree_distance_tree(const CIRC_NODE* n1, const CIRC_NODE* n2, double threshold, double* min_dist, double* max_dist);
CIRC_NODE* lwgeom_calculate_circ_tree(const LWGEOM* lwgeom);

#endif /* _LWGEODETIC_TREE_H */