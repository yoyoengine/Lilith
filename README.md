# Lilith Linear Algebra

A super simple linear algebra library created for use with [yoyoengine](https://github.com/yoyoengine).

No gaurantees are made for correctness or optimization, I rolled this myself for fun and to learn.

![Evangelion Reference](https://static.wikia.nocookie.net/evangelion/images/9/99/Lilith_with_Lance.png/revision/latest/thumbnail/width/360/height/360?cb=20120210032404)

## Features

- 3x3 matrix operations
- 2D vector operations

## Example

```c
#include <Lilith.h>

int main() {
    mat3_t identity = lla_mat3_identity();
    mat3_t scale = lla_mat3_scale(identity, 2.0f);

    mat3_t test = lla_mat3(10.0f, 80.0f, 4.0f, 5.0f, 78.0f, 9.0f, 47.0f, 9.0f, 5.0f);

    mat3_t result = lla_mat3_mult(scale, test);

    const char* res_str = lla_mat3_string(result);
    printf("%s\n", res_str);
    free((void*)res_str);

    /*
        Output:
        [20.000000, 160.000000, 8.000000]
        [10.000000, 156.000000, 18.000000]
        [94.000000, 18.000000, 10.000000]
    */

}
```

## Todo

- vec3 and appropriate mult funcs?
- row/col extraction?
- unit tests?
