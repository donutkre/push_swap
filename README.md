Pushswap
--------------------------------------
### This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

Commands are compressed by storing the commands as a string in a buffer instead of immediately outputting them to the standard output or by storing them in a linked list, etc. command unit.

- For example, the command ra -> rb / rb -> ra can be compressed to rr.
- Also, the command rra -> rrb / rrb -> rra can be compressed with rrr.
- Commands executed in the order of rr -> rrr / rrr -> rr are unnecessary and can be deleted.
- Also, pa -> pb / pb -> pa / ra -> rra / rb -> rrb / sa -> sa / sb -> sb , but the same pair of commands can be deleted.

![Imgur](https://imgur.com/9Mit3Hy.png)

![Imgur](https://imgur.com/Rn6C729.png)
