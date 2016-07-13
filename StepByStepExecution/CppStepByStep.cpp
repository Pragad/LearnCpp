#include <iostream>
using namespace std;

// STEP 1. PREPROCESSING
//      - Generates .ii files that has all #includes
//      - To understand preprocessing better, you can compile the above ‘print.c’ program
//        using flag -E, which will print the preprocessed output to stdout.
//
//      g++ -Wall -E CppStepByStep.cpp
//
//      - Even better, you can use flag ‘-save-temps’ as shown below.
//      - ‘-save-temps’ flag instructs compiler to store the temporary intermediate files
//        used by the gcc compiler in the current directory.
//      - The preprocessed output is stored in the temporary file that has the extension .i
//
//      g++ -std=c++11 -Wall -save-temps CppStepByStep.cpp -o result
//
//      -rw-rw-rw-  1 pragadhe 0     782 2016-07-10 21:14 CppStepByStep.cpp
//      -rw-rw-rw-  1 pragadhe 0  682833 2016-07-10 21:14 CppStepByStep.ii
//      -rw-rw-rw-  1 pragadhe 0    2535 2016-07-10 21:14 CppStepByStep.o
//      -rw-rw-rw-  1 pragadhe 0    3452 2016-07-10 21:14 CppStepByStep.s
// 
// STEP 2. COMPILING
//      - The next step is to take print.i as input, compile it and produce an intermediate compiled output.
//      - The output file for this stage is ‘print.s’.
//      - The output present in print.s is assembly level instructions.
//
// STEP 3. ASSEMBLER
//      - At this stage the print.s file is taken as an input and an intermediate file print.o is produced.
//      - This file is also known as the object file.
//      - ‘.o’ object file which contains machine level instructions.
//      - At this stage only the existing code is converted into machine language, the function calls like printf() are not resolved.
//      - Since the output of this stage is a machine level file (print.o).
//      - So we cannot view the content of it.
//      - If you still try to open the print.o and view it, you’ll see something that is totally not readable.
//
// STEP 4. LINKING
//      - This is the final stage at which all the linking of function calls with their definitions are done.
//      - As discussed earlier, till this stage gcc doesn’t know about the definition of functions like printf().
//      - Until the compiler knows exactly where all of these functions are implemented, it simply uses a place-holder for the function call.
//      - It is at this stage, the definition of printf() is resolved and the actual address of the function printf() is plugged in.
//      - The linker comes into action at this stage and does this task.

int main()
{
    cout << "Hello World" << endl;

    int a = 5;
    int b = 6;
    int result = a + b;
    cout << "Result: " << result << endl;

    return 0;
}
