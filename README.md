# Suduko Solver Tool

An Object Oriented implementation of a tool for solving Suduko Puzzles.

The tool makes use of at most two phases for solving a puzzle:

1.) **Candidate Phase:** Iterates through open cells and assigns possible solutions (or candidates), then assigns cells the only solution if they 
 only have one candidate available (in some cases of easy puzzles, this phase will be enough).
 
2.) **Backtracking Phase:** Iterates through all remaining open cells (with candidates $> 1$) and uses recursive backtracking to 
find the solution to the puzzle.
