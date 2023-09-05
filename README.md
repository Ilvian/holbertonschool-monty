* C - Stacks, Queues - LIFO, FIFO
Project to be done in teams of 2 people

* Objectives

1. What do LIFO and FIFO mean
LIFO (Last-In, First-Out):
LIFO is a data management principle where the most recently added item is the first one to be removed.
It's commonly associated with data structures like stacks.
In LIFO, the last element added is the first to be accessed or processed.
FIFO (First-In, First-Out):
FIFO is a data management principle where the item that has been present the longest is the first one to be removed.
It's commonly associated with data structures like queues.
In FIFO, the first element added is the first to be accessed or processed.
These principles determine the order in which elements are accessed, processed, or removed from a data structure,
depending on whether you're using LIFO or FIFO.

2. What is a stack, and when to use it
A stack is a linear data structure that follows the LIFO (Last-In, First-Out) principle.
It's used to store and manage a collection of elements, with elements added and removed from the top. 
Stacks are valuable for managing function calls, tracking the order of operations, and handling recursive algorithms,
where the last item added is the first one to be removed.

3. What is a queue, and when to use it
A queue is a linear data structure that follows the FIFO (First-In, First-Out) principle. It's used to store and
manage a collection of elements, with elements added at the rear and removed from the front. Queues are helpful for 
managing tasks or data in a sequential order, ensuring that the earliest item added is the first to be processed.

4. What are the common implementations of stacks and queues
Array-based Stack: Uses an array with a "top" index to push and pop elements. Good for a fixed-size stack.
Linked List-based Stack: Utilizes a linked list where elements are pushed and popped from the head.
More flexible for dynamic resizing.
Array-based Queue: Stores elements in an array with "front" and "rear" indices for enqueue and dequeue operations.
Resizing can be an issue.
Linked List-based Queue: Uses a linked list with pointers to the front and rear nodes for enqueue and dequeue.
Flexible for dynamic resizing.
Circular Queue (Array-based): A variant of the array-based queue where rear and front indices wrap around the array.
Useful for scenarios with fixed or logically wrapping sizes.

5. What are the most common use cases of stacks and queues
Stacks:
Function Calls: Managing function calls and their context.
Expression Evaluation: Handling arithmetic expressions.
Undo/Redo: Implementing undo and redo functionality.
Backtracking: Solving problems with backtracking algorithms.
Memory Management: Allocating and deallocating memory.
Parsing: Checking and enforcing code syntax.
Resource Management: Managing limited resources.
Queues
BFS: Exploring graphs level by level.
Task Scheduling: Fair execution of tasks.
Print Queues: Processing print jobs in order.
Bounded Buffers: Coordinating producer-consumer scenarios.
Request Handling: Processing incoming requests fairly.
Parallel Computing: Managing asynchronous tasks.
Print Spooling: Queuing print jobs for printing.
Task Management: Managing processes in operating systems.
These data structures are essential tools in various programming scenarios, simplifying the management of data and tasksin specific orders.

6. What is the proper way to use global variables
Minimize Use: Avoid global variables when possible.
Use Constants: For global constants, use const.
Avoid Mutable Globals: If a global variable is mutable, use it sparingly.
Document Clearly: Clearly document the purpose and usage of global variables.
Limit Scope: Declare them at the top of files and minimize their scope.
Thread Safety: Be cautious with global variables in multi-threaded programs.
Initialization Order: Be aware of initialization order, especially for interdependent globals.
Consider Alternatives: Explore alternatives like singletons or dependency injection.
Testing and Debugging: Be extra careful when testing and debugging code with global variables.

* Header file (monty.h)
This header file defines structures and function prototypes for working with a stack-like data structure and associated instructions.
1. Struct stack_s: This structure represents a doubly linked list node used for implementing a stack or queue.
It contains:
An integer n to store the value of the node.
Pointers prev and next to the previous and next elements in the stack/queue.
2. Struct instruction_s: This structure associates an opcode (a string) with a corresponding function that performs an operation on the stack. It contains:
A string opcode representing the operation's name.
A function pointer f that points to the function responsible for executing the operation.
3. Function Prototypes: Several function prototypes are declared for functions that perform operations on the
stack or queue. These include functions like push, pall (print all), pint (print top), pop, swap, add, and nop.

These data structures and function prototypes are likely part of a larger program designed to process Monty script
files, which contain a series of instructions for manipulating a stack-like data structure.
This header file is used to declare the data structures and functions, making them accessible to other parts of the
program that need to use them.
