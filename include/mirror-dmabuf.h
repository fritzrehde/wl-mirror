#ifndef WL_MIRROR_MIRROR_DMABUF_H_
#define WL_MIRROR_MIRROR_DMABUF_H_

#include <stdint.h>
#include "wlr-export-dmabuf-unstable-v1.h"
#include "mirror.h"
#include "egl.h"

typedef enum {
    STATE_WAIT_FRAME,
    STATE_WAIT_OBJECTS,
    STATE_WAIT_READY,
    STATE_READY,
    STATE_CANCELED
} dmabuf_state_t;

typedef struct {
    mirror_backend_t header;

    // dmabuf frame object
    struct zwlr_export_dmabuf_frame_v1 * dmabuf_frame;

    // frame data
    uint32_t x;
    uint32_t y;
    uint32_t buffer_flags;
    uint32_t frame_flags;
    uint64_t dmabuf_modifier;
    dmabuf_t dmabuf;

    // dmabuf state flags
    dmabuf_state_t state;
    uint32_t processed_objects;
} dmabuf_mirror_backend_t;

#endif
