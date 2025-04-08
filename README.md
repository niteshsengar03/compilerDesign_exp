# Compiler Design Experiments

This repository contains various programs related to compiler design concepts. Below is a brief description of each file:

## `firstFollow.cpp`
This program computes the **FIRST** and **FOLLOW** sets for a given grammar. It uses hardcoded grammar rules and outputs the computed sets for each non-terminal.

## `generation3AC.cpp`
This program generates **Three Address Code (TAC)** for a given arithmetic expression. It uses stacks to handle operator precedence and outputs the TAC in a structured format.

## `leaderIn3AC.c`
This program identifies **leader instructions** in a given set of Three Address Code (TAC) instructions. It uses rules such as the first instruction being a leader and jump targets being leaders.

## `lefFactoring.cpp`
This program performs **Left Factoring** on a given grammar production. It identifies common prefixes in the production rules and rewrites the grammar to eliminate ambiguity.

## `leftRecursion.cpp`
This program eliminates **Left Recursion** from a given grammar production. It separates left-recursive and non-left-recursive parts and rewrites the grammar accordingly.

## `lexical.cpp`
This program performs **Lexical Analysis** on an input string. It identifies tokens such as keywords, identifiers, operators, delimiters, and numbers, and classifies them accordingly.

## `shiftReduce.cpp`
This program implements a **Shift-Reduce Parser**. It processes an input string using a stack and a set of grammar rules to determine if the string can be reduced to the start symbol.



---
Each program demonstrates a specific concept in compiler design, making this repository a valuable resource for understanding the fundamentals of compiler construction.