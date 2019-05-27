# NVector

### Methods

__Max size__

![max_size](https://puu.sh/DxSQL/7b2b3a5806.png)

Returns max `size_t` available on current machine using 
`std::numeric_limits`.

__Resize__

![resize](https://puu.sh/DxSTE/046f4753da.png)

Checks if argument is not negative. If so, throws an exception. If 
`new_size` is smaller, than current vector size, then it shrinks it
down to the `new_size`. If `new_size` is bigger than current vector
capacity it will extend it to given number.

__Pop_back__

![pop_back](https://puu.sh/DxSXd/38751939e8.png)

If vector is not negative and not equal to 0 `pop_back` virtually
removes last element of the vector.

__Push_back__

![push_back](https://puu.sh/DxSZh/037b280b2b.png)

Firstly `push_back` checks if it can push one more element in to the
vector by considering it's capacity. If it is too low, it will increase
it. Then it add the element to the vector and increase it's size by 1.

__Shrink_to_fit__

![shrink_to_fit](https://puu.sh/DxTc3/e569c339ed.png)

It shrinks the capacity of the vector to the vector's size.


### Benchmarks
| | std::vector push_back time (s) | NVector push_back time (s) |
| :---: | :---: | :---: |
| 10 000 | 0.00218237 | 0.000292298 |
| 100 000 | 0.0223974 | 0.00182957 |
| 1 000 000 | 0.304972 | 0.0153772 |
| 10 000 000 | 2.82404 | 0.296433 |

| | std::vector capacity extends | NVector capacity extends |
| :---: | :---: | :---: |
| 10 000 000 | 41 | 25 |
