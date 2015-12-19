# Google Code Jam 2014

This repository contains my solutions to the problems from [Google Code Jam 2014][1]. These solutions are provided "as is" - I give no guarantees that they will work as expected.

## Instructions

You can compile all the problems by issuing the following command:

    $ make

If you want to compile only a specific problem, issue the following command, replacing `<problem_id>` with the section and identifier of the problem you want to compile (see section "Problems Solved" for the list of possible identifiers):

    $ make <problem_id>

Running a compiled problem is just a matter of executing a command similar to the next one, replacing `<problem_id>` with the identifier of the desired problem:

    $ ./<problem_id>

Unless stated otherwise, every problem in this repository reads from the standard input and writes to the standard output.

## Problems Solved

The following is the list of the problems solved. Each problem identifier is specified between round brackets. Problems marked with ✓ are done, while problems with ✗ are not complete or aren't efficient enough for the problem's limits.

### Qualification Round

* ✓ [A: Magic Trick][qual1] (`magic-trick`)
* ✓ [B: Cookie Clicker Alpha][qual2] (`cookie-clicker-alpha`)
* ✓ [D: Deceitful War][qual4] (`deceitful-war`)

### Round 1A

* ✓ [A: Charging Chaos][round1a1] (`charging-chaos`)
* ✓ [B: Full Binary Tree][round1a2] (`full-binary-tree`)

### Round 1B

* ✗ [A: The Repeater][round1b1] (`the-repeater`)
* ✗ [B: New Lottery Game][round1b2] (`new-lottery-game`)
* ✗ [C: The Bored Traveling Salesman][round1b3] (`the-bored-traveling-salesman`)

### Round 1C

* ✓ [A: Part Elf][round1c1] (`part-elf`)
* ✗ [B: Reordering Train Cars][round1c2] (`reordering-train-cars`)
* ✗ [C: Enclosure][round1c3] (`enclosure`)

### Round 2

* ✓ [A: Data Packing][round21] (`data-packing`)
* ✗ [B: Up and Down][round22] (`up-and-down`)

[1]: https://code.google.com/codejam
[qual1]: https://code.google.com/codejam/contest/2974486/dashboard#s=p0
[qual2]: https://code.google.com/codejam/contest/2974486/dashboard#s=p1
[qual4]: https://code.google.com/codejam/contest/2974486/dashboard#s=p3
[round1a1]: https://code.google.com/codejam/contest/2984486/dashboard#s=p0
[round1a2]: https://code.google.com/codejam/contest/2984486/dashboard#s=p1
[round1b1]: https://code.google.com/codejam/contest/2994486/dashboard#s=p0
[round1b2]: https://code.google.com/codejam/contest/2994486/dashboard#s=p1
[round1b3]: https://code.google.com/codejam/contest/2994486/dashboard#s=p2
[round1c1]: https://code.google.com/codejam/contest/3004486/dashboard#s=p0
[round1c2]: https://code.google.com/codejam/contest/3004486/dashboard#s=p1
[round1c3]: https://code.google.com/codejam/contest/3004486/dashboard#s=p2
[round21]: https://code.google.com/codejam/contest/3014486/dashboard#s=p0
[round22]: https://code.google.com/codejam/contest/3014486/dashboard#s=p1
