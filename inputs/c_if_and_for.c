void foo(int* a, int *b) {
  if (a[0] > 1) {
    b[0] = 2;
  }
}

void bar(float x, float y); // just a declaration

void bang(int* a, int v) {
    for (int i = 0; i < v; ++i) {
        a[i] -= i;
    }
}

/*
clang-query inputs/c_if_and_for.c

 */

/*
$ ./build/rewritersample inputs/cfunc_with_if.c
// Begin function foo returning void
void foo(int* a, int *b) {
  if (a[0] > 1) // the 'if' part
  {
    b[0] = 2;
  }
}
// End function foo

void bar(float x, float y); // just a declaration

 */


//./build/matchers_rewriter inputs/cfunc_with_if.c
//void foo(int* a, int *b) {
//  if (a[0] > 1) // the 'if' part
//  {
//    b[0] = 2;
//  }
//}
//
//void bar(float x, float y); // just a declaration
//
//void bang(int* a, int v) {
//    for (/* increment */int i = 0; i < v; ++i) {
//        a[i] -= i;
//    }
//}

