
#include <stdio.h>
#include <stdlib.h>

/* 
This program implements the following function recursively
foo(0) = 3
foo(1) = 6
foo(2) = 2
foo(3) = 7
foo(N) = foo(N-1) + foo(N-2) + foo(N-3) - foo(N-4) + 1

And displays the value depending on the n value for input
*/

int _foo(int n, int* numbers) {
/*
This function recursively evaluates the value of foo
@param: n is the number that will be input into the foo() function given by the user
@param: numbers is the array that will store the values that we get from the foo function
@return: the value of n in a function put into the numbers array at the n-th index
*/
    int array[] = {3, 6, 2, 7};
    if (n < 0) {
        return numbers[n] = 0;
    } else if (n <= 3 && n >= 0) { 
        numbers[n] = array[n];
        return numbers[n];
    } else if (numbers[n] != -1) { // if there is already a value for foo(n), simply return it rather than recalculate
        return numbers[n];
    } else {
        return numbers[n] = _foo(n - 1, numbers) + _foo(n - 2, numbers) + _foo(n - 3, numbers) - _foo(n - 4, numbers) + 1;
    }
    // numbers[n] is the value of foo(n) at that n
}

int foo(int n, int* numbers) {
/*
This function calls the recursive function
@param: n is the number that will be input into the foo() function
@param: numbers is the array that will sotre the values that we get from the foo function
@return: the value of in a function put into the numbers array at the n-th index from the recursive foo function
*/
    return _foo(n, numbers);
}

int main() {
/*
This function takes user input, initializes our array, and shows the user the value calculated from foo()
@returns 0 for completion
*/
    int n;
    int* numbers = malloc(1001 * sizeof(int));
    for (int i = 0; i < 1000; i++) {
        numbers[i] = -1;
    }

    printf("Enter a value for n: ");
    scanf("%d", &n);

    printf("Foo(%d) = %d\n", n, foo(n, numbers));

    free(numbers);

    return 0;
}