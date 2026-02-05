//
// Created by Bob on 2/1/26.
//

#include "cvision/ctypes.h"
#include "cvision/cvision.h"
#include "cvision/cobjects.h"
#include <tvision/tv.h>

extern "C" {

/* TPoint functions */

tv_Point tv_point_create(int x, int y) {
    tv_Point point;
    point.x = x;
    point.y = y;
    return point;
}

tv_Point tv_point_add(tv_Point one, tv_Point two) {
    TPoint p1, p2;
    p1.x = one.x;
    p1.y = one.y;
    p2.x = two.x;
    p2.y = two.y;
    
    TPoint result = p1 + p2;
    
    tv_Point ret;
    ret.x = result.x;
    ret.y = result.y;
    return ret;
}

tv_Point tv_point_subtract(tv_Point one, tv_Point two) {
    TPoint p1, p2;
    p1.x = one.x;
    p1.y = one.y;
    p2.x = two.x;
    p2.y = two.y;
    
    TPoint result = p1 - p2;
    
    tv_Point ret;
    ret.x = result.x;
    ret.y = result.y;
    return ret;
}

void tv_point_add_assign(tv_Point *point, tv_Point adder) {
    if (!point) return;
    
    TPoint p1, p2;
    p1.x = point->x;
    p1.y = point->y;
    p2.x = adder.x;
    p2.y = adder.y;
    
    p1 += p2;
    
    point->x = p1.x;
    point->y = p1.y;
}

void tv_point_subtract_assign(tv_Point *point, tv_Point subber) {
    if (!point) return;
    
    TPoint p1, p2;
    p1.x = point->x;
    p1.y = point->y;
    p2.x = subber.x;
    p2.y = subber.y;
    
    p1 -= p2;
    
    point->x = p1.x;
    point->y = p1.y;
}

int tv_point_equals(tv_Point one, tv_Point two) {
    TPoint p1, p2;
    p1.x = one.x;
    p1.y = one.y;
    p2.x = two.x;
    p2.y = two.y;
    
    return (p1 == p2) ? 1 : 0;
}

int tv_point_not_equals(tv_Point one, tv_Point two) {
    TPoint p1, p2;
    p1.x = one.x;
    p1.y = one.y;
    p2.x = two.x;
    p2.y = two.y;
    
    return (p1 != p2) ? 1 : 0;
}

/* TRect functions */

tv_Rect tv_rect_create(int ax, int ay, int bx, int by) {
    TRect rect(ax, ay, bx, by);
    
    tv_Rect ret;
    ret.a.x = rect.a.x;
    ret.a.y = rect.a.y;
    ret.b.x = rect.b.x;
    ret.b.y = rect.b.y;
    return ret;
}

tv_Rect tv_rect_create_points(tv_Point p1, tv_Point p2) {
    TPoint tp1, tp2;
    tp1.x = p1.x;
    tp1.y = p1.y;
    tp2.x = p2.x;
    tp2.y = p2.y;
    
    TRect rect(tp1, tp2);
    
    tv_Rect ret;
    ret.a.x = rect.a.x;
    ret.a.y = rect.a.y;
    ret.b.x = rect.b.x;
    ret.b.y = rect.b.y;
    return ret;
}

tv_Rect tv_rect_create_empty(void) {
    TRect rect;
    
    tv_Rect ret;
    ret.a.x = rect.a.x;
    ret.a.y = rect.a.y;
    ret.b.x = rect.b.x;
    ret.b.y = rect.b.y;
    return ret;
}

void tv_rect_move(tv_Rect *rect, int dx, int dy) {
    if (!rect) return;
    
    TRect tr;
    tr.a.x = rect->a.x;
    tr.a.y = rect->a.y;
    tr.b.x = rect->b.x;
    tr.b.y = rect->b.y;
    
    tr.move(dx, dy);
    
    rect->a.x = tr.a.x;
    rect->a.y = tr.a.y;
    rect->b.x = tr.b.x;
    rect->b.y = tr.b.y;
}

void tv_rect_grow(tv_Rect *rect, int dx, int dy) {
    if (!rect) return;
    
    TRect tr;
    tr.a.x = rect->a.x;
    tr.a.y = rect->a.y;
    tr.b.x = rect->b.x;
    tr.b.y = rect->b.y;
    
    tr.grow(dx, dy);
    
    rect->a.x = tr.a.x;
    rect->a.y = tr.a.y;
    rect->b.x = tr.b.x;
    rect->b.y = tr.b.y;
}

void tv_rect_intersect(tv_Rect *rect, tv_Rect other) {
    if (!rect) return;
    
    TRect tr, tr_other;
    tr.a.x = rect->a.x;
    tr.a.y = rect->a.y;
    tr.b.x = rect->b.x;
    tr.b.y = rect->b.y;
    
    tr_other.a.x = other.a.x;
    tr_other.a.y = other.a.y;
    tr_other.b.x = other.b.x;
    tr_other.b.y = other.b.y;
    
    tr.intersect(tr_other);
    
    rect->a.x = tr.a.x;
    rect->a.y = tr.a.y;
    rect->b.x = tr.b.x;
    rect->b.y = tr.b.y;
}

void tv_rect_union(tv_Rect *rect, tv_Rect other) {
    if (!rect) return;
    
    TRect tr, tr_other;
    tr.a.x = rect->a.x;
    tr.a.y = rect->a.y;
    tr.b.x = rect->b.x;
    tr.b.y = rect->b.y;
    
    tr_other.a.x = other.a.x;
    tr_other.a.y = other.a.y;
    tr_other.b.x = other.b.x;
    tr_other.b.y = other.b.y;
    
    tr.Union(tr_other);
    
    rect->a.x = tr.a.x;
    rect->a.y = tr.a.y;
    rect->b.x = tr.b.x;
    rect->b.y = tr.b.y;
}

int tv_rect_contains(tv_Rect rect, tv_Point point) {
    TRect tr;
    tr.a.x = rect.a.x;
    tr.a.y = rect.a.y;
    tr.b.x = rect.b.x;
    tr.b.y = rect.b.y;
    
    TPoint tp;
    tp.x = point.x;
    tp.y = point.y;
    
    return tr.contains(tp) ? 1 : 0;
}

int tv_rect_equals(tv_Rect one, tv_Rect two) {
    TRect tr1, tr2;
    tr1.a.x = one.a.x;
    tr1.a.y = one.a.y;
    tr1.b.x = one.b.x;
    tr1.b.y = one.b.y;
    
    tr2.a.x = two.a.x;
    tr2.a.y = two.a.y;
    tr2.b.x = two.b.x;
    tr2.b.y = two.b.y;
    
    return (tr1 == tr2) ? 1 : 0;
}

int tv_rect_not_equals(tv_Rect one, tv_Rect two) {
    TRect tr1, tr2;
    tr1.a.x = one.a.x;
    tr1.a.y = one.a.y;
    tr1.b.x = one.b.x;
    tr1.b.y = one.b.y;
    
    tr2.a.x = two.a.x;
    tr2.a.y = two.a.y;
    tr2.b.x = two.b.x;
    tr2.b.y = two.b.y;
    
    return (tr1 != tr2) ? 1 : 0;
}

int tv_rect_is_empty(tv_Rect rect) {
    TRect tr;
    tr.a.x = rect.a.x;
    tr.a.y = rect.a.y;
    tr.b.x = rect.b.x;
    tr.b.y = rect.b.y;
    
    return tr.isEmpty() ? 1 : 0;
}

} // extern "C"
