
# Assignment #2 – Data Structures & Object-Oriented Programming

This document explains the implementation of recursion, linked lists, queues, and stacks using C++. The work demonstrates core OOP concepts including inheritance and polymorphism, alongside fundamental data structure operations such as insertion, deletion, traversal, and reversal.

### Q1 – Recursion

In this question, I wrote two recursive functions:

- The first function changes the positions of characters inside a character array between two given indexes. It uses recursion to swap characters until the middle is reached.

- The second function prints a number pattern using recursion instead of loops.

This question mainly helped me understand how recursive calls work step by step.

### Q2 – Singly Linked List with Inheritance

In this question, I made a base class called Feature, and then two child classes:

- LandFeature

- WaterFeature

Each object prints its own message using the **analyze()** function.
Then I created a singly linked list where each node holds a feature.
I added features, displayed them, deleted a feature, and also reversed the list.

This question showed how polymorphism works with linked lists.

### Q3 – Doubly Linked List

Here, I created a doubly linked list to store books.
Each node contains:

- BookID

- Title

- Author

I implemented:

- Add book at start

- Add book at end

- Add at a specific position

- Delete by ID

- Display in forward and backward direction

This helped me understand how **prev** and **next** pointers work together.

### Q4 – Queue (Ticket Booking System)

This question was about a normal queue where customers wait to buy tickets.
I used a linked list to build the queue.
The first customer in the queue gets served first (FIFO).
I added customers, removed customers, and displayed the queue.

This question showed how real-life queues can be represented in programming.

### Q5 – Stacks + Analysis

I implemented stacks in two different ways:

**1.** Using a linked list

**2.** Using a dynamic array

Then I used these stacks to solve the earlier recursion question without recursion.
This showed that recursion and stacks are related.

### Short Comparison:

- Linked list stack can grow anytime but uses more memory.

- Array stack is faster in access but has a fixed size limit.

### Overall:

This assignment helped me practice:

- Linked Lists

- Doubly Linked Lists

- Queues

- Stacks

- Recursion vs Iteration

- Polymorphism and dynamic binding

I tried to write the code in a clean and simple way so that it is easy to understand.

