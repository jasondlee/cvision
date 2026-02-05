//
// Created by Bob on 2/1/26.
//

#ifndef CVISION_COBJECTS_H
#define CVISION_COBJECTS_H

#include "ctypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* TPoint C wrapper types and functions */
/* Note: tv_Point is defined in ctypes.h */

/* TPoint creation and manipulation */
tv_Point tv_point_create(int x, int y);
tv_Point tv_point_add(tv_Point one, tv_Point two);
tv_Point tv_point_subtract(tv_Point one, tv_Point two);
void tv_point_add_assign(tv_Point *point, tv_Point adder);
void tv_point_subtract_assign(tv_Point *point, tv_Point subber);
int tv_point_equals(tv_Point one, tv_Point two);
int tv_point_not_equals(tv_Point one, tv_Point two);

/* TRect C wrapper types and functions */
/* Note: tv_Rect is defined in ctypes.h */

/* TRect creation and manipulation */
tv_Rect tv_rect_create(int ax, int ay, int bx, int by);
tv_Rect tv_rect_create_points(tv_Point p1, tv_Point p2);
tv_Rect tv_rect_create_empty(void);
void tv_rect_move(tv_Rect *rect, int dx, int dy);
void tv_rect_grow(tv_Rect *rect, int dx, int dy);
void tv_rect_intersect(tv_Rect *rect, tv_Rect other);
void tv_rect_union(tv_Rect *rect, tv_Rect other);
int tv_rect_contains(tv_Rect rect, tv_Point point);
int tv_rect_equals(tv_Rect one, tv_Rect two);
int tv_rect_not_equals(tv_Rect one, tv_Rect two);
int tv_rect_is_empty(tv_Rect rect);

/* TCollection and TSortedCollection are abstract classes and cannot be instantiated directly.
 * They are typically used through derived classes in the C++ API.
 * C wrappers for specific derived collection types should be created as needed.
 */

#ifdef __cplusplus
}
#endif

#endif /* CVISION_COBJECTS_H */
