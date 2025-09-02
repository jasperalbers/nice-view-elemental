#include "../../include/utils/draw_art.h"
#include "../../include/images/art.h"

#include <lvgl.h>

// Array of image descriptors
static const lv_img_dsc_t* artworks[] = {
    &hammerbeam2, &hammerbeam3, &hammerbeam4, &hammerbeam5,
    &hammerbeam6, &hammerbeam7, &hammerbeam8, &hammerbeam9, &hammerbeam10,
    &hammerbeam11, &hammerbeam12, &hammerbeam13, &hammerbeam14, &hammerbeam15,
    &hammerbeam16, &hammerbeam17, &hammerbeam19,
    &hammerbeam21, &hammerbeam23, &hammerbeam24, &hammerbeam25,
    &hammerbeam26, &hammerbeam27, &hammerbeam28, &hammerbeam29,
};

#define ARTWORK_COUNT (sizeof(artworks) / sizeof(artworks[0]))

void draw_art(lv_obj_t* canvas, unsigned index) {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);

    const lv_img_dsc_t* img = artworks[index % ARTWORK_COUNT];
    lv_canvas_draw_img(canvas, 0, 0, img, &img_dsc);
}