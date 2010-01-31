#ifndef ISL_FLOW_H
#define ISL_FLOW_H

#include <isl_set.h>
#include <isl_map.h>

#if defined(__cplusplus)
extern "C" {
#endif

/* Let n (>= 0) be the number of iterators shared by first and second.
 * If first precedes second textually return 2 * n + 1,
 * otherwise return 2 * n.
 */
typedef int (*isl_access_level_before)(void *first, void *second);

struct isl_access_info;
typedef struct isl_access_info isl_access_info;
struct isl_flow;
typedef struct isl_flow isl_flow;

__isl_give isl_access_info *isl_access_info_alloc(__isl_take isl_map *sink,
	void *sink_user, isl_access_level_before fn, int max_source);
__isl_give isl_access_info *isl_access_info_add_source(
	__isl_take isl_access_info *acc, __isl_take isl_map *source,
	void *source_user);
__isl_give isl_flow *isl_access_info_compute_flow(__isl_take isl_access_info *acc);
int isl_flow_foreach(__isl_keep isl_flow *deps,
	int (*fn)(__isl_take isl_map *dep, void *dep_user, void *user),
	void *user);
__isl_give isl_set *isl_flow_get_no_source(__isl_keep isl_flow *deps);
void isl_flow_free(__isl_take isl_flow *deps);

#if defined(__cplusplus)
}
#endif

#endif
