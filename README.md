
<h3 align="center">SHORT DESCRIPTION</h3>

The program is able to solve a quadratic equation and perform automotic code testing.

<h3 align="center">INSTALATION</h3>

To download this git, you need to use this comant

git clone https://github.com/krampu1/square.git

<h3 align="center">HUW TO USE</h3>

To use the program, you need to run the ```run``` file.

To run unit tests, use the compilation flag ```-d``` .

<h3 align="center">EXAMPLE</h3>

```
./run.exe 
this program solve quadratic equation. Press f to exit program
enter a, b, c:
3 7 -6
x1 = -3 x2 = 0.666667
enter a, b, c:
idh ih dffsdh j
error in input data, enter 3 numbers:
9 -6 1
x1 = 0.333333
enter a, b, c:
f
```
```
./run.exe -d
test number 1   accept || a = 0 b = 0 c = 0 || true answer: count_roots = infinit  || program answer: count_roots = infinit 
test number 2   accept || a = 0 b = 1 c = 0 || true answer: count_roots = 1 x1 = 0 x2 = 0 || program answer: count_roots = 1 x1 = 0 x2 = 0
test number 3   accept || a = 3 b = 7 c = -6 || true answer: count_roots = 2 x1 = -3 x2 = 0.666667 || program answer: count_roots = 2 x1 = -3 x2 = 0.666667
test number 4   accept || a = -1 b = 7 c = 8 || true answer: count_roots = 2 x1 = -1 x2 = 8 || program answer: count_roots = 2 x1 = -1 x2 = 8
test number 5   accept || a = 4 b = 4 c = 1 || true answer: count_roots = 1 x1 = -0.5 x2 = 0 || program answer: count_roots = 1 x1 = -0.5 x2 = 0
test number 6   accept || a = 2 b = 1 c = 1 || true answer: count_roots = 0 x1 = 0 x2 = 0 || program answer: count_roots = 0 x1 = 0 x2 = 0
test number 7   accept || a = -1 b = 2 c = 8 || true answer: count_roots = 2 x1 = -2 x2 = 4 || program answer: count_roots = 2 x1 = -2 x2 = 4
test number 8   accept || a = 9 b = -6 c = 1 || true answer: count_roots = 1 x1 = 0.333333 x2 = 0 || program answer: count_roots = 1 x1 = 0.333333 x2 = 0
test number 9   accept || a = 1 b = 3 c = 2 || true answer: count_roots = 2 x1 = -2 x2 = -1 || program answer: count_roots = 2 x1 = -2 x2 = -1
test number 10  accept || a = 1 b = -5 c = 6 || true answer: count_roots = 2 x1 = 2 x2 = 3 || program answer: count_roots = 2 x1 = 2 x2 = 3
all test accepted
```
<h4 align="center">TO BUILD </h4>

To compile, you need to use the ```make``` function.

To delete the generated object files during compilation, use ```make clean``` .