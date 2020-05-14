#include <opencv2/core.hpp>
#include <cstdlib>
#include <cstdio>
#include <cstring>

extern "C" {

struct PM_shape_t {
    int width, height, channels;
};

enum PM_dtype_e {
    PM_UINT8,
    PM_INT8,
    PM_UINT16,
    PM_INT16,
    PM_INT32,
    PM_FLOAT32,
    PM_FLOAT64,
};

struct PM_mat_t {
    void *data_ptr;
    PM_shape_t shape;
    int dtype;
};

void PM_free_pymat(PM_mat_t pymat);
PM_mat_t PM_inpaint(PM_mat_t image, PM_mat_t mask, int patch_size);
PM_mat_t PM_inpaint_regularity(PM_mat_t image, PM_mat_t mask, PM_mat_t ijmap, int patch_size, double guide_weight);

} /*  extern "C" */

